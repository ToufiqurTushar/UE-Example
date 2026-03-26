// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AdMobShowRewardedCallback.h"

#ifdef ADMOBPLUGIN_AdMobShowRewardedCallback_generated_h
#error "AdMobShowRewardedCallback.generated.h already included, missing '#pragma once' in AdMobShowRewardedCallback.h"
#endif
#define ADMOBPLUGIN_AdMobShowRewardedCallback_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAdMobShowRewardedCallback;

// ********** Begin Delegate FAdMobRewardedCompleted ***********************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_11_DELEGATE \
ADMOBPLUGIN_API void FAdMobRewardedCompleted_DelegateWrapper(const FMulticastScriptDelegate& AdMobRewardedCompleted, int32 Amount, const FString& Type);


// ********** End Delegate FAdMobRewardedCompleted *************************************************

// ********** Begin Delegate FAdMobRewardedFailed **************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_13_DELEGATE \
ADMOBPLUGIN_API void FAdMobRewardedFailed_DelegateWrapper(const FMulticastScriptDelegate& AdMobRewardedFailed);


// ********** End Delegate FAdMobRewardedFailed ****************************************************

// ********** Begin Class UAdMobShowRewardedCallback ***********************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execWatchRewardedAd);


struct Z_Construct_UClass_UAdMobShowRewardedCallback_Statics;
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobShowRewardedCallback_NoRegister();

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdMobShowRewardedCallback(); \
	friend struct ::Z_Construct_UClass_UAdMobShowRewardedCallback_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ADMOBPLUGIN_API UClass* ::Z_Construct_UClass_UAdMobShowRewardedCallback_NoRegister(); \
public: \
	DECLARE_CLASS2(UAdMobShowRewardedCallback, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdMobPlugin"), Z_Construct_UClass_UAdMobShowRewardedCallback_NoRegister) \
	DECLARE_SERIALIZER(UAdMobShowRewardedCallback)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdMobShowRewardedCallback(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAdMobShowRewardedCallback(UAdMobShowRewardedCallback&&) = delete; \
	UAdMobShowRewardedCallback(const UAdMobShowRewardedCallback&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdMobShowRewardedCallback); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdMobShowRewardedCallback); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdMobShowRewardedCallback) \
	NO_API virtual ~UAdMobShowRewardedCallback();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_15_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_18_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAdMobShowRewardedCallback;

// ********** End Class UAdMobShowRewardedCallback *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
