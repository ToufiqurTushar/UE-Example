// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdmobInterstitialCallback.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAdmobInterstitialCallback() {}

// ********** Begin Cross Module References ********************************************************
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdmobInterstitialCallback();
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdmobInterstitialCallback_NoRegister();
ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature();
ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
UPackage* Z_Construct_UPackage__Script_AdMobPlugin();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FAdMobInterstitialCompleted *******************************************
struct Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdmobInterstitialCallback.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAdMobInterstitialCompleted constinit property declarations ***********
// ********** End Delegate FAdMobInterstitialCompleted constinit property declarations *************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AdMobPlugin, nullptr, "AdMobInterstitialCompleted__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAdMobInterstitialCompleted_DelegateWrapper(const FMulticastScriptDelegate& AdMobInterstitialCompleted)
{
	AdMobInterstitialCompleted.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FAdMobInterstitialCompleted *********************************************

// ********** Begin Delegate FAdMobInterstitialFailed **********************************************
struct Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdmobInterstitialCallback.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAdMobInterstitialFailed constinit property declarations **************
// ********** End Delegate FAdMobInterstitialFailed constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AdMobPlugin, nullptr, "AdMobInterstitialFailed__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAdMobInterstitialFailed_DelegateWrapper(const FMulticastScriptDelegate& AdMobInterstitialFailed)
{
	AdMobInterstitialFailed.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FAdMobInterstitialFailed ************************************************

// ********** Begin Class UAdmobInterstitialCallback Function WatchInterstitialAd ******************
struct Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics
{
	struct AdmobInterstitialCallback_eventWatchInterstitialAd_Parms
	{
		FString AdUnitID;
		UAdmobInterstitialCallback* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "AdMob" },
		{ "DisplayName", "Show Interstitial Ad" },
		{ "ModuleRelativePath", "Public/AdmobInterstitialCallback.h" },
		{ "ToolTip", "Displays an AdMob Interstitial Ad. Requires a valid Ad Unit ID.Returns a callback object for ad events." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdUnitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function WatchInterstitialAd constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdUnitID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WatchInterstitialAd constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WatchInterstitialAd Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::NewProp_AdUnitID = { "AdUnitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdmobInterstitialCallback_eventWatchInterstitialAd_Parms, AdUnitID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdUnitID_MetaData), NewProp_AdUnitID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdmobInterstitialCallback_eventWatchInterstitialAd_Parms, ReturnValue), Z_Construct_UClass_UAdmobInterstitialCallback_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::NewProp_AdUnitID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::PropPointers) < 2048);
// ********** End Function WatchInterstitialAd Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdmobInterstitialCallback, nullptr, "WatchInterstitialAd", 	Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::AdmobInterstitialCallback_eventWatchInterstitialAd_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::AdmobInterstitialCallback_eventWatchInterstitialAd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdmobInterstitialCallback::execWatchInterstitialAd)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdUnitID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAdmobInterstitialCallback**)Z_Param__Result=UAdmobInterstitialCallback::WatchInterstitialAd(Z_Param_AdUnitID);
	P_NATIVE_END;
}
// ********** End Class UAdmobInterstitialCallback Function WatchInterstitialAd ********************

// ********** Begin Class UAdmobInterstitialCallback ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAdmobInterstitialCallback;
UClass* UAdmobInterstitialCallback::GetPrivateStaticClass()
{
	using TClass = UAdmobInterstitialCallback;
	if (!Z_Registration_Info_UClass_UAdmobInterstitialCallback.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AdmobInterstitialCallback"),
			Z_Registration_Info_UClass_UAdmobInterstitialCallback.InnerSingleton,
			StaticRegisterNativesUAdmobInterstitialCallback,
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
	return Z_Registration_Info_UClass_UAdmobInterstitialCallback.InnerSingleton;
}
UClass* Z_Construct_UClass_UAdmobInterstitialCallback_NoRegister()
{
	return UAdmobInterstitialCallback::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAdmobInterstitialCallback_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AdmobInterstitialCallback.h" },
		{ "ModuleRelativePath", "Public/AdmobInterstitialCallback.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "Category", "AdMob" },
		{ "ModuleRelativePath", "Public/AdmobInterstitialCallback.h" },
		{ "ToolTip", "Triggered when an Interstitial Ad is closed after being displayed." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFailed_MetaData[] = {
		{ "Category", "AdMob" },
		{ "ModuleRelativePath", "Public/AdmobInterstitialCallback.h" },
		{ "ToolTip", "Triggered when an Interstitial Ad fails to load or show." },
	};
#endif // WITH_METADATA

// ********** Begin Class UAdmobInterstitialCallback constinit property declarations ***************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFailed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAdmobInterstitialCallback constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("WatchInterstitialAd"), .Pointer = &UAdmobInterstitialCallback::execWatchInterstitialAd },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdmobInterstitialCallback_WatchInterstitialAd, "WatchInterstitialAd" }, // 3665797405
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdmobInterstitialCallback>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAdmobInterstitialCallback_Statics

// ********** Begin Class UAdmobInterstitialCallback Property Definitions **************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdmobInterstitialCallback_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdmobInterstitialCallback, OnCompleted), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 2007818485
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdmobInterstitialCallback_Statics::NewProp_OnFailed = { "OnFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdmobInterstitialCallback, OnFailed), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobInterstitialFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFailed_MetaData), NewProp_OnFailed_MetaData) }; // 2630164477
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAdmobInterstitialCallback_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdmobInterstitialCallback_Statics::NewProp_OnCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdmobInterstitialCallback_Statics::NewProp_OnFailed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdmobInterstitialCallback_Statics::PropPointers) < 2048);
// ********** End Class UAdmobInterstitialCallback Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UAdmobInterstitialCallback_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AdMobPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdmobInterstitialCallback_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAdmobInterstitialCallback_Statics::ClassParams = {
	&UAdmobInterstitialCallback::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAdmobInterstitialCallback_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAdmobInterstitialCallback_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdmobInterstitialCallback_Statics::Class_MetaDataParams), Z_Construct_UClass_UAdmobInterstitialCallback_Statics::Class_MetaDataParams)
};
void UAdmobInterstitialCallback::StaticRegisterNativesUAdmobInterstitialCallback()
{
	UClass* Class = UAdmobInterstitialCallback::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAdmobInterstitialCallback_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAdmobInterstitialCallback()
{
	if (!Z_Registration_Info_UClass_UAdmobInterstitialCallback.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAdmobInterstitialCallback.OuterSingleton, Z_Construct_UClass_UAdmobInterstitialCallback_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAdmobInterstitialCallback.OuterSingleton;
}
UAdmobInterstitialCallback::UAdmobInterstitialCallback(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAdmobInterstitialCallback);
UAdmobInterstitialCallback::~UAdmobInterstitialCallback() {}
// ********** End Class UAdmobInterstitialCallback *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h__Script_AdMobPlugin_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAdmobInterstitialCallback, UAdmobInterstitialCallback::StaticClass, TEXT("UAdmobInterstitialCallback"), &Z_Registration_Info_UClass_UAdmobInterstitialCallback, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAdmobInterstitialCallback), 4123593744U) },
	};
}; // Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h__Script_AdMobPlugin_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h__Script_AdMobPlugin_2138853417{
	TEXT("/Script/AdMobPlugin"),
	Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h__Script_AdMobPlugin_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdmobInterstitialCallback_h__Script_AdMobPlugin_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
