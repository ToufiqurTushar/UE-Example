#include "GoogleMobileAdsBPLibrary.h"
#include "Async/Async.h"

FOnUserEarnedRewardDelegate UGoogleMobileAdsBPLibrary::OnUserEarnedReward;

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeOnUserEarnedReward(JNIEnv* jenv, jobject thiz)
	{
		AsyncTask(ENamedThreads::GameThread, []() {
			UGoogleMobileAdsBPLibrary::OnUserEarnedReward.Broadcast();
		});
	}
#ifdef __cplusplus
}
#endif
#endif

#if PLATFORM_IOS
#include "IOS/GoogleMobileAdsIOS.h"
#endif

void UGoogleMobileAdsBPLibrary::InitializeAdMob()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jmethodID InitializeMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleMobileAds_Initialize", "()V", false);
		if (InitializeMethod)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, InitializeMethod);
		}
	}
#endif

#if PLATFORM_IOS
	FGoogleMobileAdsIOS::InitializeAdMob();
#endif
}

void UGoogleMobileAdsBPLibrary::LoadInterstitialAd(const FString& AdUnitID)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jAdUnitId = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
		jmethodID LoadMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleMobileAds_LoadInterstitial", "(Ljava/lang/String;)V", false);
		if (LoadMethod)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LoadMethod, jAdUnitId);
		}
		Env->DeleteLocalRef(jAdUnitId);
	}
#endif

#if PLATFORM_IOS
	FGoogleMobileAdsIOS::LoadInterstitialAd(AdUnitID);
#endif
}

void UGoogleMobileAdsBPLibrary::ShowInterstitialAd()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jmethodID ShowMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleMobileAds_ShowInterstitial", "()V", false);
		if (ShowMethod)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, ShowMethod);
		}
	}
#endif

#if PLATFORM_IOS
	FGoogleMobileAdsIOS::ShowInterstitialAd();
#endif
}

void UGoogleMobileAdsBPLibrary::LoadRewardedAd(const FString& AdUnitID)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jAdUnitId = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
		jmethodID LoadMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleMobileAds_LoadRewarded", "(Ljava/lang/String;)V", false);
		if (LoadMethod)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LoadMethod, jAdUnitId);
		}
		Env->DeleteLocalRef(jAdUnitId);
	}
#endif

#if PLATFORM_IOS
	FGoogleMobileAdsIOS::LoadRewardedAd(AdUnitID);
#endif
}

void UGoogleMobileAdsBPLibrary::ShowRewardedAd()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jmethodID ShowMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleMobileAds_ShowRewarded", "()V", false);
		if (ShowMethod)
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, ShowMethod);
		}
	}
#endif

#if PLATFORM_IOS
	FGoogleMobileAdsIOS::ShowRewardedAd();
#endif
}
