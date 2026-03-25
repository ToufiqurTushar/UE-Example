#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FormsExampleWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UFormsExampleWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
public:
	UFUNCTION() void OnBackClicked();
	UFUNCTION() void OnTextChanged(const FText& Text);
    UFUNCTION() void OnSubmitClicked();
};
