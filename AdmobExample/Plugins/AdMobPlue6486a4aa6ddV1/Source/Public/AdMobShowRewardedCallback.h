// Copyright (c) 2025 Loko. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AdMobShowRewardedCallback.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FAdMobRewardedCompleted,
    int32, Amount,
    const FString &, Type);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAdMobRewardedFailed);

UCLASS()
class ADMOBPLUGIN_API UAdMobShowRewardedCallback : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    /**
     * Loads and displays a Rewarded Ad using the provided Ad Unit ID.
     * Returns a callback object that notifies you when the user earns a reward,
     * the ad is shown, closed, or fails to load.
     */
    UFUNCTION(BlueprintCallable, Category = "AdMob", DisplayName = "Show Rewarded Ad",
              meta = (BlueprintInternalUseOnly = "true", ToolTip = "Displays a Rewarded Ad. Requires a valid Ad Unit ID. Returns a callback object for reward and ad lifecycle events."))
    static UAdMobShowRewardedCallback *WatchRewardedAd(const FString &AdUnitID);

    /*Called When user earns a reward from a Rewarded Ad.*/
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when the user earns a reward from a Rewarded Ad."))
    FAdMobRewardedCompleted OnCompleted;

    /*Called When Rewarded Ad Faild to Load*/
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when a Rewarded Ad Faild to Load"))
    FAdMobRewardedFailed OnFailed;

    // Called from JNI → ALWAYS forwarded to GameThread
    static void HandleRewardEarned(int32 Amount, const FString &Type);
    static void HandleRewardAdFailed();

private:
    // Track the active node safely (NO global static raw pointer!)
    static TWeakObjectPtr<UAdMobShowRewardedCallback> ActiveInstance;

    void FinishAndCleanup();
};
