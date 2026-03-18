#pragma once

#include "CoreMinimal.h"

#if PLATFORM_IOS
class FGoogleMobileAdsIOS
{
public:
	static void InitializeAdMob();
	static void LoadInterstitialAd(const FString& AdUnitID);
	static void ShowInterstitialAd();
	static void LoadRewardedAd(const FString& AdUnitID);
	static void ShowRewardedAd();
};
#endif
