#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ListsExampleWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UListsExampleWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
public:
	UFUNCTION() void OnBackClicked();
};
