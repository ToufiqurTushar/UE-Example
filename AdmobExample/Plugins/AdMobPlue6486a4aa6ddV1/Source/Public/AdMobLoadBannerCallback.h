// Copyright (c) 2025 Loko. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AdMobLoadBannerCallback.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAdMobBannerLoadSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAdMobBannerLoadFailed);

UCLASS()
class ADMOBPLUGIN_API UAdMobLoadBannerCallback : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    /**
     * Loads and displays an AdMob Banner Ad using the given Ad Unit ID.
     * Supports standard or adaptive banner sizes. Returns a callback object
     * allowing you to handle load success or failure events.
     */
    UFUNCTION(BlueprintCallable, Category = "AdMob", DisplayName = "Show Banner Ad",
              meta = (BlueprintInternalUseOnly = "true",ToolTip = "Loads and displays an AdMob Banner Ad. 'bIsAdaptive' enables adaptive banner sizing. Returns a callback object for banner load events."))
    static UAdMobLoadBannerCallback *WatchBannerAd(const FString &AdUnitId, bool bIsAdaptive);

    /** Called when the banner ad loads successfully. */
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when a Banner Ad finishes loading successfully."))
    FAdMobBannerLoadSuccess OnSuccess;

    /** Called when the banner ad fails to load. */
    UPROPERTY(BlueprintAssignable, Category = "AdMob", meta = (ToolTip = "Triggered when a Banner Ad fails to load."))
    FAdMobBannerLoadFailed OnFailed;

    static void HandleSuccess();
    static void HandleFailed();
};
