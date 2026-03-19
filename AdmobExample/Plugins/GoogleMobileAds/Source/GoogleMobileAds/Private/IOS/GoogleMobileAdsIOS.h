#pragma once

#include "CoreMinimal.h"

#if PLATFORM_IOS
class GOOGLEMOBILEADS_API FGoogleMobileAdsIOS
{
public:
	static void InitializeAdMob();
	static void LoadInterstitialAd(const FString& AdUnitID);
	static void ShowInterstitialAd();
	static void LoadRewardedAd(const FString& AdUnitID);
	static void ShowRewardedAd();
	static void LoadBannerAd(const FString& AdUnitID);
	static void ShowBannerAd();
	static void HideBannerAd();
};
#endif
