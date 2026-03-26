// Copyright (c) 2025 Loko. All Rights Reserved.

#include "AdmobInterstitialCallback.h"
#include "AdMobFunctions.h"
#include "Async/Async.h"

TWeakObjectPtr<UAdmobInterstitialCallback> UAdmobInterstitialCallback::ActiveInstance;

// ------------------------------------------------------------
// CREATE NODE
// ------------------------------------------------------------
UAdmobInterstitialCallback *UAdmobInterstitialCallback::WatchInterstitialAd(const FString &AdUnitID)
{
    UAdmobInterstitialCallback *Node = NewObject<UAdmobInterstitialCallback>();
    ActiveInstance = Node;

    Node->AddToRoot(); // prevent GC
    UAdMobFunctions::AdMob_LoadInterstitial(AdUnitID);

    return Node;
}

// ------------------------------------------------------------
// JNI → GameThread: Completed
// ------------------------------------------------------------
void UAdmobInterstitialCallback::HandleInterstitialAdCompleted()
{
    if (ActiveInstance.IsValid())
    {
        UAdmobInterstitialCallback *Node = ActiveInstance.Get();

        Async(EAsyncExecution::TaskGraphMainThread, [Node]()
              {
            Node->OnCompleted.Broadcast();
            Node->FinishAndCleanup(); });
    }
}

// ------------------------------------------------------------
// JNI → GameThread: Failed
// ------------------------------------------------------------
void UAdmobInterstitialCallback::HandleInterstitialAdFailed()
{
    if (ActiveInstance.IsValid())
    {
        UAdmobInterstitialCallback *Node = ActiveInstance.Get();

        Async(EAsyncExecution::TaskGraphMainThread, [Node]()
              {
            Node->OnFailed.Broadcast();
            Node->FinishAndCleanup(); });
    }
}

// ------------------------------------------------------------
// Cleanup
// ------------------------------------------------------------
void UAdmobInterstitialCallback::FinishAndCleanup()
{
    ActiveInstance = nullptr;
    RemoveFromRoot();
}
