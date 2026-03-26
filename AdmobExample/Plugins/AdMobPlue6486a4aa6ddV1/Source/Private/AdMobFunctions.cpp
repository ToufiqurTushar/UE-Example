// Copyright (c) 2025 Loko. All Rights Reserved.

#include "AdMobFunctions.h"
#include "AdMobShowRewardedCallback.h"
#include "AdMobLoadBannerCallback.h"
#include "AdmobRewardedInterstitialCallback.h"
#include "AdmobInterstitialCallback.h"
#include "Async/Async.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"

static jclass AdMobClass = nullptr;
static jobject AdMobObject = nullptr;

static jmethodID GetMethod(const char *Name, const char *Sig)
{
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    return Env->GetMethodID(AdMobClass, Name, Sig);
}
#endif

static void InitAdMobJava()
{
#if PLATFORM_ANDROID
    if (AdMobClass != nullptr)
        return;

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    jclass TempClass = FAndroidApplication::FindJavaClass("com/google/admob/AdMobManager");
    AdMobClass = (jclass)Env->NewGlobalRef(TempClass);

    jmethodID Constructor = Env->GetMethodID(AdMobClass, "<init>", "(Landroid/app/Activity;)V");

    jobject Activity = FAndroidApplication::GetGameActivityThis();
    jobject LocalObj = Env->NewObject(AdMobClass, Constructor, Activity);

    AdMobObject = Env->NewGlobalRef(LocalObj);

    Env->DeleteLocalRef(LocalObj);
    Env->DeleteLocalRef(TempClass);

    UE_LOG(LogTemp, Warning, TEXT("AdMob Java Manager Initialized."));
#endif
}

//-----------------------------------------------------------
// Blueprint Functions
//-----------------------------------------------------------
void UAdMobFunctions::AdMob_WatchRewarded(const FString &AdUnitID)
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("loadRewarded", "(Ljava/lang/String;)V");

    jstring jID = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
    Env->CallVoidMethod(AdMobObject, Method, jID);
    Env->DeleteLocalRef(jID);
#endif
}

void UAdMobFunctions::AdMob_ShowRewarded()
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("showRewarded", "()V");
    Env->CallVoidMethod(AdMobObject, Method);
#endif
}

bool UAdMobFunctions::AdMob_IsRewardedLoaded()
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("isRewardedLoaded", "()Z");

    return Env->CallBooleanMethod(AdMobObject, Method);
#else
    return false;
#endif
}

// Banner
void UAdMobFunctions::AdMob_WatchBanner(const FString &AdUnitID, bool bIsAdaptive)
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("loadBanner", "(Ljava/lang/String;Z)V");

    jstring jID = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
    jboolean jAdaptive = bIsAdaptive ? JNI_TRUE : JNI_FALSE;

    Env->CallVoidMethod(AdMobObject, Method, jID, jAdaptive);
    Env->DeleteLocalRef(jID);
#endif
}

void UAdMobFunctions::AdMob_ShowBanner()
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("showBanner", "()V");
    Env->CallVoidMethod(AdMobObject, Method);
#endif
}

void UAdMobFunctions::AdMob_HideBanner()
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("hideBanner", "()V");
    Env->CallVoidMethod(AdMobObject, Method);
#endif
}

bool UAdMobFunctions::AdMob_IsBannerLoaded()
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("isBannerLoaded", "()Z");

    return Env->CallBooleanMethod(AdMobObject, Method);
#else
    return false;
#endif
}

void UAdMobFunctions::AdMob_LoadRewardedInterstitial(const FString &AdUnitID)
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("loadRewardedInterstitial", "(Ljava/lang/String;)V");

    jstring jID = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
    Env->CallVoidMethod(AdMobObject, Method, jID);
    Env->DeleteLocalRef(jID);
#endif
}
void UAdMobFunctions::AdMob_ShowRewardedInterstitial()
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("showRewardedInterstitial", "()V");
    Env->CallVoidMethod(AdMobObject, Method);
#endif
}

void UAdMobFunctions::AdMob_LoadInterstitial(const FString &AdUnitID)
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("loadInterstitial", "(Ljava/lang/String;)V");

    jstring jID = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
    Env->CallVoidMethod(AdMobObject, Method, jID);
    Env->DeleteLocalRef(jID);
#endif
}

