// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AdMobLoadBannerCallback.h"

#ifdef ADMOBPLUGIN_AdMobLoadBannerCallback_generated_h
#error "AdMobLoadBannerCallback.generated.h already included, missing '#pragma once' in AdMobLoadBannerCallback.h"
#endif
#define ADMOBPLUGIN_AdMobLoadBannerCallback_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAdMobLoadBannerCallback;

// ********** Begin Delegate FAdMobBannerLoadSuccess ***********************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_8_DELEGATE \
ADMOBPLUGIN_API void FAdMobBannerLoadSuccess_DelegateWrapper(const FMulticastScriptDelegate& AdMobBannerLoadSuccess);


// ********** End Delegate FAdMobBannerLoadSuccess *************************************************

// ********** Begin Delegate FAdMobBannerLoadFailed ************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_9_DELEGATE \
ADMOBPLUGIN_API void FAdMobBannerLoadFailed_DelegateWrapper(const FMulticastScriptDelegate& AdMobBannerLoadFailed);


// ********** End Delegate FAdMobBannerLoadFailed **************************************************

// ********** Begin Class UAdMobLoadBannerCallback *************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execWatchBannerAd);


struct Z_Construct_UClass_UAdMobLoadBannerCallback_Statics;
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobLoadBannerCallback_NoRegister();

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdMobLoadBannerCallback(); \
	friend struct ::Z_Construct_UClass_UAdMobLoadBannerCallback_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ADMOBPLUGIN_API UClass* ::Z_Construct_UClass_UAdMobLoadBannerCallback_NoRegister(); \
public: \
	DECLARE_CLASS2(UAdMobLoadBannerCallback, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdMobPlugin"), Z_Construct_UClass_UAdMobLoadBannerCallback_NoRegister) \
	DECLARE_SERIALIZER(UAdMobLoadBannerCallback)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdMobLoadBannerCallback(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAdMobLoadBannerCallback(UAdMobLoadBannerCallback&&) = delete; \
	UAdMobLoadBannerCallback(const UAdMobLoadBannerCallback&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdMobLoadBannerCallback); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdMobLoadBannerCallback); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdMobLoadBannerCallback) \
	NO_API virtual ~UAdMobLoadBannerCallback();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_11_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_14_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAdMobLoadBannerCallback;

// ********** End Class UAdMobLoadBannerCallback ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
