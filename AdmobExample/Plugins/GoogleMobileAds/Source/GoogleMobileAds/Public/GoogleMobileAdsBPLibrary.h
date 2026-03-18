#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GoogleMobileAdsBPLibrary.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnUserEarnedRewardDelegate);

/**
 * A simple Blueprint Function Library exposing Google Mobile Ads initialization
 * and interstitial ads natively.
 */
UCLASS()
class GOOGLEMOBILEADS_API UGoogleMobileAdsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FOnUserEarnedRewardDelegate OnUserEarnedReward;

	/** Initializes the Google Mobile Ads SDK */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void InitializeAdMob();

	/** Loads an Interstitial Ad with a specific Ad Unit ID */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void LoadInterstitialAd(const FString& AdUnitID);

	/** Shows the previously loaded Interstitial Ad */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void ShowInterstitialAd();

	/** Loads a Rewarded Ad with a specific Ad Unit ID */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void LoadRewardedAd(const FString& AdUnitID);

	/** Shows the previously loaded Rewarded Ad */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void ShowRewardedAd();
};
