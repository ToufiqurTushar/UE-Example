#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LayoutExampleWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API ULayoutExampleWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

public:
	UFUNCTION() void OnBackClicked();
};
