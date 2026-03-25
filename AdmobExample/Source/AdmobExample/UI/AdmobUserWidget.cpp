#include "AdmobUserWidget.h"
#include "Engine/World.h"
#include "FlutterUMGWidgets.h"
#include "GoogleMobileAdsBPLibrary.h"
#include "TimerManager.h"
#include "AdmobExampleGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "ProfileSaveGame.h"

using namespace Flutter;

TSharedRef<SWidget> UAdmobUserWidget::RebuildWidget() {
  FFlutterBuildContext Context(this);

  if (!FlutterTheme::MaterialIconsFont) {
      FlutterTheme::MaterialIconsFont = LoadObject<UFont>(nullptr, TEXT("/Game/Fonts/MaterialIcons-Regular_Font.MaterialIcons-Regular_Font"));
      if (FlutterTheme::MaterialIconsFont) {
          UE_LOG(LogTemp, Log, TEXT("AdmobUserWidget: Material Icons Font loaded successfully."));
      } else {
          UE_LOG(LogTemp, Error, TEXT("AdmobUserWidget: FAILED to load Material Icons Font from /Game/Fonts/MaterialIcons-Regular_Font"));
      }
  }

  BottomNavigationBar InitialNav;
  BottomNavBar = InitialNav.Widget;

  auto Stack = IndexedStack().Index(CurrentTabIndex)(
      BuildAdsPage(),
      BuildListPage(),
      BuildProfilePage(),
      BuildRankingPage(),
      BuildAboutPage()
  );
  BodySwitcher = Stack.Widget;

  Column BottomArea;
  BottomArea(InitialNav);
  BottomArea(Container().Color(FLinearColor(0.81f, 0.81f, 0.81f, 1.0f)).Child(BannerPlaceholder = Text(TEXT("Banner Ad")).Widget));

  Root = Cast<UCanvasPanel>(
      Scaffold()
          .AppBar(AppBar().Title(Text(TEXT("Flutter UI Ecosystem")).FontSize(20)))
          .Body(BodySwitcher)
          .BottomNavigationBar(BottomArea.Widget)
          .Build());

  SwitchTab(0);

  return Root->TakeWidget();
}

void UAdmobUserWidget::SwitchTab(int32 Index) {
    CurrentTabIndex = Index;
    if (BodySwitcher) {
        BodySwitcher->SetActiveWidgetIndex(CurrentTabIndex);
    }
    if (BottomNavBar) {
        BottomNavigationBar NavView(BottomNavBar);
        NavView.Items({
            BottomNavigationBarItem(Icons::Tv, TEXT("Ads")),
            BottomNavigationBarItem(Icons::List, TEXT("List")),
            BottomNavigationBarItem(Icons::Person, TEXT("Profile")),
            BottomNavigationBarItem(Icons::Settings, TEXT("Ranking")),
            BottomNavigationBarItem(Icons::Info, TEXT("About"))
        }, this, {TEXT("OnTab0Clicked"), TEXT("OnTab1Clicked"), TEXT("OnTab2Clicked"), TEXT("OnTab3Clicked"), TEXT("OnTab4Clicked")}, CurrentTabIndex);
    }
}

void UAdmobUserWidget::OnTab0Clicked() { SwitchTab(0); }
void UAdmobUserWidget::OnTab1Clicked() { SwitchTab(1); }
void UAdmobUserWidget::OnTab2Clicked() { SwitchTab(2); }
void UAdmobUserWidget::OnTab3Clicked() { SwitchTab(3); }
void UAdmobUserWidget::OnTab4Clicked() { SwitchTab(4); }

