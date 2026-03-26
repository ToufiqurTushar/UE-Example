// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdMobSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAdMobSettings() {}

// ********** Begin Cross Module References ********************************************************
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobSettings();
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobSettings_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
UPackage* Z_Construct_UPackage__Script_AdMobPlugin();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAdMobSettings ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAdMobSettings;
UClass* UAdMobSettings::GetPrivateStaticClass()
{
	using TClass = UAdMobSettings;
	if (!Z_Registration_Info_UClass_UAdMobSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AdMobSettings"),
			Z_Registration_Info_UClass_UAdMobSettings.InnerSingleton,
			StaticRegisterNativesUAdMobSettings,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UAdMobSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UAdMobSettings_NoRegister()
{
	return UAdMobSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAdMobSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "AdMob Settings" },
		{ "IncludePath", "AdMobSettings.h" },
		{ "ModuleRelativePath", "Public/AdMobSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppID_MetaData[] = {
		{ "Category", "AdMob" },
		{ "Comment", "// AppID\n" },
		{ "ModuleRelativePath", "Public/AdMobSettings.h" },
		{ "ToolTip", "AppID" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAdMobSettings constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AppID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAdMobSettings constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdMobSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAdMobSettings_Statics

// ********** Begin Class UAdMobSettings Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAdMobSettings_Statics::NewProp_AppID = { "AppID", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdMobSettings, AppID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppID_MetaData), NewProp_AppID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAdMobSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdMobSettings_Statics::NewProp_AppID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobSettings_Statics::PropPointers) < 2048);
// ********** End Class UAdMobSettings Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UAdMobSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_AdMobPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAdMobSettings_Statics::ClassParams = {
	&UAdMobSettings::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAdMobSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobSettings_Statics::PropPointers),
	0,
	0x000000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UAdMobSettings_Statics::Class_MetaDataParams)
};
void UAdMobSettings::StaticRegisterNativesUAdMobSettings()
{
}
UClass* Z_Construct_UClass_UAdMobSettings()
{
	if (!Z_Registration_Info_UClass_UAdMobSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAdMobSettings.OuterSingleton, Z_Construct_UClass_UAdMobSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAdMobSettings.OuterSingleton;
}
UAdMobSettings::UAdMobSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAdMobSettings);
UAdMobSettings::~UAdMobSettings() {}
// ********** End Class UAdMobSettings *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h__Script_AdMobPlugin_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAdMobSettings, UAdMobSettings::StaticClass, TEXT("UAdMobSettings"), &Z_Registration_Info_UClass_UAdMobSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAdMobSettings), 4249642431U) },
	};
}; // Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h__Script_AdMobPlugin_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h__Script_AdMobPlugin_3368736612{
	TEXT("/Script/AdMobPlugin"),
	Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h__Script_AdMobPlugin_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobSettings_h__Script_AdMobPlugin_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
