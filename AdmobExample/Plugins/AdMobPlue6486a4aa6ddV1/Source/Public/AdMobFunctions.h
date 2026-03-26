// Copyright (c) 2025 Loko. All Rights Reserved.
#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdMobFunctions.generated.h"

UCLASS()
class ADMOBPLUGIN_API UAdMobFunctions : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION()
    static void AdMob_WatchRewarded(const FString &AdUnitID);

    UFUNCTION()
    static void AdMob_ShowRewarded();

    UFUNCTION()
    static bool AdMob_IsRewardedLoaded();

    UFUNCTION()
    static void AdMob_WatchBanner(const FString &AdUnitID, bool bIsAdaptive);

    UFUNCTION()
    static void AdMob_ShowBanner();

    UFUNCTION()
    static void AdMob_HideBanner();

    UFUNCTION()
    static bool AdMob_IsBannerLoaded();

    UFUNCTION()
    static void AdMob_LoadRewardedInterstitial(const FString &AdUnitID);

    UFUNCTION()
    static void AdMob_ShowRewardedInterstitial();

    UFUNCTION()
    static void AdMob_LoadInterstitial(const FString &AdUnitID);

    UFUNCTION()
    static void AdMob_ShowInterstitial();
};