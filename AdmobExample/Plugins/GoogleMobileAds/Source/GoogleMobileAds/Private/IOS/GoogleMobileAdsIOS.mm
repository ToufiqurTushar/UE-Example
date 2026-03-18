#include "IOS/GoogleMobileAdsIOS.h"

#if PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
// Uncomment when GoogleMobileAds.framework is linked properly
// #import <GoogleMobileAds/GoogleMobileAds.h>

void FGoogleMobileAdsIOS::InitializeAdMob()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		// [GADMobileAds.sharedInstance startWithCompletionHandler:nil];
		NSLog(@"[GoogleMobileAdsPlugin] InitializeAdMob called on iOS");
	});
}

void FGoogleMobileAdsIOS::LoadInterstitialAd(const FString& AdUnitID)
{
	NSString* NSAdUnitID = AdUnitID.GetNSString();
	dispatch_async(dispatch_get_main_queue(), ^{
		// GADRequest *request = [GADRequest request];
		// [GADInterstitialAd loadWithAdUnitID:NSAdUnitID request:request completionHandler:nil];
		NSLog(@"[GoogleMobileAdsPlugin] LoadInterstitialAd called with ID: %@", NSAdUnitID);
	});
}

void FGoogleMobileAdsIOS::ShowInterstitialAd()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		NSLog(@"[GoogleMobileAdsPlugin] ShowInterstitialAd called");
	});
}

void FGoogleMobileAdsIOS::LoadRewardedAd(const FString& AdUnitID)
{
	NSString* NSAdUnitID = AdUnitID.GetNSString();
	dispatch_async(dispatch_get_main_queue(), ^{
		NSLog(@"[GoogleMobileAdsPlugin] LoadRewardedAd called with ID: %@", NSAdUnitID);
	});
}

void FGoogleMobileAdsIOS::ShowRewardedAd()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		NSLog(@"[GoogleMobileAdsPlugin] ShowRewardedAd called");
	});
}

#endif
