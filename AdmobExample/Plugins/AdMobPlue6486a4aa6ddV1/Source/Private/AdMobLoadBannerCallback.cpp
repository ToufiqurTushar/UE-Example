// Copyright (c) 2025 Loko. All Rights Reserved.

#include "AdMobLoadBannerCallback.h"
#include "AdMobFunctions.h"

static UAdMobLoadBannerCallback *LoadInstance = nullptr;
UAdMobLoadBannerCallback *UAdMobLoadBannerCallback::WatchBannerAd(const FString &AdUnitId, bool bIsAdaptive)
{
    LoadInstance = NewObject<UAdMobLoadBannerCallback>();
    LoadInstance->AddToRoot();
    UAdMobFunctions::AdMob_WatchBanner(AdUnitId, bIsAdaptive);
    return LoadInstance;
}

void UAdMobLoadBannerCallback::HandleSuccess()
{
    if (LoadInstance)
    {
        LoadInstance->OnSuccess.Broadcast();
        LoadInstance->RemoveFromRoot();
        LoadInstance = nullptr;
    }
}
void UAdMobLoadBannerCallback::HandleFailed()
{
    if (LoadInstance)
    {
        LoadInstance->OnFailed.Broadcast();
        LoadInstance->RemoveFromRoot();
        LoadInstance = nullptr;
    }
}
