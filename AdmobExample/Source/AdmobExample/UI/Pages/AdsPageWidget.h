#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AdsPageWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UAdsPageWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

public:
	UFUNCTION() void OnShowInterstitialClicked();
	UFUNCTION() void OnShowRewardedClicked();
	UFUNCTION() void OnShowBannerClicked();
	UFUNCTION() void OnHideBannerClicked();
	UFUNCTION() void OnCheckInitClicked();
};
