// Copyright (c) 2025 Loko. All Rights Reserved.
#include "AdmobRewardedInterstitialCallback.h"
#include "AdMobFunctions.h"
#include "Async/Async.h"

TWeakObjectPtr<UAdmobRewardedInterstitialCallback> UAdmobRewardedInterstitialCallback::ActiveInstance;

// ------------------------------------------------------------
// CREATE NODE
// ------------------------------------------------------------
UAdmobRewardedInterstitialCallback *UAdmobRewardedInterstitialCallback::WatchRewardedInterstitialAd(const FString &AdUnitID)
{
    UAdmobRewardedInterstitialCallback *Node = NewObject<UAdmobRewardedInterstitialCallback>();
    ActiveInstance = Node;

    Node->AddToRoot(); // prevent GC
    UAdMobFunctions::AdMob_LoadRewardedInterstitial(AdUnitID);

    return Node;
}

// ------------------------------------------------------------
// JNI → GameThread: Reward Earned
// ------------------------------------------------------------
void UAdmobRewardedInterstitialCallback::HandleInterstitialRewardEarned(int32 Amount, const FString &Type)
{
    if (ActiveInstance.IsValid())
    {
        UAdmobRewardedInterstitialCallback *Node = ActiveInstance.Get();

        Async(EAsyncExecution::TaskGraphMainThread, [Node, Amount, Type]()
              {
            Node->OnCompleted.Broadcast(Amount, Type);
            Node->FinishAndCleanup(); });
    }
}

// ------------------------------------------------------------
// JNI → GameThread: Failed
// ------------------------------------------------------------
void UAdmobRewardedInterstitialCallback::HandleInterstitialRewardAdFailed()
{
    if (ActiveInstance.IsValid())
    {
        UAdmobRewardedInterstitialCallback *Node = ActiveInstance.Get();

        Async(EAsyncExecution::TaskGraphMainThread, [Node]()
              {
            Node->OnFailed.Broadcast();
            Node->FinishAndCleanup(); });
    }
}

// ------------------------------------------------------------
// Cleanup
// ------------------------------------------------------------
void UAdmobRewardedInterstitialCallback::FinishAndCleanup()
{
    ActiveInstance = nullptr;
    RemoveFromRoot();
}
