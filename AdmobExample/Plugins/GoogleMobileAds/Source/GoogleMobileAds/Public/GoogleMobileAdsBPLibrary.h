#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GoogleMobileAdsBPLibrary.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnUserEarnedRewardDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnBannerAdLoadFailedDelegate, const FString& /* ErrorMessage */);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnAdMobInitializationCompleteDelegate, bool /* bSuccess */, const FString& /* ErrorMessage */);

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
	static FOnBannerAdLoadFailedDelegate OnBannerAdLoadFailed;
	static FOnAdMobInitializationCompleteDelegate OnAdMobInitializationComplete;

    static bool bIsInitialized;

    UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
    static bool IsAdMobInitialized() { return bIsInitialized; }

	/** Sets test device IDs for the Ad Requests */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void SetTestDeviceIds(const TArray<FString>& DeviceIDs);

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

	/** Loads a Banner Ad with a specific Ad Unit ID */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void LoadBannerAd(const FString& AdUnitID);

	/** Shows the previously loaded Banner Ad */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void ShowBannerAd();

	/** Hides the currently showing Banner Ad */
	UFUNCTION(BlueprintCallable, Category = "GoogleMobileAds")
	static void HideBannerAd();
};
