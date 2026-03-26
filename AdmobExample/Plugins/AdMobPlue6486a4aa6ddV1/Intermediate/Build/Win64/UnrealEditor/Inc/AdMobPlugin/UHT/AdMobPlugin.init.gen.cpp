// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdMobPlugin_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature();
	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature();
	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature();
	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature();
	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialRewardedCompleted__DelegateSignature();
	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialRewardedFailed__DelegateSignature();
	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature();
	ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_AdMobPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_AdMobPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_AdMobPlugin.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialRewardedCompleted__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialRewardedFailed__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/AdMobPlugin",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xDE5436F4,
			0x72DD9801,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_AdMobPlugin.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_AdMobPlugin.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_AdMobPlugin(Z_Construct_UPackage__Script_AdMobPlugin, TEXT("/Script/AdMobPlugin"), Z_Registration_Info_UPackage__Script_AdMobPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xDE5436F4, 0x72DD9801));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
