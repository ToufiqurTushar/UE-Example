#include "HomePageWidget.h"
#include "Engine/World.h"
#include "FlutterUMGWidgets.h"
#include "GoogleMobileAdsBPLibrary.h"
#include "TimerManager.h"
#include "AdmobExampleGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "ProfileSaveGame.h"
#include "UI/Pages/AdsPageWidget.h"
#include "UI/Pages/ListPageWidget.h"
#include "UI/Pages/ProfilePageWidget.h"
#include "UI/Pages/RankingPageWidget.h"
#include "UI/Pages/AboutPageWidget.h"

using namespace Flutter;

TSharedRef<SWidget> UHomePageWidget::RebuildWidget() {
  FFlutterBuildContext Context(this);

  if (!FlutterTheme::MaterialIconsFont) {
      FlutterTheme::MaterialIconsFont = LoadObject<UFont>(nullptr, TEXT("/Game/Fonts/MaterialIcons-Regular_Font.MaterialIcons-Regular_Font"));
      if (FlutterTheme::MaterialIconsFont) {
          UE_LOG(LogTemp, Log, TEXT("HomePageWidget: Material Icons Font loaded successfully."));
      } else {
          UE_LOG(LogTemp, Error, TEXT("HomePageWidget: FAILED to load Material Icons Font from /Game/Fonts/MaterialIcons-Regular_Font"));
      }
  }

  BottomNavigationBar InitialNav;
  BottomNavBar = InitialNav.Widget;

  auto Stack = IndexedStack().Index(CurrentTabIndex)(
      CreateWidget<UAdsPageWidget>(this),
      CreateWidget<UListPageWidget>(this),
      CreateWidget<UProfilePageWidget>(this),
      CreateWidget<URankingPageWidget>(this),
      CreateWidget<UAboutPageWidget>(this)
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

void UHomePageWidget::SwitchTab(int32 Index) {
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

void UHomePageWidget::OnTab0Clicked() { SwitchTab(0); }
void UHomePageWidget::OnTab1Clicked() { SwitchTab(1); }
void UHomePageWidget::OnTab2Clicked() { SwitchTab(2); }
void UHomePageWidget::OnTab3Clicked() { SwitchTab(3); }
void UHomePageWidget::OnTab4Clicked() { SwitchTab(4); }

void UHomePageWidget::NativeConstruct() {
  Super::NativeConstruct();

  if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0)) {
      PC->bShowMouseCursor = true;
      
      SetIsFocusable(true); // Fix "Attempting to focus Non-Focusable widget" error
      
      FInputModeUIOnly InputMode;
      InputMode.SetWidgetToFocus(TakeWidget());
      InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
      PC->SetInputMode(InputMode);
  }

  if (UAdmobExampleGameInstance* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) {
      GI->SetMainWidget(this, Root);
  }

  UGoogleMobileAdsBPLibrary::OnUserEarnedReward.AddUObject(
      this, &UHomePageWidget::HandleRewardEarned);
  UGoogleMobileAdsBPLibrary::OnBannerAdLoadFailed.AddUObject(
      this, &UHomePageWidget::HandleBannerAdLoadFailed);
  UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.AddUObject(
      this, &UHomePageWidget::HandleInitializationComplete);

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

void UHomePageWidget::NativeDestruct() {
  UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.RemoveAll(this);
  UGoogleMobileAdsBPLibrary::OnBannerAdLoadFailed.RemoveAll(this);
  UGoogleMobileAdsBPLibrary::HideBannerAd();
  UGoogleMobileAdsBPLibrary::OnUserEarnedReward.RemoveAll(this);
  Super::NativeDestruct();
}

void UHomePageWidget::HandleRewardEarned() {
  Fluttertoast::showToast(this, Root,
                          TEXT("Notification: You earned 10 points! (Toast)"));

  if (BannerPlaceholder) {
    BannerPlaceholder->SetText(
        FText::FromString(TEXT("You earned 10 points!")));
    BannerPlaceholder->SetColorAndOpacity(FSlateColor(FLinearColor::Green));
  }
}

void UHomePageWidget::HandleBannerAdLoadFailed(const FString& ErrorMessage) {
    FString ToastMsg = FString::Printf(TEXT("Banner Load Failed: %s"), *ErrorMessage);
    Fluttertoast::showToast(this, Root, ToastMsg);
}

void UHomePageWidget::HandleInitializationComplete(bool bSuccess, const FString& ErrorMessage) {
    if (bSuccess) {
        Fluttertoast::showToast(this, Root, TEXT("AdMob Initialized Successfully!"));
    } else {
        FString ToastMsg = FString::Printf(TEXT("AdMob Init FAILED: %s"), *ErrorMessage);
        Fluttertoast::showToast(this, Root, ToastMsg);
    }
}

