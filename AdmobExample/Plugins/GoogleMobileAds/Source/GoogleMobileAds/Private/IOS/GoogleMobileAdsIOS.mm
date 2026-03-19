#include "IOS/GoogleMobileAdsIOS.h"

#if PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GoogleMobileAds/GoogleMobileAds.h>

static GADInterstitialAd* GlobalInterstitialAd = nil;
static GADRewardedAd* GlobalRewardedAd = nil;

UIViewController* FGoogleMobileAdsIOS_GetRootVC() {
    UIWindow *window = nil;
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (scene.activationState == UISceneActivationStateForegroundActive && [scene isKindOfClass:[UIWindowScene class]]) {
            window = ((UIWindowScene *)scene).windows.firstObject;
            break;
        }
    }
    if (!window) {
        window = [UIApplication sharedApplication].windows.firstObject;
    }
    return window.rootViewController;
}

void FGoogleMobileAdsIOS::InitializeAdMob()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[GADMobileAds.sharedInstance startWithCompletionHandler:^(GADInitializationStatus *status) {
			NSLog(@"[GoogleMobileAdsPlugin] AdMob SDK Initialized completely!");
		}];
	});
}

void FGoogleMobileAdsIOS::LoadInterstitialAd(const FString& AdUnitID)
{
	NSString* NSAdUnitID = AdUnitID.GetNSString();
	dispatch_async(dispatch_get_main_queue(), ^{
		GADRequest *request = [GADRequest request];
		[GADInterstitialAd loadWithAdUnitID:NSAdUnitID request:request completionHandler:^(GADInterstitialAd *ad, NSError *error) {
			if (error) {
				NSLog(@"[GoogleMobileAdsPlugin] Failed to load interstitial ad: %@", [error localizedDescription]);
				return;
			}
			GlobalInterstitialAd = ad;
			NSLog(@"[GoogleMobileAdsPlugin] Interstitial ad loaded and cached successfully.");
		}];
	});
}

void FGoogleMobileAdsIOS::ShowInterstitialAd()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		if (GlobalInterstitialAd) {
			UIViewController* RootVC = FGoogleMobileAdsIOS_GetRootVC();
			[GlobalInterstitialAd presentFromRootViewController:RootVC];
			GlobalInterstitialAd = nil;
		} else {
			NSLog(@"[GoogleMobileAdsPlugin] Interstitial ad wasn't loaded yet.");
		}
	});
}

void FGoogleMobileAdsIOS::LoadRewardedAd(const FString& AdUnitID)
{
	NSString* NSAdUnitID = AdUnitID.GetNSString();
	dispatch_async(dispatch_get_main_queue(), ^{
		GADRequest *request = [GADRequest request];
		[GADRewardedAd loadWithAdUnitID:NSAdUnitID request:request completionHandler:^(GADRewardedAd *ad, NSError *error) {
			if (error) {
				NSLog(@"[GoogleMobileAdsPlugin] Failed to load rewarded ad: %@", [error localizedDescription]);
				return;
			}
			GlobalRewardedAd = ad;
			NSLog(@"[GoogleMobileAdsPlugin] Rewarded ad loaded and cached successfully.");
		}];
	});
}

void FGoogleMobileAdsIOS::ShowRewardedAd()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		if (GlobalRewardedAd) {
			UIViewController* RootVC = FGoogleMobileAdsIOS_GetRootVC();
			[GlobalRewardedAd presentFromRootViewController:RootVC userDidEarnRewardHandler:^{
				NSLog(@"[GoogleMobileAdsPlugin] Reward granted!");
			}];
			GlobalRewardedAd = nil;
		} else {
			NSLog(@"[GoogleMobileAdsPlugin] Rewarded ad wasn't loaded yet.");
		}
	});
}

#endif
