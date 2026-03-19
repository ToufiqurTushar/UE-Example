#include "FlutterInkWell.h"

UFlutterInkWell::UFlutterInkWell()
{
	// Default to transparent style for InkWell
	FButtonStyle Style;
	Style.Normal.TintColor = FSlateColor(FLinearColor::Transparent);
	Style.Hovered.TintColor = FSlateColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.05f));
	Style.Pressed.TintColor = FSlateColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.1f));
	
	Style.Normal.DrawAs = ESlateBrushDrawType::Box;
	Style.Hovered.DrawAs = ESlateBrushDrawType::Box;
	Style.Pressed.DrawAs = ESlateBrushDrawType::Box;

	SetStyle(Style);
	
	IsFocusable = false;
	SetClickMethod(EButtonClickMethod::PreciseClick);
}

void UFlutterInkWell::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	
	if (!OnClicked.Contains(this, "HandleInternalClick"))
	{
		OnClicked.AddUniqueDynamic(this, &UFlutterInkWell::HandleInternalClick);
	}
}

void UFlutterInkWell::HandleInternalClick()
{
	if (OnInkWellClicked.IsBound())
	{
		OnInkWellClicked.Broadcast(Index);
	}
}