UWidget* UAdmobUserWidget::BuildAdsPage() {
    return Flutter::Padding(FMargin(16.0f)).Child(Column()(
              Center()(Column().MainAxisAlignment(0)(
                  ElevatedButton()
                      .OnPressed(this, TEXT("OnShowInterstitialClicked"))
                      .Child(Text(TEXT("Show Interstitial"))),
                  SizedBox(1.0f, 20.0f),
                  ElevatedButton()
                      .OnPressed(this, TEXT("OnShowRewardedClicked"))
                      .Child(Text(TEXT("Show Rewarded"))),
                  SizedBox(1.0f, 20.0f),
                  ElevatedButton()
                      .OnPressed(this, TEXT("OnShowBannerClicked"))
                      .Child(Text(TEXT("Show Banner"))),
                  SizedBox(1.0f, 10.0f),
                  ElevatedButton()
                      .OnPressed(this, TEXT("OnHideBannerClicked"))
                      .Child(Text(TEXT("Hide Banner"))),
                  SizedBox(1.0f, 10.0f),
                  ElevatedButton()
                      .OnPressed(this, TEXT("OnCheckInitClicked"))
                      .Child(Text(TEXT("Check Initialization")))
              ))
          ));
}

UWidget* UAdmobUserWidget::BuildListPage() {
    return Column()(
        Center()(Text(TEXT("ListView.builder Example")).FontSize(18).Color(FLinearColor(0.13f, 0.13f, 0.13f, 1.0f))),
        SizedBox(1.0f, 10.0f),
        Expanded().Child(
            ListView::builder(20, [this](int32 Index) -> UWidget* {
                return Flutter::Padding(FMargin(8.f, 4.f, 8.f, 4.f)).Child(
                    InkWell().OnTap(this, TEXT("OnListItemClicked"), Index).Child(
                        Card().SetElevation(4.0f).SetBorderRadius(8.0f).Child(
                            ListTile()
                                .Leading(Container().Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f)).Padding(FMargin(8.f)).Child(Text(TEXT("#")).Color(FLinearColor::White).FontSize(16)))
                                .Title(Text(FString::Printf(TEXT("Item %d"), Index)).FontSize(16))
                                .Subtitle(Text(TEXT("Click to see index.")).FontSize(12).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)))
                                .Trailing(Text(TEXT("Click Me")).FontSize(14).Color(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f)))
                        )
                    )
                );
            })
        )
    );
}

UWidget* UAdmobUserWidget::BuildProfilePage() {
    auto Stack = IndexedStack().Index(0)(
        BuildProfileViewPage(),
        BuildProfileEditPage()
    );
    ProfileSwitcher = Cast<UWidgetSwitcher>(Stack.Widget);
    return ProfileSwitcher;
}

UWidget* UAdmobUserWidget::BuildProfileViewPage() {
    Flutter::Text NameTextWidget = Flutter::Text(CurrentName).FontSize(18);
    ProfileNameText = NameTextWidget.Widget;

    Flutter::Text EmailTextWidget = Flutter::Text(CurrentEmail).FontSize(18);
    ProfileEmailText = EmailTextWidget.Widget;

    Flutter::Text BioTextWidget = Flutter::Text(CurrentBio).FontSize(16);
    ProfileBioText = BioTextWidget.Widget;

    return Flutter::Padding(FMargin(16.0f)).Child(
        Flutter::Column().MainAxisAlignment(0)(
            Flutter::Center()(Flutter::Text(TEXT("User Profile")).FontSize(24)),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::Card().SetElevation(4.0f).SetBorderRadius(8.0f).Child(
                Flutter::Padding(FMargin(16.0f)).Child(
                    Flutter::Column().MainAxisAlignment(0)(
                        Flutter::Text(TEXT("Name:")).FontSize(14).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)),
                        Flutter::SizedBox(1.0f, 4.0f),
                        NameTextWidget,
                        Flutter::SizedBox(1.0f, 16.0f),
                        Flutter::Text(TEXT("Email:")).FontSize(14).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)),
                        Flutter::SizedBox(1.0f, 4.0f),
                        EmailTextWidget,
                        Flutter::SizedBox(1.0f, 16.0f),
                        Flutter::Text(TEXT("Bio:")).FontSize(14).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)),
                        Flutter::SizedBox(1.0f, 4.0f),
                        BioTextWidget
                    )
                )
            ),
            Flutter::SizedBox(1.0f, 30.0f),
            Flutter::Center()(
                Flutter::ElevatedButton()
                    .OnPressed(this, TEXT("OnEditProfileClicked"))
                    .Child(Flutter::Padding(FMargin(16.0f, 8.0f)).Child(Flutter::Text(TEXT("Edit Profile")).FontSize(16).Color(FLinearColor::White)))
            )
        )
    );
}

