#include "SplashPage.h"
#include "TimerManager.h"
#include "Components/CanvasPanelSlot.h"
#include "Math/Vector2D.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Kismet/GameplayStatics.h"

TSharedRef<SWidget> USplashPage::RebuildWidget()
{
	//1
	Root = NewObject<UCanvasPanel>(this);
	Root->SetRenderOpacity(1.f);
		//1.2
		DescriptionTextBlock = NewObject<UTextBlock>(this);
		Root->AddChild(DescriptionTextBlock);
		DescriptionTextBlock->SetText(FText::FromString(TEXT("MyGame")));
		DescriptionTextBlock->SetJustification(ETextJustify::Center);
		//font
		FSlateFontInfo FontInfo = DescriptionTextBlock->GetFont();
		FontInfo.Size = 60.0f;
		DescriptionTextBlock->SetFont(FontInfo);
		DescriptionTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1, 0)));  // Start fully transparent
		if (auto* Slot = Cast<UCanvasPanelSlot>(DescriptionTextBlock->Slot))
		{
			//Slot->SetAnchors(UUIHelper::GetAnchor(EUIAlignment::Center_Bottom));
			//Slot->SetAlignment(UUIHelper::GetPivot(EUIAlignment::Center_Bottom));
			Slot->SetAutoSize(true);
			//Slot->SetOffsets(FMargin(0.f, 0.f, 0.f, 0.f));
			//Slot->SetPosition(FVector2D(0.f, 0.f));
		}
		
	return Root->TakeWidget();
}

void USplashPage::NativeConstruct()
{
	Super::NativeConstruct();

	// UTimerHelper::InterpolateFloat(
	// 	this, // World context (typically 'this' in an Actor or UObject)
	// 	0.0f, // Start value
	// 	1.0f, // End value
	// 	1.5f, // Duration in seconds
	// 	[this](float CurrentValue) // OnUpdate function
	// 	{
	// 		UE_LOG(LogTemp, Log, TEXT("Current Value: %f"), CurrentValue);
	// 		Root->SetRenderOpacity(CurrentValue);
	// 		FLinearColor Color = DescriptionTextBlock->GetColorAndOpacity().GetSpecifiedColor();
	// 		Color.A = CurrentValue;
	// 		DescriptionTextBlock->SetColorAndOpacity(FSlateColor(Color));
	// 	},
	// 	[this]() // OnComplete function
	// 	{
	// 		//UGameplayStatics::OpenLevel(this, FName(TEXT("RaceTrack_demonstration")));
	// 		UGameplayStatics::OpenLevel(this, FName(TEXT("Landing")));
	// 	}
	// );
}