void UAdMobFunctions::AdMob_ShowInterstitial()
{
#if PLATFORM_ANDROID
    InitAdMobJava();

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jmethodID Method = GetMethod("showInterstitial", "()V");
    Env->CallVoidMethod(AdMobObject, Method);
#endif
}

//-----------------------------------------------------------
// JNI CALLBACKS - FULLY SAFE (GAME THREAD ONLY)
//-----------------------------------------------------------
#if PLATFORM_ANDROID

extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onRewardedLoadSuccess(JNIEnv *, jobject)
{
    AsyncTask(ENamedThreads::GameThread, []()
              { UAdMobFunctions::AdMob_ShowRewarded(); });
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onRewardedAdFailed(JNIEnv *, jobject, jint ErrorCode)
{
    AsyncTask(ENamedThreads::GameThread, [ErrorCode]()
              { UAdMobShowRewardedCallback::HandleRewardAdFailed(); });
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onRewardEarned(JNIEnv *Env, jobject, jint Amount, jstring Type)
{
    const char *RawStr = nullptr;
    FString RewardType;

    if (Type != nullptr)
    {
        RawStr = Env->GetStringUTFChars(Type, nullptr);
        if (RawStr)
        {
            RewardType = UTF8_TO_TCHAR(RawStr);
            Env->ReleaseStringUTFChars(Type, RawStr);
        }
    }

    const int32 Amount32 = static_cast<int32>(Amount);

    UE_LOG(LogTemp, Warning, TEXT("[AdMob] Reward Earned from JNI: %d %s"), Amount32, *RewardType);

    AsyncTask(ENamedThreads::GameThread, [Amount32, RewardType]()
              { UAdMobShowRewardedCallback::HandleRewardEarned(Amount32, RewardType); });
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onBannerLoaded(JNIEnv *, jobject)
{
    AsyncTask(ENamedThreads::GameThread, []()
              { UAdMobLoadBannerCallback::HandleSuccess(); });
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onBannerLoadFailed(JNIEnv *, jobject, jint ErrorCode)
{
    AsyncTask(ENamedThreads::GameThread, [ErrorCode]()
              { UAdMobLoadBannerCallback::HandleFailed(); });
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onRewardedInterstitialLoadSuccess(JNIEnv *, jobject)
{
    AsyncTask(ENamedThreads::GameThread, []()
              { UAdMobFunctions::AdMob_ShowRewardedInterstitial(); });
}
extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onRewardedInterstitialFailed(JNIEnv *, jobject, jint ErrorCode)
{
    AsyncTask(ENamedThreads::GameThread, [ErrorCode]()
              { UAdmobRewardedInterstitialCallback::HandleInterstitialRewardAdFailed(); });
}
extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onRewardedInterstitialEarned(JNIEnv *Env, jobject, jint Amount, jstring Type)
{
    const char *RawStr = nullptr;
    FString RewardType;

    if (Type != nullptr)
    {
        RawStr = Env->GetStringUTFChars(Type, nullptr);
        if (RawStr)
        {
            RewardType = UTF8_TO_TCHAR(RawStr);
            Env->ReleaseStringUTFChars(Type, RawStr);
        }
    }

    const int32 Amount32 = static_cast<int32>(Amount);

    UE_LOG(LogTemp, Warning, TEXT("[AdMob] Reward Earned from Rewarded Interstitial JNI: %d %s"), Amount32, *RewardType);

    AsyncTask(ENamedThreads::GameThread, [Amount32, RewardType]()
              { UAdmobRewardedInterstitialCallback::HandleInterstitialRewardEarned(Amount32, RewardType); });
}
extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onInterstitialLoadSuccess(JNIEnv *, jobject)
{
    AsyncTask(ENamedThreads::GameThread, []()
              { UAdMobFunctions::AdMob_ShowInterstitial(); });
}
extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onInterstitialFailed(JNIEnv *, jobject, jint ErrorCode)
{
    AsyncTask(ENamedThreads::GameThread, [ErrorCode]()
              { UAdmobInterstitialCallback::HandleInterstitialAdFailed(); });
}
extern "C" JNIEXPORT void JNICALL
Java_com_google_admob_AdMobManager_onInterstitialCompleted(JNIEnv *, jobject)
{
    AsyncTask(ENamedThreads::GameThread, []()
              { UAdmobInterstitialCallback::HandleInterstitialAdCompleted(); });
}
#endif