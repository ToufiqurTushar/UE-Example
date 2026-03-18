#include "AdmobUserWidget.h"
#include "Engine/World.h"
#include "FlutterUMGWidgets.h"
#include "GoogleMobileAdsBPLibrary.h"
#include "TimerManager.h"

using namespace Flutter;

TSharedRef<SWidget> UAdmobUserWidget::RebuildWidget() {
  FFlutterBuildContext Context(this);

  Root = Cast<UCanvasPanel>(
      Scaffold()
          .AppBar(AppBar().Title(Text(TEXT("GetX AdMob Example")).FontSize(20)))
          .Body(Flutter::Padding(FMargin(16.0f)).Child(Column()(
              Center()(Column().MainAxisAlignment(0)(
                  ElevatedButton()
                      .OnPressed(this, TEXT("OnShowInterstitialClicked"))
                      .Child(Text(TEXT("Show Interstitial"))),
                  SizedBox(1.0f, 20.0f),
                  ElevatedButton()
                      .OnPressed(this, TEXT("OnShowRewardedClicked"))
                      .Child(Text(TEXT("Show Rewarded")))
              )),
              SizedBox(1.0f, 20.0f),
              Center()(Text(TEXT("ListView.builder Example")).FontSize(18).Color(FLinearColor(0.13f, 0.13f, 0.13f, 1.0f))),
              SizedBox(1.0f, 10.0f),
              Expanded().Child(
                  ListView::builder(20, [](int32 Index) -> UWidget* {
                      return Flutter::Padding(FMargin(8.f, 4.f, 8.f, 4.f)).Child(
                          Card().SetElevation(4.0f).SetBorderRadius(8.0f).Child(
                              ListTile()
                                  .Leading(Container().Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f)).Padding(FMargin(8.f)).Child(Text(TEXT("#")).Color(FLinearColor::White).FontSize(16)))
                                  .Title(Text(FString::Printf(TEXT("Item %d"), Index)).FontSize(16))
                                  .Subtitle(Text(TEXT("ListTile description.")).FontSize(12).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)))
                                  .Trailing(Text(TEXT("Trailing")).FontSize(14).Color(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f)))
                          )
                      );
                  })
              )
          )))
          .BottomNavigationBar(
              Container()
                  .Color(FLinearColor(0.8f, 0.8f, 0.8f, 1.0f))
                  .Child(BannerPlaceholder = Text(TEXT("Banner Ad")).Widget))
          .Build());

  return Root->TakeWidget();
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

void UAdmobUserWidget::NativeConstruct() {
  Super::NativeConstruct();
  UGoogleMobileAdsBPLibrary::OnUserEarnedReward.AddUObject(
      this, &UAdmobUserWidget::HandleRewardEarned);

  // Demonstrate the new Toast system
  Fluttertoast::showToast(this, Root, TEXT("AdMob Initialized!"));

  // Pre-load the ads using the actual test IDs found in the Flutter app
  UGoogleMobileAdsBPLibrary::LoadInterstitialAd(
      TEXT("ca-app-pub-3940256099942544/1033173712"));
  UGoogleMobileAdsBPLibrary::LoadRewardedAd(
      TEXT("ca-app-pub-3940256099942544/5224354917"));
}

void UAdmobUserWidget::NativeDestruct() {
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
