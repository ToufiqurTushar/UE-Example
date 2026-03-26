// Copyright (c) 2025 Loko. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AdmobInterstitialCallback.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAdMobInterstitialCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAdMobInterstitialFailed);

UCLASS()
class ADMOBPLUGIN_API UAdmobInterstitialCallback : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    /**
     * Displays an AdMob Interstitial Ad using the provided Ad Unit ID.
     * Returns a callback object that notifies you when the ad is closed, failed, or shown.
     */

    UFUNCTION(BlueprintCallable, Category = "AdMob", DisplayName = "Show Interstitial Ad",
              meta = (BlueprintInternalUseOnly = "true", ToolTip = "Displays an AdMob Interstitial Ad. Requires a valid Ad Unit ID.Returns a callback object for ad events."))
    static UAdmobInterstitialCallback *WatchInterstitialAd(const FString &AdUnitID);

    /*Called When Interstitial Ad is closed after being displayed*/
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when an Interstitial Ad is closed after being displayed."))
    FAdMobInterstitialCompleted OnCompleted;

    /*Called When Interstitial Ad fails to load or show*/
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when an Interstitial Ad fails to load or show."))
    FAdMobInterstitialFailed OnFailed;

    // Called from JNI → ALWAYS forwarded to GameThread
    static void HandleInterstitialAdCompleted();
    static void HandleInterstitialAdFailed();

private:
    // Track the active node safely (NO global static raw pointer!)
    static TWeakObjectPtr<UAdmobInterstitialCallback> ActiveInstance;

    void FinishAndCleanup();
};
