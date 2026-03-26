// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AdMobFunctions.h"

#ifdef ADMOBPLUGIN_AdMobFunctions_generated_h
#error "AdMobFunctions.generated.h already included, missing '#pragma once' in AdMobFunctions.h"
#endif
#define ADMOBPLUGIN_AdMobFunctions_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UAdMobFunctions **********************************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAdMob_ShowInterstitial); \
	DECLARE_FUNCTION(execAdMob_LoadInterstitial); \
	DECLARE_FUNCTION(execAdMob_ShowRewardedInterstitial); \
	DECLARE_FUNCTION(execAdMob_LoadRewardedInterstitial); \
	DECLARE_FUNCTION(execAdMob_IsBannerLoaded); \
	DECLARE_FUNCTION(execAdMob_HideBanner); \
	DECLARE_FUNCTION(execAdMob_ShowBanner); \
	DECLARE_FUNCTION(execAdMob_WatchBanner); \
	DECLARE_FUNCTION(execAdMob_IsRewardedLoaded); \
	DECLARE_FUNCTION(execAdMob_ShowRewarded); \
	DECLARE_FUNCTION(execAdMob_WatchRewarded);


struct Z_Construct_UClass_UAdMobFunctions_Statics;
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobFunctions_NoRegister();

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdMobFunctions(); \
	friend struct ::Z_Construct_UClass_UAdMobFunctions_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ADMOBPLUGIN_API UClass* ::Z_Construct_UClass_UAdMobFunctions_NoRegister(); \
public: \
	DECLARE_CLASS2(UAdMobFunctions, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdMobPlugin"), Z_Construct_UClass_UAdMobFunctions_NoRegister) \
	DECLARE_SERIALIZER(UAdMobFunctions)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdMobFunctions(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAdMobFunctions(UAdMobFunctions&&) = delete; \
	UAdMobFunctions(const UAdMobFunctions&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdMobFunctions); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdMobFunctions); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdMobFunctions) \
	NO_API virtual ~UAdMobFunctions();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_7_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_10_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAdMobFunctions;

// ********** End Class UAdMobFunctions ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
