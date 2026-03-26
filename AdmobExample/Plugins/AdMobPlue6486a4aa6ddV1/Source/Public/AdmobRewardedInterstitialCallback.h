// Copyright (c) 2025 Loko. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AdmobRewardedInterstitialCallback.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FAdMobInterstitialRewardedCompleted,
    int32, Amount,
    const FString &, Type);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAdMobInterstitialRewardedFailed);

UCLASS()
class ADMOBPLUGIN_API UAdmobRewardedInterstitialCallback : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    /**
     * Loads and displays a Rewarded Interstitial Ad using the provided Ad Unit ID.
     * Returns a callback object allowing you to handle reward events, ad closed,
     * ad failed, and ad shown notifications.
     */
    UFUNCTION(BlueprintCallable, Category = "AdMob", DisplayName = "Show Rewarded Interstitial Ad",
              meta = (BlueprintInternalUseOnly = "true", ToolTip = "Displays a Rewarded Interstitial Ad. Requires a valid Ad Unit ID. Returns a callback object for reward and ad lifecycle events."))
    static UAdmobRewardedInterstitialCallback *WatchRewardedInterstitialAd(const FString &AdUnitID);

    /** Called when the user earns a reward from a Rewarded Interstitial Ad. */
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when the user earns a reward from a Rewarded Interstitial Ad."))
    FAdMobInterstitialRewardedCompleted OnCompleted;

    /** Called when a Rewarded Interstitial Ad fails to load or show. */
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when a Rewarded Interstitial Ad fails to load or show."))
    FAdMobInterstitialRewardedFailed OnFailed;

    // Called from JNI → ALWAYS forwarded to GameThread
    static void HandleInterstitialRewardEarned(int32 Amount, const FString &Type);
    static void HandleInterstitialRewardAdFailed();

private:
    // Active async node instance
    static TWeakObjectPtr<UAdmobRewardedInterstitialCallback> ActiveInstance;

    void FinishAndCleanup();
};
