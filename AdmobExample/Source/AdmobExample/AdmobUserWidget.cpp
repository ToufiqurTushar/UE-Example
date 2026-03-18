#include "AdmobUserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Math/Vector2D.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/Spacer.h"
#include "Components/Border.h"
#include "Components/BorderSlot.h"
#include "GoogleMobileAdsBPLibrary.h"

TSharedRef<SWidget> UAdmobUserWidget::RebuildWidget()
{
	Root = NewObject<UCanvasPanel>(this);
	Root->SetRenderOpacity(1.f);
	
	// AppBar (Top)
	UBorder* AppBarBg = NewObject<UBorder>(this);
	AppBarBg->SetBrushColor(FLinearColor(0.1f, 0.4f, 0.8f, 1.0f)); // Flutter Material Blue
	Root->AddChild(AppBarBg);
	if (auto* Slot = Cast<UCanvasPanelSlot>(AppBarBg->Slot))
	{
		Slot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 0.0f));
		Slot->SetOffsets(FMargin(0.0f, 0.0f, 0.0f, 60.0f));
	}
	AppBarText = NewObject<UTextBlock>(this);
	AppBarText->SetText(FText::FromString(TEXT("GetX AdMob Example")));
	AppBarBg->AddChild(AppBarText);
	if (auto* Slot = Cast<UBorderSlot>(AppBarText->Slot))
	{
		Slot->SetPadding(FMargin(16.0f, 0.0f));
		Slot->SetVerticalAlignment(VAlign_Center);
	}
	FSlateFontInfo FontInfo = AppBarText->GetFont();
	FontInfo.Size = 20.0f;
	AppBarText->SetFont(FontInfo);

	// Body (Center Column)
	CenterBox = NewObject<UVerticalBox>(this);
	Root->AddChild(CenterBox);
	if (auto* Slot = Cast<UCanvasPanelSlot>(CenterBox->Slot))
	{
		Slot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
		Slot->SetAlignment(FVector2D(0.5f, 0.5f));
		Slot->SetAutoSize(true);
	}

	BtnShowInterstitial = NewObject<UButton>(this);
	UTextBlock* TxtInter = NewObject<UTextBlock>(this);
	TxtInter->SetText(FText::FromString(TEXT("Show Interstitial")));
	TxtInter->SetColorAndOpacity(FSlateColor(FLinearColor::Black));
	BtnShowInterstitial->AddChild(TxtInter);
	BtnShowInterstitial->OnClicked.AddDynamic(this, &UAdmobUserWidget::OnShowInterstitialClicked);
	CenterBox->AddChild(BtnShowInterstitial);

	USpacer* Spacer = NewObject<USpacer>(this);
	Spacer->SetSize(FVector2D(1.0f, 20.0f));
	CenterBox->AddChild(Spacer);

	BtnShowRewarded = NewObject<UButton>(this);
	UTextBlock* TxtTarget = NewObject<UTextBlock>(this);
	TxtTarget->SetText(FText::FromString(TEXT("Show Rewarded")));
	TxtTarget->SetColorAndOpacity(FSlateColor(FLinearColor::Black));
	BtnShowRewarded->AddChild(TxtTarget);
	BtnShowRewarded->OnClicked.AddDynamic(this, &UAdmobUserWidget::OnShowRewardedClicked);
	CenterBox->AddChild(BtnShowRewarded);

	// BottomNavigationBar (Banner Placeholder)
	UBorder* BannerBg = NewObject<UBorder>(this);
	BannerBg->SetBrushColor(FLinearColor(0.8f, 0.8f, 0.8f, 1.0f));
	Root->AddChild(BannerBg);
	if (auto* Slot = Cast<UCanvasPanelSlot>(BannerBg->Slot))
	{
		Slot->SetAnchors(FAnchors(0.0f, 1.0f, 1.0f, 1.0f));
		Slot->SetOffsets(FMargin(0.0f, -50.0f, 0.0f, 0.0f)); // Height 50
	}
	BannerPlaceholder = NewObject<UTextBlock>(this);
	BannerPlaceholder->SetText(FText::FromString(TEXT("Banner Ad")));
	BannerPlaceholder->SetColorAndOpacity(FSlateColor(FLinearColor::Black));
	BannerPlaceholder->SetJustification(ETextJustify::Center);
	BannerBg->AddChild(BannerPlaceholder);
	if (auto* Slot = Cast<UBorderSlot>(BannerPlaceholder->Slot))
	{
		Slot->SetVerticalAlignment(VAlign_Center);
		Slot->SetHorizontalAlignment(HAlign_Center);
	}

	return Root->TakeWidget();
}

void UAdmobUserWidget::OnShowInterstitialClicked()
{
	UGoogleMobileAdsBPLibrary::ShowInterstitialAd();
}

void UAdmobUserWidget::OnShowRewardedClicked()
{
	UGoogleMobileAdsBPLibrary::ShowRewardedAd();
}

void UAdmobUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UGoogleMobileAdsBPLibrary::OnUserEarnedReward.AddUObject(this, &UAdmobUserWidget::HandleRewardEarned);
	
	// Initialize AdMob automatically when the widget starts
	UGoogleMobileAdsBPLibrary::InitializeAdMob();
	
	// Pre-load the ads using the actual test IDs found in the Flutter app
	UGoogleMobileAdsBPLibrary::LoadInterstitialAd(TEXT("ca-app-pub-3940256099942544/1033173712"));
	UGoogleMobileAdsBPLibrary::LoadRewardedAd(TEXT("ca-app-pub-3940256099942544/5224354917"));
}

void UAdmobUserWidget::NativeDestruct()
{
	UGoogleMobileAdsBPLibrary::OnUserEarnedReward.RemoveAll(this);
	Super::NativeDestruct();
}

void UAdmobUserWidget::HandleRewardEarned()
{
	if (BannerPlaceholder)
	{
		BannerPlaceholder->SetText(FText::FromString(TEXT("You earned 10 points!")));
		BannerPlaceholder->SetColorAndOpacity(FSlateColor(FLinearColor::Green));
	}
}
