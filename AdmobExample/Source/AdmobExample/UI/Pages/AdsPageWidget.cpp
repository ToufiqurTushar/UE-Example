#include "AdsPageWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"
#include "GoogleMobileAdsBPLibrary.h"
#include "AdmobExampleGameInstance.h"

using namespace Flutter;

TSharedRef<SWidget> UAdsPageWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);

    auto MyCol = Flutter::Padding(FMargin(16.0f)).Child(Column()(
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

    if (WidgetTree) {
        WidgetTree->RootWidget = MyCol.Widget;
    }

    return MyCol.Widget->TakeWidget();
}

void UAdsPageWidget::OnShowInterstitialClicked() {
  if (auto* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) GI->ShowToast(TEXT("Notification: You clicked on the Interstitial Ad button! (Toast)"));
  UGoogleMobileAdsBPLibrary::ShowInterstitialAd();
}

void UAdsPageWidget::OnShowRewardedClicked() {
  if (auto* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) GI->ShowToast(TEXT("Notification: You clicked on the Rewarded Ad button! (Toast)"));
  UGoogleMobileAdsBPLibrary::ShowRewardedAd();
}

void UAdsPageWidget::OnShowBannerClicked() {
    if (auto* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) GI->ShowToast(TEXT("Showing Banner Ad..."));
    UGoogleMobileAdsBPLibrary::ShowBannerAd();
}

void UAdsPageWidget::OnHideBannerClicked() {
    if (auto* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) GI->ShowToast(TEXT("Hiding Banner Ad..."));
    UGoogleMobileAdsBPLibrary::HideBannerAd();
}

void UAdsPageWidget::OnCheckInitClicked() {
    if (UGoogleMobileAdsBPLibrary::IsAdMobInitialized()) {
        if (auto* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) GI->ShowToast(TEXT("AdMob is already INITIALIZED."));
    } else {
        if (auto* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) GI->ShowToast(TEXT("AdMob not initialized. Retrying..."));
        UGoogleMobileAdsBPLibrary::InitializeAdMob();
    }
}
