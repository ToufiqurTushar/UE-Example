// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdMobShowRewardedCallback.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAdMobShowRewardedCallback() {}

// ********** Begin Cross Module References ********************************************************
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobShowRewardedCallback();
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobShowRewardedCallback_NoRegister();
ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature();
ADMOBPLUGIN_API UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
UPackage* Z_Construct_UPackage__Script_AdMobPlugin();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FAdMobRewardedCompleted ***********************************************
struct Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics
{
	struct _Script_AdMobPlugin_eventAdMobRewardedCompleted_Parms
	{
		int32 Amount;
		FString Type;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobShowRewardedCallback.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAdMobRewardedCompleted constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Type;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FAdMobRewardedCompleted constinit property declarations *****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FAdMobRewardedCompleted Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_AdMobPlugin_eventAdMobRewardedCompleted_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_AdMobPlugin_eventAdMobRewardedCompleted_Parms, Type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::NewProp_Type,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FAdMobRewardedCompleted Property Definitions ****************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AdMobPlugin, nullptr, "AdMobRewardedCompleted__DelegateSignature", 	Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::_Script_AdMobPlugin_eventAdMobRewardedCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::_Script_AdMobPlugin_eventAdMobRewardedCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAdMobRewardedCompleted_DelegateWrapper(const FMulticastScriptDelegate& AdMobRewardedCompleted, int32 Amount, const FString& Type)
{
	struct _Script_AdMobPlugin_eventAdMobRewardedCompleted_Parms
	{
		int32 Amount;
		FString Type;
	};
	_Script_AdMobPlugin_eventAdMobRewardedCompleted_Parms Parms;
	Parms.Amount=Amount;
	Parms.Type=Type;
	AdMobRewardedCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FAdMobRewardedCompleted *************************************************

// ********** Begin Delegate FAdMobRewardedFailed **************************************************
struct Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobShowRewardedCallback.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAdMobRewardedFailed constinit property declarations ******************
// ********** End Delegate FAdMobRewardedFailed constinit property declarations ********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AdMobPlugin, nullptr, "AdMobRewardedFailed__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAdMobRewardedFailed_DelegateWrapper(const FMulticastScriptDelegate& AdMobRewardedFailed)
{
	AdMobRewardedFailed.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FAdMobRewardedFailed ****************************************************

// ********** Begin Class UAdMobShowRewardedCallback Function WatchRewardedAd **********************
struct Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics
{
	struct AdMobShowRewardedCallback_eventWatchRewardedAd_Parms
	{
		FString AdUnitID;
		UAdMobShowRewardedCallback* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "AdMob" },
		{ "DisplayName", "Show Rewarded Ad" },
		{ "ModuleRelativePath", "Public/AdMobShowRewardedCallback.h" },
		{ "ToolTip", "Displays a Rewarded Ad. Requires a valid Ad Unit ID. Returns a callback object for reward and ad lifecycle events." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdUnitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function WatchRewardedAd constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdUnitID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WatchRewardedAd constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WatchRewardedAd Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::NewProp_AdUnitID = { "AdUnitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobShowRewardedCallback_eventWatchRewardedAd_Parms, AdUnitID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdUnitID_MetaData), NewProp_AdUnitID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobShowRewardedCallback_eventWatchRewardedAd_Parms, ReturnValue), Z_Construct_UClass_UAdMobShowRewardedCallback_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::NewProp_AdUnitID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::PropPointers) < 2048);
// ********** End Function WatchRewardedAd Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobShowRewardedCallback, nullptr, "WatchRewardedAd", 	Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::AdMobShowRewardedCallback_eventWatchRewardedAd_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::AdMobShowRewardedCallback_eventWatchRewardedAd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobShowRewardedCallback::execWatchRewardedAd)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdUnitID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAdMobShowRewardedCallback**)Z_Param__Result=UAdMobShowRewardedCallback::WatchRewardedAd(Z_Param_AdUnitID);
	P_NATIVE_END;
}
// ********** End Class UAdMobShowRewardedCallback Function WatchRewardedAd ************************

// ********** Begin Class UAdMobShowRewardedCallback ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAdMobShowRewardedCallback;
UClass* UAdMobShowRewardedCallback::GetPrivateStaticClass()
{
	using TClass = UAdMobShowRewardedCallback;
	if (!Z_Registration_Info_UClass_UAdMobShowRewardedCallback.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AdMobShowRewardedCallback"),
			Z_Registration_Info_UClass_UAdMobShowRewardedCallback.InnerSingleton,
			StaticRegisterNativesUAdMobShowRewardedCallback,
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
	return Z_Registration_Info_UClass_UAdMobShowRewardedCallback.InnerSingleton;
}
UClass* Z_Construct_UClass_UAdMobShowRewardedCallback_NoRegister()
{
	return UAdMobShowRewardedCallback::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAdMobShowRewardedCallback_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AdMobShowRewardedCallback.h" },
		{ "ModuleRelativePath", "Public/AdMobShowRewardedCallback.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "Category", "AdMob" },
		{ "ModuleRelativePath", "Public/AdMobShowRewardedCallback.h" },
		{ "ToolTip", "Triggered when the user earns a reward from a Rewarded Ad." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFailed_MetaData[] = {
		{ "Category", "AdMob" },
		{ "ModuleRelativePath", "Public/AdMobShowRewardedCallback.h" },
		{ "ToolTip", "Triggered when a Rewarded Ad Faild to Load" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAdMobShowRewardedCallback constinit property declarations ***************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFailed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAdMobShowRewardedCallback constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("WatchRewardedAd"), .Pointer = &UAdMobShowRewardedCallback::execWatchRewardedAd },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdMobShowRewardedCallback_WatchRewardedAd, "WatchRewardedAd" }, // 2916895373
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdMobShowRewardedCallback>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAdMobShowRewardedCallback_Statics

// ********** Begin Class UAdMobShowRewardedCallback Property Definitions **************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdMobShowRewardedCallback, OnCompleted), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 3258226912
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::NewProp_OnFailed = { "OnFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdMobShowRewardedCallback, OnFailed), Z_Construct_UDelegateFunction_AdMobPlugin_AdMobRewardedFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFailed_MetaData), NewProp_OnFailed_MetaData) }; // 3139207767
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::NewProp_OnCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::NewProp_OnFailed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::PropPointers) < 2048);
// ********** End Class UAdMobShowRewardedCallback Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AdMobPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::ClassParams = {
	&UAdMobShowRewardedCallback::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::Class_MetaDataParams), Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::Class_MetaDataParams)
};
void UAdMobShowRewardedCallback::StaticRegisterNativesUAdMobShowRewardedCallback()
{
	UClass* Class = UAdMobShowRewardedCallback::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAdMobShowRewardedCallback()
{
	if (!Z_Registration_Info_UClass_UAdMobShowRewardedCallback.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAdMobShowRewardedCallback.OuterSingleton, Z_Construct_UClass_UAdMobShowRewardedCallback_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAdMobShowRewardedCallback.OuterSingleton;
}
UAdMobShowRewardedCallback::UAdMobShowRewardedCallback(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAdMobShowRewardedCallback);
UAdMobShowRewardedCallback::~UAdMobShowRewardedCallback() {}
// ********** End Class UAdMobShowRewardedCallback *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h__Script_AdMobPlugin_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAdMobShowRewardedCallback, UAdMobShowRewardedCallback::StaticClass, TEXT("UAdMobShowRewardedCallback"), &Z_Registration_Info_UClass_UAdMobShowRewardedCallback, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAdMobShowRewardedCallback), 1688069777U) },
	};
}; // Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h__Script_AdMobPlugin_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h__Script_AdMobPlugin_2017911666{
	TEXT("/Script/AdMobPlugin"),
	Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h__Script_AdMobPlugin_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobShowRewardedCallback_h__Script_AdMobPlugin_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
