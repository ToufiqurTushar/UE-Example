// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdMobLoadBannerCallback.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAdMobLoadBannerCallback() {}

// ********** Begin Cross Module References ********************************************************
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobLoadBannerCallback();
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobLoadBannerCallback_NoRegister();
ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature();
ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
UPackage* Z_Construct_UPackage__Script_AdMobPlugin();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FAdMobBannerLoadSuccess ***********************************************
struct Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobLoadBannerCallback.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAdMobBannerLoadSuccess constinit property declarations ***************
// ********** End Delegate FAdMobBannerLoadSuccess constinit property declarations *****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AdMobPlugin, nullptr, "AdMobBannerLoadSuccess__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAdMobBannerLoadSuccess_DelegateWrapper(const FMulticastScriptDelegate& AdMobBannerLoadSuccess)
{
	AdMobBannerLoadSuccess.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FAdMobBannerLoadSuccess *************************************************

// ********** Begin Delegate FAdMobBannerLoadFailed ************************************************
struct Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobLoadBannerCallback.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAdMobBannerLoadFailed constinit property declarations ****************
// ********** End Delegate FAdMobBannerLoadFailed constinit property declarations ******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AdMobPlugin, nullptr, "AdMobBannerLoadFailed__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAdMobBannerLoadFailed_DelegateWrapper(const FMulticastScriptDelegate& AdMobBannerLoadFailed)
{
	AdMobBannerLoadFailed.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FAdMobBannerLoadFailed **************************************************

// ********** Begin Class UAdMobLoadBannerCallback Function WatchBannerAd **************************
struct Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics
{
	struct AdMobLoadBannerCallback_eventWatchBannerAd_Parms
	{
		FString AdUnitId;
		bool bIsAdaptive;
		UAdMobLoadBannerCallback* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "AdMob" },
		{ "DisplayName", "Show Banner Ad" },
		{ "ModuleRelativePath", "Public/AdMobLoadBannerCallback.h" },
		{ "ToolTip", "Loads and displays an AdMob Banner Ad. 'bIsAdaptive' enables adaptive banner sizing. Returns a callback object for banner load events." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdUnitId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function WatchBannerAd constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdUnitId;
	static void NewProp_bIsAdaptive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAdaptive;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WatchBannerAd constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WatchBannerAd Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_AdUnitId = { "AdUnitId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobLoadBannerCallback_eventWatchBannerAd_Parms, AdUnitId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdUnitId_MetaData), NewProp_AdUnitId_MetaData) };
void Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_bIsAdaptive_SetBit(void* Obj)
{
	((AdMobLoadBannerCallback_eventWatchBannerAd_Parms*)Obj)->bIsAdaptive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_bIsAdaptive = { "bIsAdaptive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AdMobLoadBannerCallback_eventWatchBannerAd_Parms), &Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_bIsAdaptive_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobLoadBannerCallback_eventWatchBannerAd_Parms, ReturnValue), Z_Construct_UClass_UAdMobLoadBannerCallback_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_AdUnitId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_bIsAdaptive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::PropPointers) < 2048);
// ********** End Function WatchBannerAd Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobLoadBannerCallback, nullptr, "WatchBannerAd", 	Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::AdMobLoadBannerCallback_eventWatchBannerAd_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::AdMobLoadBannerCallback_eventWatchBannerAd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobLoadBannerCallback::execWatchBannerAd)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdUnitId);
	P_GET_UBOOL(Z_Param_bIsAdaptive);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAdMobLoadBannerCallback**)Z_Param__Result=UAdMobLoadBannerCallback::WatchBannerAd(Z_Param_AdUnitId,Z_Param_bIsAdaptive);
	P_NATIVE_END;
}
// ********** End Class UAdMobLoadBannerCallback Function WatchBannerAd ****************************

// ********** Begin Class UAdMobLoadBannerCallback *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAdMobLoadBannerCallback;
UClass* UAdMobLoadBannerCallback::GetPrivateStaticClass()
{
	using TClass = UAdMobLoadBannerCallback;
	if (!Z_Registration_Info_UClass_UAdMobLoadBannerCallback.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AdMobLoadBannerCallback"),
			Z_Registration_Info_UClass_UAdMobLoadBannerCallback.InnerSingleton,
			StaticRegisterNativesUAdMobLoadBannerCallback,
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
	return Z_Registration_Info_UClass_UAdMobLoadBannerCallback.InnerSingleton;
}
UClass* Z_Construct_UClass_UAdMobLoadBannerCallback_NoRegister()
{
	return UAdMobLoadBannerCallback::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAdMobLoadBannerCallback_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AdMobLoadBannerCallback.h" },
		{ "ModuleRelativePath", "Public/AdMobLoadBannerCallback.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[] = {
		{ "Category", "AdMob" },
		{ "ModuleRelativePath", "Public/AdMobLoadBannerCallback.h" },
		{ "ToolTip", "Triggered when a Banner Ad finishes loading successfully." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFailed_MetaData[] = {
		{ "Category", "AdMob" },
		{ "ModuleRelativePath", "Public/AdMobLoadBannerCallback.h" },
		{ "ToolTip", "Triggered when a Banner Ad fails to load." },
	};
#endif // WITH_METADATA

// ********** Begin Class UAdMobLoadBannerCallback constinit property declarations *****************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFailed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAdMobLoadBannerCallback constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("WatchBannerAd"), .Pointer = &UAdMobLoadBannerCallback::execWatchBannerAd },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdMobLoadBannerCallback_WatchBannerAd, "WatchBannerAd" }, // 971548186
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdMobLoadBannerCallback>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAdMobLoadBannerCallback_Statics

// ********** Begin Class UAdMobLoadBannerCallback Property Definitions ****************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdMobLoadBannerCallback, OnSuccess), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadSuccess__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSuccess_MetaData), NewProp_OnSuccess_MetaData) }; // 1924201814
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::NewProp_OnFailed = { "OnFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdMobLoadBannerCallback, OnFailed), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobBannerLoadFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFailed_MetaData), NewProp_OnFailed_MetaData) }; // 3650438643
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::NewProp_OnFailed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::PropPointers) < 2048);
// ********** End Class UAdMobLoadBannerCallback Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AdMobPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::ClassParams = {
	&UAdMobLoadBannerCallback::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::Class_MetaDataParams), Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::Class_MetaDataParams)
};
void UAdMobLoadBannerCallback::StaticRegisterNativesUAdMobLoadBannerCallback()
{
	UClass* Class = UAdMobLoadBannerCallback::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAdMobLoadBannerCallback()
{
	if (!Z_Registration_Info_UClass_UAdMobLoadBannerCallback.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAdMobLoadBannerCallback.OuterSingleton, Z_Construct_UClass_UAdMobLoadBannerCallback_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAdMobLoadBannerCallback.OuterSingleton;
}
UAdMobLoadBannerCallback::UAdMobLoadBannerCallback(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAdMobLoadBannerCallback);
UAdMobLoadBannerCallback::~UAdMobLoadBannerCallback() {}
// ********** End Class UAdMobLoadBannerCallback ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h__Script_AdMobPlugin_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAdMobLoadBannerCallback, UAdMobLoadBannerCallback::StaticClass, TEXT("UAdMobLoadBannerCallback"), &Z_Registration_Info_UClass_UAdMobLoadBannerCallback, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAdMobLoadBannerCallback), 3484529393U) },
	};
}; // Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h__Script_AdMobPlugin_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h__Script_AdMobPlugin_2468134228{
	TEXT("/Script/AdMobPlugin"),
	Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h__Script_AdMobPlugin_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobLoadBannerCallback_h__Script_AdMobPlugin_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
