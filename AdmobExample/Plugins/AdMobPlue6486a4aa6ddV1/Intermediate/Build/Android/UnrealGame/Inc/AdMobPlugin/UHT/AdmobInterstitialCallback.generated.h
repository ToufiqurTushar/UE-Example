// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AdmobInterstitialCallback.h"

#ifdef ADMOBPLUGIN_AdmobInterstitialCallback_generated_h
#error "AdmobInterstitialCallback.generated.h already included, missing '#pragma once' in AdmobInterstitialCallback.h"
#endif
#define ADMOBPLUGIN_AdmobInterstitialCallback_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAdmobInterstitialCallback;

// ********** Begin Delegate FAdMobInterstitialCompleted *******************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_9_DELEGATE \
ADMOBPLUGIN_API void FAdMobInterstitialCompleted_DelegateWrapper(const FMulticastScriptDelegate& AdMobInterstitialCompleted);


// ********** End Delegate FAdMobInterstitialCompleted *********************************************

// ********** Begin Delegate FAdMobInterstitialFailed **********************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_10_DELEGATE \
ADMOBPLUGIN_API void FAdMobInterstitialFailed_DelegateWrapper(const FMulticastScriptDelegate& AdMobInterstitialFailed);


// ********** End Delegate FAdMobInterstitialFailed ************************************************

// ********** Begin Class UAdmobInterstitialCallback ***********************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execWatchInterstitialAd);


struct Z_Construct_UClass_UAdmobInterstitialCallback_Statics;
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdmobInterstitialCallback_NoRegister();

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdmobInterstitialCallback(); \
	friend struct ::Z_Construct_UClass_UAdmobInterstitialCallback_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ADMOBPLUGIN_API UClass* ::Z_Construct_UClass_UAdmobInterstitialCallback_NoRegister(); \
public: \
	DECLARE_CLASS2(UAdmobInterstitialCallback, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdMobPlugin"), Z_Construct_UClass_UAdmobInterstitialCallback_NoRegister) \
	DECLARE_SERIALIZER(UAdmobInterstitialCallback)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdmobInterstitialCallback(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAdmobInterstitialCallback(UAdmobInterstitialCallback&&) = delete; \
	UAdmobInterstitialCallback(const UAdmobInterstitialCallback&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdmobInterstitialCallback); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdmobInterstitialCallback); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdmobInterstitialCallback) \
	NO_API virtual ~UAdmobInterstitialCallback();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_12_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_15_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAdmobInterstitialCallback;

// ********** End Class UAdmobInterstitialCallback *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
