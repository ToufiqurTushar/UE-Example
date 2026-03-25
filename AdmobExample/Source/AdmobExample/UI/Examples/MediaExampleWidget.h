#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MediaExampleWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UMediaExampleWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
public:
	UFUNCTION() void OnBackClicked();
};
