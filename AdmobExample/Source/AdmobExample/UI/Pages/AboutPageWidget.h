#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AboutPageWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UAboutPageWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
