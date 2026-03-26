// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AdmobRewardedInterstitialCallback.h"

#ifdef ADMOBPLUGIN_AdmobRewardedInterstitialCallback_generated_h
#error "AdmobRewardedInterstitialCallback.generated.h already included, missing '#pragma once' in AdmobRewardedInterstitialCallback.h"
#endif
#define ADMOBPLUGIN_AdmobRewardedInterstitialCallback_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAdmobRewardedInterstitialCallback;

// ********** Begin Delegate FAdMobInterstitialRewardedCompleted ***********************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_11_DELEGATE \
ADMOBPLUGIN_API void FAdMobInterstitialRewardedCompleted_DelegateWrapper(const FMulticastScriptDelegate& AdMobInterstitialRewardedCompleted, int32 Amount, const FString& Type);


// ********** End Delegate FAdMobInterstitialRewardedCompleted *************************************

// ********** Begin Delegate FAdMobInterstitialRewardedFailed **************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_13_DELEGATE \
ADMOBPLUGIN_API void FAdMobInterstitialRewardedFailed_DelegateWrapper(const FMulticastScriptDelegate& AdMobInterstitialRewardedFailed);


// ********** End Delegate FAdMobInterstitialRewardedFailed ****************************************

// ********** Begin Class UAdmobRewardedInterstitialCallback ***************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execWatchRewardedInterstitialAd);


struct Z_Construct_UClass_UAdmobRewardedInterstitialCallback_Statics;
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdmobRewardedInterstitialCallback_NoRegister();

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdmobRewardedInterstitialCallback(); \
	friend struct ::Z_Construct_UClass_UAdmobRewardedInterstitialCallback_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ADMOBPLUGIN_API UClass* ::Z_Construct_UClass_UAdmobRewardedInterstitialCallback_NoRegister(); \
public: \
	DECLARE_CLASS2(UAdmobRewardedInterstitialCallback, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdMobPlugin"), Z_Construct_UClass_UAdmobRewardedInterstitialCallback_NoRegister) \
	DECLARE_SERIALIZER(UAdmobRewardedInterstitialCallback)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdmobRewardedInterstitialCallback(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAdmobRewardedInterstitialCallback(UAdmobRewardedInterstitialCallback&&) = delete; \
	UAdmobRewardedInterstitialCallback(const UAdmobRewardedInterstitialCallback&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdmobRewardedInterstitialCallback); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdmobRewardedInterstitialCallback); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdmobRewardedInterstitialCallback) \
	NO_API virtual ~UAdmobRewardedInterstitialCallback();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_15_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_18_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAdmobRewardedInterstitialCallback;

// ********** End Class UAdmobRewardedInterstitialCallback *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobRewardedInterstitialCallback_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
