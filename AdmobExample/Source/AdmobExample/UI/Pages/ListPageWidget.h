#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ListPageWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UListPageWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

public:
    UFUNCTION()
    void OnListItemClicked(int32 Index);
};
