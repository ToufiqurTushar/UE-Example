#include "IOS/GoogleMobileAdsIOS.h"
#include "Async/Async.h"
#include "GoogleMobileAdsBPLibrary.h"

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
- (void)loadRequest:(id)request;
- (NSDictionary *)adapterStatusesByClassName;
@property(nonatomic, weak) UIViewController *rootViewController;
@property(nonatomic, copy) NSString *adUnitID;
@end

@interface AdMobBannerDelegate : NSObject
@end

@implementation AdMobBannerDelegate
- (void)bannerView:(id)bannerView didFailToReceiveAdWithError:(NSError *)error {
    NSString *ErrorMessage = [error localizedDescription];
    NSLog(@"[GoogleMobileAdsPlugin] Banner FAILED to load: %@", ErrorMessage);
    AsyncTask(ENamedThreads::GameThread, [ErrorMessage]() {
        UGoogleMobileAdsBPLibrary::OnBannerAdLoadFailed.Broadcast(FString(ErrorMessage));
    });
}
@end

static id GlobalInterstitialAd = nil;
static id GlobalRewardedAd = nil;
static id GlobalBannerView = nil;
static AdMobBannerDelegate* GlobalBannerDelegate = nil;

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
                NSDictionary *statuses = [status adapterStatusesByClassName];
                __block NSString *FirstError = nil;
                [statuses enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
                    NSInteger state = [[obj valueForKey:@"state"] integerValue];
                    if (state == 0) { // GADAdapterInitializationStateNotReady
                        FirstError = [obj valueForKey:@"description"];
                        *stop = YES;
                    }
                }];

                NSString* ErrorResult = FirstError;
                AsyncTask(ENamedThreads::GameThread, [ErrorResult]() {
                    if (ErrorResult) {
                        UGoogleMobileAdsBPLibrary::bIsInitialized = false;
                        UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.Broadcast(false, FString(ErrorResult));
                    } else {
                        UGoogleMobileAdsBPLibrary::bIsInitialized = true;
                        UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.Broadcast(true, TEXT(""));
                    }
                });
            }];
        } else {
            NSString* ErrorMsg = @"GADMobileAds class not found at runtime.";
            NSLog(@"[GoogleMobileAdsPlugin] %@", ErrorMsg);
            AsyncTask(ENamedThreads::GameThread, [ErrorMsg]() {
                UGoogleMobileAdsBPLibrary::bIsInitialized = false;
                UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.Broadcast(false, FString(ErrorMsg));
            });
        }
	});
}

void FGoogleMobileAdsIOS::LoadInterstitialAd(const FString& AdUnitID)
{
	NSString* NSAdUnitID = AdUnitID.GetNSString();
	dispatch_async(dispatch_get_main_queue(), ^{
        Class GADRequestClass = NSClassFromString(@"GADRequest");
        Class GADInterstitialAdClass = NSClassFromString(@"GADInterstitialAd");
        
        if (!GADRequestClass || !GADInterstitialAdClass) {
            NSLog(@"[GoogleMobileAdsPlugin] ERROR: Could not find AdMob classes (GADRequest: %@, GADInterstitialAd: %@)", 
                  GADRequestClass ? @"Found" : @"MISSING", 
                  GADInterstitialAdClass ? @"Found" : @"MISSING");
            return;
        }

        id request = [GADRequestClass request];
        NSLog(@"[GoogleMobileAdsPlugin] Starting interstitial load for UnitID: %@", NSAdUnitID);
        
        [GADInterstitialAdClass loadWithAdUnitID:NSAdUnitID request:request completionHandler:^(id ad, NSError *error) {
            if (error) {
                NSLog(@"[GoogleMobileAdsPlugin] FAILED to load interstitial ad: %@ (Error Code: %ld)", [error localizedDescription], (long)error.code);
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
        Class GADRequestClass = NSClassFromString(@"GADRequest");
        Class GADRewardedAdClass = NSClassFromString(@"GADRewardedAd");
        
        if (!GADRequestClass || !GADRewardedAdClass) {
            NSLog(@"[GoogleMobileAdsPlugin] ERROR: Could not find AdMob classes (GADRequest: %@, GADRewardedAd: %@)", 
                  GADRequestClass ? @"Found" : @"MISSING", 
                  GADRewardedAdClass ? @"Found" : @"MISSING");
            return;
        }

        id request = [GADRequestClass request];
        NSLog(@"[GoogleMobileAdsPlugin] Starting rewarded load for UnitID: %@", NSAdUnitID);

        [GADRewardedAdClass loadWithAdUnitID:NSAdUnitID request:request completionHandler:^(id ad, NSError *error) {
            if (error) {
                NSLog(@"[GoogleMobileAdsPlugin] FAILED to load rewarded ad: %@ (Error Code: %ld)", [error localizedDescription], (long)error.code);
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

void FGoogleMobileAdsIOS::LoadBannerAd(const FString& AdUnitID)
{
	NSString* NSAdUnitID = AdUnitID.GetNSString();
	dispatch_async(dispatch_get_main_queue(), ^{
        Class GADBannerViewClass = NSClassFromString(@"GADBannerView");
        Class GADRequestClass = NSClassFromString(@"GADRequest");

        if (!GADBannerViewClass || !GADRequestClass) {
            NSLog(@"[GoogleMobileAdsPlugin] ERROR: Could not find AdMob Banner classes.");
            return;
        }

        if (GlobalBannerView) {
            [GlobalBannerView removeFromSuperview];
            GlobalBannerView = nil;
        }

        if (!GlobalBannerDelegate) {
            GlobalBannerDelegate = [[AdMobBannerDelegate alloc] init];
        }
        
        id BannerView = [[GADBannerViewClass alloc] init];
        [BannerView setAdUnitID:NSAdUnitID];
        [BannerView setRootViewController:FGoogleMobileAdsIOS_GetRootVC()];
        [BannerView setValue:GlobalBannerDelegate forKey:@"delegate"];

        GlobalBannerView = BannerView;
        id request = [GADRequestClass request];
        [GlobalBannerView loadRequest:request];
        NSLog(@"[GoogleMobileAdsPlugin] Banner ad load initiated for: %@", NSAdUnitID);
	});
}

void FGoogleMobileAdsIOS::ShowBannerAd()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		if (GlobalBannerView) {
			UIViewController* RootVC = FGoogleMobileAdsIOS_GetRootVC();
			UIView* RootView = RootVC.view;
			
			CGRect Frame = [GlobalBannerView frame];
            if (Frame.size.height == 0) {
                Frame = CGRectMake(0, 0, 320, 50);
            }
			CGFloat ScreenHeight = RootView.bounds.size.height;
            CGFloat ScreenWidth = RootView.bounds.size.width;
			Frame.origin.y = ScreenHeight - Frame.size.height;
            Frame.origin.x = (ScreenWidth - Frame.size.width) / 2.0;
			[GlobalBannerView setFrame:Frame];
			
			[RootView addSubview:GlobalBannerView];
			NSLog(@"[GoogleMobileAdsPlugin] Banner ad added to subview.");
		} else {
            NSLog(@"[GoogleMobileAdsPlugin] Banner ad not loaded yet.");
        }
	});
}

void FGoogleMobileAdsIOS::HideBannerAd()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		if (GlobalBannerView) {
			[GlobalBannerView removeFromSuperview];
			NSLog(@"[GoogleMobileAdsPlugin] Banner ad hidden.");
		}
	});
}

#endif
