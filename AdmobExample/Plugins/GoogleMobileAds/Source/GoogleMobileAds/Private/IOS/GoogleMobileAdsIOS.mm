#include "IOS/GoogleMobileAdsIOS.h"

#if PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Forward-declare the CocoaPods headers so UBT can compile the C++ module cleanly
// The actual implementation is violently linked during the Xcode workspace phase
// Use an NSObject category to declare methods we'll call dynamically.
// This prevents the linker from needing the actual GAD class symbols at this stage.
@interface NSObject (AdMobDynamicStubs)
+ (id)sharedInstance;
- (void)startWithCompletionHandler:(void (^)(id status))completionHandler;
+ (id)request;
+ (void)loadWithAdUnitID:(NSString *)adUnitID request:(id)request completionHandler:(void (^)(id ad, NSError *error))completionHandler;
- (void)presentFromRootViewController:(UIViewController *)rootViewController;
- (void)presentFromRootViewController:(UIViewController *)rootViewController userDidEarnRewardHandler:(void (^)(void))userDidEarnRewardHandler;
@end

static id GlobalInterstitialAd = nil;
static id GlobalRewardedAd = nil;

UIViewController* FGoogleMobileAdsIOS_GetRootVC() {
    UIWindow *window = nil;
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (scene.activationState == UISceneActivationStateForegroundActive && [scene isKindOfClass:[UIWindowScene class]]) {
            window = ((UIWindowScene *)scene).windows.firstObject;
            break;
        }
    }
    if (!window) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        window = [UIApplication sharedApplication].windows.firstObject;
#pragma clang diagnostic pop
    }
    return window.rootViewController;
}

void FGoogleMobileAdsIOS::InitializeAdMob()
{
	dispatch_async(dispatch_get_main_queue(), ^{
        Class GADMobileAdsClass = NSClassFromString(@"GADMobileAds");
        if (GADMobileAdsClass) {
            [[GADMobileAdsClass sharedInstance] startWithCompletionHandler:^(id status) {
                NSLog(@"[GoogleMobileAdsPlugin] AdMob SDK Initialized completely!");
            }];
        } else {
            NSLog(@"[GoogleMobileAdsPlugin] GADMobileAds class not found at runtime. Ensure CocoaPods are linked.");
        }
	});
}

void FGoogleMobileAdsIOS::LoadInterstitialAd(const FString& AdUnitID)
{
	NSString* NSAdUnitID = AdUnitID.GetNSString();
	dispatch_async(dispatch_get_main_queue(), ^{
        Class GADRequestClass = NSClassFromString(@"GADRequest");
        Class GADInterstitialAdClass = NSClassFromString(@"GADInterstitialAd");
        if (GADRequestClass && GADInterstitialAdClass) {
            id request = [GADRequestClass request];
            [GADInterstitialAdClass loadWithAdUnitID:NSAdUnitID request:request completionHandler:^(id ad, NSError *error) {
                if (error) {
                    NSLog(@"[GoogleMobileAdsPlugin] Failed to load interstitial ad: %@", [error localizedDescription]);
                    return;
                }
                GlobalInterstitialAd = ad;
                NSLog(@"[GoogleMobileAdsPlugin] Interstitial ad loaded and cached successfully.");
            }];
        }
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
        Class GADRequestClass = NSClassFromString(@"GADRequest");
        Class GADRewardedAdClass = NSClassFromString(@"GADRewardedAd");
        if (GADRequestClass && GADRewardedAdClass) {
            id request = [GADRequestClass request];
            [GADRewardedAdClass loadWithAdUnitID:NSAdUnitID request:request completionHandler:^(id ad, NSError *error) {
                if (error) {
                    NSLog(@"[GoogleMobileAdsPlugin] Failed to load rewarded ad: %@", [error localizedDescription]);
                    return;
                }
                GlobalRewardedAd = ad;
                NSLog(@"[GoogleMobileAdsPlugin] Rewarded ad loaded and cached successfully.");
            }];
        }
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