UWidget* UAdmobUserWidget::BuildProfileEditPage() {
    return Flutter::Padding(FMargin(16.0f)).Child(
        Flutter::Column().MainAxisAlignment(0)(
            Flutter::Center()(Flutter::Text(TEXT("Edit Profile")).FontSize(24)),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::TextField().Text(CurrentName).HintText(TEXT("Name")).OnChanged(this, TEXT("OnNameChanged")),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::TextField().Text(CurrentEmail).HintText(TEXT("Email")).OnChanged(this, TEXT("OnEmailChanged")),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::TextField().Text(CurrentBio).HintText(TEXT("Bio")).OnChanged(this, TEXT("OnBioChanged")),
            Flutter::SizedBox(1.0f, 30.0f),
            Flutter::Center()(
                Flutter::ElevatedButton()
                    .OnPressed(this, TEXT("OnSaveProfileClicked"))
                    .Child(Flutter::Padding(FMargin(16.0f, 8.0f)).Child(Flutter::Text(TEXT("Save Profile")).FontSize(16).Color(FLinearColor::White)))
            )
        )
    );
}

void UAdmobUserWidget::LoadProfile() {
    if (UGameplayStatics::DoesSaveGameExist(TEXT("ProfileSlot"), 0)) {
        if (UProfileSaveGame* LoadedGame = Cast<UProfileSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("ProfileSlot"), 0))) {
            CurrentName = LoadedGame->UserName;
            CurrentEmail = LoadedGame->UserEmail;
            CurrentBio = LoadedGame->UserBio;
            UE_LOG(LogTemp, Log, TEXT("Profile Loaded: %s"), *CurrentName);
            return;
        }
    }
    
    CurrentName = TEXT("Guest User");
    CurrentEmail = TEXT("guest@example.com");
    CurrentBio = TEXT("Hello! I am using the FlutterUMG plugin in Unreal Engine.");
}

void UAdmobUserWidget::OnEditProfileClicked() {
    if (ProfileSwitcher) {
        ProfileSwitcher->SetActiveWidgetIndex(1); // Switch to Edit Page
    }
}

void UAdmobUserWidget::OnSaveProfileClicked() {
    if (UProfileSaveGame* SaveGameInstance = Cast<UProfileSaveGame>(UGameplayStatics::CreateSaveGameObject(UProfileSaveGame::StaticClass()))) {
        SaveGameInstance->UserName = CurrentName;
        SaveGameInstance->UserEmail = CurrentEmail;
        SaveGameInstance->UserBio = CurrentBio;
        UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("ProfileSlot"), 0);
        
        // Update display view
        if (ProfileNameText) ProfileNameText->SetText(FText::FromString(CurrentName));
        if (ProfileEmailText) ProfileEmailText->SetText(FText::FromString(CurrentEmail));
        if (ProfileBioText) ProfileBioText->SetText(FText::FromString(CurrentBio));

        if (ProfileSwitcher) {
            ProfileSwitcher->SetActiveWidgetIndex(0); // Switch to View Page
        }
        
        Fluttertoast::showToast(this, Root, TEXT("Profile Saved!"));
    }
}

void UAdmobUserWidget::OnNameChanged(const FText& Text) {
    CurrentName = Text.ToString();
}

void UAdmobUserWidget::OnEmailChanged(const FText& Text) {
    CurrentEmail = Text.ToString();
}

void UAdmobUserWidget::OnBioChanged(const FText& Text) {
    CurrentBio = Text.ToString();
}

void UAdmobUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
    Super::NativeTick(MyGeometry, InDeltaTime);

    if (RankingSizeBox && !FMath::IsNearlyEqual(CurrentRankingHeight, TargetRankingHeight, 0.5f)) {
        CurrentRankingHeight = FMath::FInterpTo(CurrentRankingHeight, TargetRankingHeight, InDeltaTime, 10.0f);
        RankingSizeBox->SetHeightOverride(CurrentRankingHeight);
    }

    for (int32 i = RankingItems.Num() - 1; i >= 0; --i) {
        FRankingItem& Item = RankingItems[i];
        
        Item.CurrentY = FMath::FInterpTo(Item.CurrentY, Item.TargetY, InDeltaTime, 10.0f);
        Item.Opacity = FMath::FInterpTo(Item.Opacity, Item.TargetOpacity, InDeltaTime, 12.0f);

        if (Item.Widget) {
            if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Item.Widget->Slot)) {
                FMargin Offs = CanvasSlot->GetOffsets();
                CanvasSlot->SetOffsets(FMargin(Offs.Left, Item.CurrentY, Offs.Right, Offs.Bottom));
            }
            Item.Widget->SetRenderOpacity(Item.Opacity);
        }

        if (Item.bIsRemoving && Item.Opacity < 0.05f) {
            if (Item.Widget) {
                Item.Widget->RemoveFromParent();
            }
            RankingItems.RemoveAt(i);
        }
    }
}

UWidget* UAdmobUserWidget::BuildRankingPage() {
    Flutter::Stack RankingStack;
    RankingCanvas = RankingStack.Widget;

    Flutter::SizeBox HostBox;
    RankingSizeBox = HostBox.Widget;
    TargetRankingHeight = 20.0f;
    CurrentRankingHeight = 20.0f;
    RankingSizeBox->SetHeightOverride(CurrentRankingHeight);
    RankingSizeBox->AddChild(RankingCanvas);

    Flutter::ListView Scroller;
    Scroller.Widget->AddChild(RankingSizeBox);

    return Flutter::Column().MainAxisAlignment(0)(
        Flutter::Padding(FMargin(16.f)).Child(
            Flutter::Row().MainAxisAlignment(0)(
                Flutter::Expanded().Child(Flutter::ElevatedButton().OnPressed(this, TEXT("OnRankingAddClicked")).Child(Flutter::Text(TEXT("Add")).FontSize(14).Color(FLinearColor::White))),
                Flutter::SizedBox(10.f, 1.f),
                Flutter::Expanded().Child(Flutter::ElevatedButton().OnPressed(this, TEXT("OnRankingShuffleClicked")).Child(Flutter::Text(TEXT("Rescore")).FontSize(14).Color(FLinearColor::White))),
                Flutter::SizedBox(10.f, 1.f),
                Flutter::Expanded().Child(Flutter::ElevatedButton().OnPressed(this, TEXT("OnRankingRemoveClicked")).Child(Flutter::Text(TEXT("Remove")).FontSize(14).Color(FLinearColor::White)))
            )
        ),
        Flutter::Expanded().Child(
            Flutter::Padding(FMargin(16.f, 0.f, 16.f, 16.f)).Child(
                Scroller
            )
        )
    );
}

void UAdmobUserWidget::OnRankingAddClicked() {
    if (!RankingCanvas) return;

    FRankingItem NewItem;
    NewItem.Id = NextRankingId++;
    NewItem.Name = FString::Printf(TEXT("Player %d"), NewItem.Id);
    NewItem.Score = FMath::RandRange(10, 1000);
    NewItem.CurrentY = RankingItems.Num() * 80.0f + 600.0f; // Start further down
    NewItem.Opacity = 0.0f;
    NewItem.TargetOpacity = 1.0f;

    UWidget* CardWidget = Flutter::Card().SetElevation(2.f).SetBorderRadius(8.f).Child(
        Flutter::ListTile()
            .Leading(Flutter::Text(FString::Printf(TEXT("#%d"), NewItem.Id)).FontSize(18).Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.f)))
            .Title(Flutter::Text(NewItem.Name).FontSize(16))
            .Trailing(Flutter::Text(FString::Printf(TEXT("%d pt"), NewItem.Score)).FontSize(16).Color(FLinearColor::Red))
    );
    
    NewItem.Widget = CardWidget;

    UCanvasPanelSlot* Slot = RankingCanvas->AddChildToCanvas(NewItem.Widget);
    if (Slot) {
        Slot->SetAutoSize(false);
        Slot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 0.0f)); // Stretch horizontally
        Slot->SetOffsets(FMargin(0.0f, NewItem.CurrentY, 0.0f, 70.0f)); // Left=0, Top=CurrentY, Right=0, Height=70
    }
    NewItem.Widget->SetRenderOpacity(0.0f);

    RankingItems.Add(NewItem);

    RankingItems.Sort([](const FRankingItem& A, const FRankingItem& B) {
        return A.Score > B.Score;
    });

    float YOffset = 0.0f;
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.TargetY = YOffset;
            YOffset += 80.0f;
        }
    }
    TargetRankingHeight = YOffset + 20.0f;
}

