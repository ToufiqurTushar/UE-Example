#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExamplesPageWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UExamplesPageWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

public:
	UFUNCTION() void OnTextExampleClicked();
	UFUNCTION() void OnLayoutExampleClicked();
    UFUNCTION() void OnFormsExampleClicked();
    UFUNCTION() void OnListsExampleClicked();
    UFUNCTION() void OnMediaExampleClicked();

private:
	// Appends the generated example to the viewport directly to create a push-page native overlay.
	void PushExamplePage(TSubclassOf<UUserWidget> WidgetClass);
};
