#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GoogleMobileAdsRuntimeSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class GOOGLEMOBILEADS_API UGoogleMobileAdsRuntimeSettings : public UObject
{
	GENERATED_BODY()

public:
	UGoogleMobileAdsRuntimeSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Config, EditAnywhere, Category = "Application Configuration", meta = (DisplayName = "AdMob App ID (Android)"))
	FString AdMobAppID_Android;

	UPROPERTY(Config, EditAnywhere, Category = "Application Configuration", meta = (DisplayName = "AdMob App ID (iOS)"))
	FString AdMobAppID_IOS;
};
