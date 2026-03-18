#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "TimerManager.h"
#include "Components/CanvasPanel.h"
#include "Widgets/SWidget.h"
#include "SplashPage.generated.h"


UCLASS()
class EXAMPLE_API USplashPage : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void NativeConstruct() override;

private:
	UPROPERTY()
	UCanvasPanel* Root;
	
	UPROPERTY()
	UTextBlock* DescriptionTextBlock;
};
