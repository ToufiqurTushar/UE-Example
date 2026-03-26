// Copyright (c) 2025 Loko. All Rights Reserved.

#include "AdMobShowRewardedCallback.h"
#include "AdMobFunctions.h"
#include "Async/Async.h"

TWeakObjectPtr<UAdMobShowRewardedCallback> UAdMobShowRewardedCallback::ActiveInstance;

// ------------------------------------------------------------
// CREATE NODE
// ------------------------------------------------------------
UAdMobShowRewardedCallback *UAdMobShowRewardedCallback::WatchRewardedAd(const FString &AdUnitID)
{
    UAdMobShowRewardedCallback *Node = NewObject<UAdMobShowRewardedCallback>();
    ActiveInstance = Node;

    Node->AddToRoot(); // prevent GC
    UAdMobFunctions::AdMob_WatchRewarded(AdUnitID);

    return Node;
}

// ------------------------------------------------------------
// JNI → GameThread: Reward Earned
// ------------------------------------------------------------
void UAdMobShowRewardedCallback::HandleRewardEarned(int32 Amount, const FString &Type)
{
    Async(EAsyncExecution::TaskGraphMainThread, [Amount, Type]()
          {
        if (!ActiveInstance.IsValid())
            return;

        UAdMobShowRewardedCallback* Node = ActiveInstance.Get();
        Node->OnCompleted.Broadcast(Amount, Type);

        Node->FinishAndCleanup(); });
}

// ------------------------------------------------------------
// JNI → GameThread: Failed
// ------------------------------------------------------------
void UAdMobShowRewardedCallback::HandleRewardAdFailed()
{
    Async(EAsyncExecution::TaskGraphMainThread, []()
          {
        if (!ActiveInstance.IsValid())
            return;

        UAdMobShowRewardedCallback* Node = ActiveInstance.Get();
        Node->OnFailed.Broadcast();

        Node->FinishAndCleanup(); });
}

// ------------------------------------------------------------
// Safe Cleanup (AFTER delegate execution)
// ------------------------------------------------------------
void UAdMobShowRewardedCallback::FinishAndCleanup()
{
    RemoveFromRoot();
    ActiveInstance.Reset();
}