void UAdmobUserWidget::OnRankingRemoveClicked() {
    for (int32 i = RankingItems.Num() - 1; i >= 0; --i) {
        if (!RankingItems[i].bIsRemoving) {
            RankingItems[i].bIsRemoving = true;
            RankingItems[i].TargetOpacity = 0.0f;
            break;
        }
    }

    float YOffset = 0.0f;
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.TargetY = YOffset;
            YOffset += 80.0f;
        }
    }
    TargetRankingHeight = YOffset + 20.0f;
}

void UAdmobUserWidget::OnRankingShuffleClicked() {
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.Score = FMath::RandRange(10, 1000);
            
            if (Item.Widget) {
                Item.Widget->RemoveFromParent();
            }

            UWidget* CardWidget = Flutter::Card().SetElevation(2.f).SetBorderRadius(8.f).Child(
                Flutter::ListTile()
                    .Leading(Flutter::Text(FString::Printf(TEXT("#%d"), Item.Id)).FontSize(18).Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.f)))
                    .Title(Flutter::Text(Item.Name).FontSize(16))
                    .Trailing(Flutter::Text(FString::Printf(TEXT("%d pt"), Item.Score)).FontSize(16).Color(FLinearColor::Red))
            );
            
            Item.Widget = CardWidget;
            
            if (RankingCanvas) {
                UCanvasPanelSlot* Slot = RankingCanvas->AddChildToCanvas(Item.Widget);
                if (Slot) {
                    Slot->SetAutoSize(false);
                    Slot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 0.0f)); // Stretch horizontally
                    Slot->SetOffsets(FMargin(0.0f, Item.CurrentY, 0.0f, 70.0f));
                }
            }
            Item.Widget->SetRenderOpacity(Item.Opacity);
        }
    }
    
    RankingItems.Sort([](const FRankingItem& A, const FRankingItem& B) {
        return A.Score > B.Score;
    });

    float YOffset = 0.0f;
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.TargetY = YOffset;
            YOffset += 80.0f;
        }
    }
    TargetRankingHeight = YOffset + 20.0f;
}

UWidget* UAdmobUserWidget::BuildAboutPage() {
    return Center()(Text(TEXT("About FlutterUMG")).FontSize(24));
}

void UAdmobUserWidget::OnShowInterstitialClicked() {
  Fluttertoast::showToast(
      this, Root,
      TEXT("Notification: You clicked on the Interstitial Ad button! (Toast)"));

  UGoogleMobileAdsBPLibrary::ShowInterstitialAd();
}

void UAdmobUserWidget::OnShowRewardedClicked() {
  Fluttertoast::showToast(
      this, Root,
      TEXT("Notification: You clicked on the Rewarded Ad button! (Toast)"));

  UGoogleMobileAdsBPLibrary::ShowRewardedAd();
}

void UAdmobUserWidget::OnShowBannerClicked() {
    Fluttertoast::showToast(this, Root, TEXT("Showing Banner Ad..."));
    UGoogleMobileAdsBPLibrary::ShowBannerAd();
}

void UAdmobUserWidget::OnHideBannerClicked() {
    Fluttertoast::showToast(this, Root, TEXT("Hiding Banner Ad..."));
    UGoogleMobileAdsBPLibrary::HideBannerAd();
}

