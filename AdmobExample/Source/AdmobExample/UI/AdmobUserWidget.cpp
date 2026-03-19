#include "AdmobUserWidget.h"
#include "Engine/World.h"
#include "FlutterUMGWidgets.h"
#include "GoogleMobileAdsBPLibrary.h"
#include "TimerManager.h"
#include "AdmobExampleGameInstance.h"

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
      BuildSettingsPage(),
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
            BottomNavigationBarItem(Icons::Settings, TEXT("Settings")),
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
    return Center()(Text(TEXT("Profile Page")).FontSize(24));
}

UWidget* UAdmobUserWidget::BuildSettingsPage() {
    return Center()(Text(TEXT("Settings")).FontSize(24));
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
