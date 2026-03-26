// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AdMobSettings.h"

#ifdef ADMOBPLUGIN_AdMobSettings_generated_h
#error "AdMobSettings.generated.h already included, missing '#pragma once' in AdMobSettings.h"
#endif
#define ADMOBPLUGIN_AdMobSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UAdMobSettings ***********************************************************
struct Z_Construct_UClass_UAdMobSettings_Statics;
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobSettings_NoRegister();

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAdMobSettings(); \
	friend struct ::Z_Construct_UClass_UAdMobSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ADMOBPLUGIN_API UClass* ::Z_Construct_UClass_UAdMobSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UAdMobSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdMobPlugin"), Z_Construct_UClass_UAdMobSettings_NoRegister) \
	DECLARE_SERIALIZER(UAdMobSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdMobSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAdMobSettings(UAdMobSettings&&) = delete; \
	UAdMobSettings(const UAdMobSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdMobSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdMobSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdMobSettings) \
	NO_API virtual ~UAdMobSettings();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h_8_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAdMobSettings;

// ********** End Class UAdMobSettings *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