void UAdmobUserWidget::NativeConstruct() {
  Super::NativeConstruct();

  if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0)) {
      PC->bShowMouseCursor = true;
      FInputModeUIOnly InputMode;
      InputMode.SetWidgetToFocus(TakeWidget());
      InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
      PC->SetInputMode(InputMode);
  }

  LoadProfile();

  if (UAdmobExampleGameInstance* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) {
      GI->SetMainWidget(this, Root);
  }

  UGoogleMobileAdsBPLibrary::OnUserEarnedReward.AddUObject(
      this, &UAdmobUserWidget::HandleRewardEarned);
  UGoogleMobileAdsBPLibrary::OnBannerAdLoadFailed.AddUObject(
      this, &UAdmobUserWidget::HandleBannerAdLoadFailed);
  UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.AddUObject(
      this, &UAdmobUserWidget::HandleInitializationComplete);

  // Demonstrate the new Toast system
  if (UGoogleMobileAdsBPLibrary::IsAdMobInitialized()) {
      Fluttertoast::showToast(this, Root, TEXT("AdMob Initialized!"));
  } else {
      Fluttertoast::showToast(this, Root, TEXT("AdMob Initializing..."));
  }

  // Pre-load the ads using the actual test IDs found in the Flutter app
  UGoogleMobileAdsBPLibrary::LoadInterstitialAd(
      TEXT("ca-app-pub-3940256099942544/1033173712"));
  UGoogleMobileAdsBPLibrary::LoadRewardedAd(
      TEXT("ca-app-pub-3940256099942544/5224354917"));
  
  // Show Banner Ad on initialization
  UGoogleMobileAdsBPLibrary::LoadBannerAd(
      TEXT("ca-app-pub-3940256099942544/2934735716"));
  UGoogleMobileAdsBPLibrary::ShowBannerAd();
}

void UAdmobUserWidget::NativeDestruct() {
  UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.RemoveAll(this);
  UGoogleMobileAdsBPLibrary::OnBannerAdLoadFailed.RemoveAll(this);
  UGoogleMobileAdsBPLibrary::HideBannerAd();
  UGoogleMobileAdsBPLibrary::OnUserEarnedReward.RemoveAll(this);
  Super::NativeDestruct();
}

void UAdmobUserWidget::HandleRewardEarned() {
  Fluttertoast::showToast(this, Root,
                          TEXT("Notification: You earned 10 points! (Toast)"));

  if (BannerPlaceholder) {
    BannerPlaceholder->SetText(
        FText::FromString(TEXT("You earned 10 points!")));
    BannerPlaceholder->SetColorAndOpacity(FSlateColor(FLinearColor::Green));
  }
}

void UAdmobUserWidget::HandleBannerAdLoadFailed(const FString& ErrorMessage) {
    FString ToastMsg = FString::Printf(TEXT("Banner Load Failed: %s"), *ErrorMessage);
    Fluttertoast::showToast(this, Root, ToastMsg);
}

void UAdmobUserWidget::HandleInitializationComplete(bool bSuccess, const FString& ErrorMessage) {
    if (bSuccess) {
        Fluttertoast::showToast(this, Root, TEXT("AdMob Initialized Successfully!"));
    } else {
        FString ToastMsg = FString::Printf(TEXT("AdMob Init FAILED: %s"), *ErrorMessage);
        Fluttertoast::showToast(this, Root, ToastMsg);
    }
}

void UAdmobUserWidget::OnCheckInitClicked() {
    if (UGoogleMobileAdsBPLibrary::IsAdMobInitialized()) {
        Fluttertoast::showToast(this, Root, TEXT("AdMob is already INITIALIZED."));
    } else {
        Fluttertoast::showToast(this, Root, TEXT("AdMob not initialized. Retrying..."));
        UGoogleMobileAdsBPLibrary::InitializeAdMob();
    }
}

void UAdmobUserWidget::OnListItemClicked(int32 Index) {
    FString Message = FString::Printf(TEXT("Clicked on item %d"), Index);
    Fluttertoast::showToast(this, Root, Message);
}
