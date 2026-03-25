#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TextExampleWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UTextExampleWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

public:
	UFUNCTION() void OnBackClicked();
};
