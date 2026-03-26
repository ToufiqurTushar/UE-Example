// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdMobFunctions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAdMobFunctions() {}

// ********** Begin Cross Module References ********************************************************
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobFunctions();
ADMOBPLUGIN_API UClass* Z_Construct_UClass_UAdMobFunctions_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_AdMobPlugin();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAdMobFunctions Function AdMob_HideBanner ********************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_HideBanner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_HideBanner constinit property declarations **********************
// ********** End Function AdMob_HideBanner constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_HideBanner_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_HideBanner", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_HideBanner_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_HideBanner_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_HideBanner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_HideBanner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_HideBanner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_HideBanner();
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_HideBanner **********************************

// ********** Begin Class UAdMobFunctions Function AdMob_IsBannerLoaded ****************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics
{
	struct AdMobFunctions_eventAdMob_IsBannerLoaded_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_IsBannerLoaded constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AdMob_IsBannerLoaded constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AdMob_IsBannerLoaded Property Definitions *****************************
void Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AdMobFunctions_eventAdMob_IsBannerLoaded_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AdMobFunctions_eventAdMob_IsBannerLoaded_Parms), &Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::PropPointers) < 2048);
// ********** End Function AdMob_IsBannerLoaded Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_IsBannerLoaded", 	Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::AdMobFunctions_eventAdMob_IsBannerLoaded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::AdMobFunctions_eventAdMob_IsBannerLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_IsBannerLoaded)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAdMobFunctions::AdMob_IsBannerLoaded();
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_IsBannerLoaded ******************************

// ********** Begin Class UAdMobFunctions Function AdMob_IsRewardedLoaded **************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics
{
	struct AdMobFunctions_eventAdMob_IsRewardedLoaded_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_IsRewardedLoaded constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AdMob_IsRewardedLoaded constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AdMob_IsRewardedLoaded Property Definitions ***************************
void Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AdMobFunctions_eventAdMob_IsRewardedLoaded_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AdMobFunctions_eventAdMob_IsRewardedLoaded_Parms), &Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::PropPointers) < 2048);
// ********** End Function AdMob_IsRewardedLoaded Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_IsRewardedLoaded", 	Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::AdMobFunctions_eventAdMob_IsRewardedLoaded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::AdMobFunctions_eventAdMob_IsRewardedLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_IsRewardedLoaded)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAdMobFunctions::AdMob_IsRewardedLoaded();
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_IsRewardedLoaded ****************************

// ********** Begin Class UAdMobFunctions Function AdMob_LoadInterstitial **************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics
{
	struct AdMobFunctions_eventAdMob_LoadInterstitial_Parms
	{
		FString AdUnitID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdUnitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_LoadInterstitial constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdUnitID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AdMob_LoadInterstitial constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AdMob_LoadInterstitial Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::NewProp_AdUnitID = { "AdUnitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobFunctions_eventAdMob_LoadInterstitial_Parms, AdUnitID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdUnitID_MetaData), NewProp_AdUnitID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::NewProp_AdUnitID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::PropPointers) < 2048);
// ********** End Function AdMob_LoadInterstitial Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_LoadInterstitial", 	Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::AdMobFunctions_eventAdMob_LoadInterstitial_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::AdMobFunctions_eventAdMob_LoadInterstitial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_LoadInterstitial)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdUnitID);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_LoadInterstitial(Z_Param_AdUnitID);
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_LoadInterstitial ****************************

// ********** Begin Class UAdMobFunctions Function AdMob_LoadRewardedInterstitial ******************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics
{
	struct AdMobFunctions_eventAdMob_LoadRewardedInterstitial_Parms
	{
		FString AdUnitID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdUnitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_LoadRewardedInterstitial constinit property declarations ********
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdUnitID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AdMob_LoadRewardedInterstitial constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AdMob_LoadRewardedInterstitial Property Definitions *******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::NewProp_AdUnitID = { "AdUnitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobFunctions_eventAdMob_LoadRewardedInterstitial_Parms, AdUnitID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdUnitID_MetaData), NewProp_AdUnitID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::NewProp_AdUnitID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::PropPointers) < 2048);
// ********** End Function AdMob_LoadRewardedInterstitial Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_LoadRewardedInterstitial", 	Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::AdMobFunctions_eventAdMob_LoadRewardedInterstitial_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::AdMobFunctions_eventAdMob_LoadRewardedInterstitial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_LoadRewardedInterstitial)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdUnitID);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_LoadRewardedInterstitial(Z_Param_AdUnitID);
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_LoadRewardedInterstitial ********************

// ********** Begin Class UAdMobFunctions Function AdMob_ShowBanner ********************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowBanner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_ShowBanner constinit property declarations **********************
// ********** End Function AdMob_ShowBanner constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowBanner_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_ShowBanner", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowBanner_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowBanner_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowBanner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowBanner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_ShowBanner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_ShowBanner();
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_ShowBanner **********************************

// ********** Begin Class UAdMobFunctions Function AdMob_ShowInterstitial **************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowInterstitial_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_ShowInterstitial constinit property declarations ****************
// ********** End Function AdMob_ShowInterstitial constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowInterstitial_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_ShowInterstitial", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowInterstitial_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowInterstitial_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowInterstitial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowInterstitial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_ShowInterstitial)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_ShowInterstitial();
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_ShowInterstitial ****************************

// ********** Begin Class UAdMobFunctions Function AdMob_ShowRewarded ******************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewarded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_ShowRewarded constinit property declarations ********************
// ********** End Function AdMob_ShowRewarded constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewarded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_ShowRewarded", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewarded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewarded_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewarded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewarded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_ShowRewarded)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_ShowRewarded();
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_ShowRewarded ********************************

// ********** Begin Class UAdMobFunctions Function AdMob_ShowRewardedInterstitial ******************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewardedInterstitial_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_ShowRewardedInterstitial constinit property declarations ********
// ********** End Function AdMob_ShowRewardedInterstitial constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewardedInterstitial_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_ShowRewardedInterstitial", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewardedInterstitial_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewardedInterstitial_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewardedInterstitial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewardedInterstitial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_ShowRewardedInterstitial)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_ShowRewardedInterstitial();
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_ShowRewardedInterstitial ********************

// ********** Begin Class UAdMobFunctions Function AdMob_WatchBanner *******************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics
{
	struct AdMobFunctions_eventAdMob_WatchBanner_Parms
	{
		FString AdUnitID;
		bool bIsAdaptive;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdUnitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_WatchBanner constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdUnitID;
	static void NewProp_bIsAdaptive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAdaptive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AdMob_WatchBanner constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AdMob_WatchBanner Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::NewProp_AdUnitID = { "AdUnitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobFunctions_eventAdMob_WatchBanner_Parms, AdUnitID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdUnitID_MetaData), NewProp_AdUnitID_MetaData) };
void Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::NewProp_bIsAdaptive_SetBit(void* Obj)
{
	((AdMobFunctions_eventAdMob_WatchBanner_Parms*)Obj)->bIsAdaptive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::NewProp_bIsAdaptive = { "bIsAdaptive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AdMobFunctions_eventAdMob_WatchBanner_Parms), &Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::NewProp_bIsAdaptive_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::NewProp_AdUnitID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::NewProp_bIsAdaptive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::PropPointers) < 2048);
// ********** End Function AdMob_WatchBanner Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_WatchBanner", 	Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::AdMobFunctions_eventAdMob_WatchBanner_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::AdMobFunctions_eventAdMob_WatchBanner_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_WatchBanner)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdUnitID);
	P_GET_UBOOL(Z_Param_bIsAdaptive);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_WatchBanner(Z_Param_AdUnitID,Z_Param_bIsAdaptive);
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_WatchBanner *********************************

// ********** Begin Class UAdMobFunctions Function AdMob_WatchRewarded *****************************
struct Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics
{
	struct AdMobFunctions_eventAdMob_WatchRewarded_Parms
	{
		FString AdUnitID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdUnitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdMob_WatchRewarded constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdUnitID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AdMob_WatchRewarded constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AdMob_WatchRewarded Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::NewProp_AdUnitID = { "AdUnitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdMobFunctions_eventAdMob_WatchRewarded_Parms, AdUnitID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdUnitID_MetaData), NewProp_AdUnitID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::NewProp_AdUnitID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::PropPointers) < 2048);
// ********** End Function AdMob_WatchRewarded Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdMobFunctions, nullptr, "AdMob_WatchRewarded", 	Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::AdMobFunctions_eventAdMob_WatchRewarded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::AdMobFunctions_eventAdMob_WatchRewarded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAdMobFunctions::execAdMob_WatchRewarded)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdUnitID);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAdMobFunctions::AdMob_WatchRewarded(Z_Param_AdUnitID);
	P_NATIVE_END;
}
// ********** End Class UAdMobFunctions Function AdMob_WatchRewarded *******************************

// ********** Begin Class UAdMobFunctions **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAdMobFunctions;
UClass* UAdMobFunctions::GetPrivateStaticClass()
{
	using TClass = UAdMobFunctions;
	if (!Z_Registration_Info_UClass_UAdMobFunctions.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AdMobFunctions"),
			Z_Registration_Info_UClass_UAdMobFunctions.InnerSingleton,
			StaticRegisterNativesUAdMobFunctions,
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
	return Z_Registration_Info_UClass_UAdMobFunctions.InnerSingleton;
}
UClass* Z_Construct_UClass_UAdMobFunctions_NoRegister()
{
	return UAdMobFunctions::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAdMobFunctions_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AdMobFunctions.h" },
		{ "ModuleRelativePath", "Public/AdMobFunctions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAdMobFunctions constinit property declarations **************************
// ********** End Class UAdMobFunctions constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AdMob_HideBanner"), .Pointer = &UAdMobFunctions::execAdMob_HideBanner },
		{ .NameUTF8 = UTF8TEXT("AdMob_IsBannerLoaded"), .Pointer = &UAdMobFunctions::execAdMob_IsBannerLoaded },
		{ .NameUTF8 = UTF8TEXT("AdMob_IsRewardedLoaded"), .Pointer = &UAdMobFunctions::execAdMob_IsRewardedLoaded },
		{ .NameUTF8 = UTF8TEXT("AdMob_LoadInterstitial"), .Pointer = &UAdMobFunctions::execAdMob_LoadInterstitial },
		{ .NameUTF8 = UTF8TEXT("AdMob_LoadRewardedInterstitial"), .Pointer = &UAdMobFunctions::execAdMob_LoadRewardedInterstitial },
		{ .NameUTF8 = UTF8TEXT("AdMob_ShowBanner"), .Pointer = &UAdMobFunctions::execAdMob_ShowBanner },
		{ .NameUTF8 = UTF8TEXT("AdMob_ShowInterstitial"), .Pointer = &UAdMobFunctions::execAdMob_ShowInterstitial },
		{ .NameUTF8 = UTF8TEXT("AdMob_ShowRewarded"), .Pointer = &UAdMobFunctions::execAdMob_ShowRewarded },
		{ .NameUTF8 = UTF8TEXT("AdMob_ShowRewardedInterstitial"), .Pointer = &UAdMobFunctions::execAdMob_ShowRewardedInterstitial },
		{ .NameUTF8 = UTF8TEXT("AdMob_WatchBanner"), .Pointer = &UAdMobFunctions::execAdMob_WatchBanner },
		{ .NameUTF8 = UTF8TEXT("AdMob_WatchRewarded"), .Pointer = &UAdMobFunctions::execAdMob_WatchRewarded },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_HideBanner, "AdMob_HideBanner" }, // 3457147967
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_IsBannerLoaded, "AdMob_IsBannerLoaded" }, // 3544905692
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_IsRewardedLoaded, "AdMob_IsRewardedLoaded" }, // 1088014404
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadInterstitial, "AdMob_LoadInterstitial" }, // 1378862643
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_LoadRewardedInterstitial, "AdMob_LoadRewardedInterstitial" }, // 2249547941
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowBanner, "AdMob_ShowBanner" }, // 4144489742
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowInterstitial, "AdMob_ShowInterstitial" }, // 1467961488
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewarded, "AdMob_ShowRewarded" }, // 23145027
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_ShowRewardedInterstitial, "AdMob_ShowRewardedInterstitial" }, // 3490236670
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchBanner, "AdMob_WatchBanner" }, // 4043204647
		{ &Z_Construct_UFunction_UAdMobFunctions_AdMob_WatchRewarded, "AdMob_WatchRewarded" }, // 3495621837
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdMobFunctions>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAdMobFunctions_Statics
UObject* (*const Z_Construct_UClass_UAdMobFunctions_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_AdMobPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobFunctions_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAdMobFunctions_Statics::ClassParams = {
	&UAdMobFunctions::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdMobFunctions_Statics::Class_MetaDataParams), Z_Construct_UClass_UAdMobFunctions_Statics::Class_MetaDataParams)
};
void UAdMobFunctions::StaticRegisterNativesUAdMobFunctions()
{
	UClass* Class = UAdMobFunctions::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAdMobFunctions_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAdMobFunctions()
{
	if (!Z_Registration_Info_UClass_UAdMobFunctions.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAdMobFunctions.OuterSingleton, Z_Construct_UClass_UAdMobFunctions_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAdMobFunctions.OuterSingleton;
}
UAdMobFunctions::UAdMobFunctions(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAdMobFunctions);
UAdMobFunctions::~UAdMobFunctions() {}
// ********** End Class UAdMobFunctions ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h__Script_AdMobPlugin_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAdMobFunctions, UAdMobFunctions::StaticClass, TEXT("UAdMobFunctions"), &Z_Registration_Info_UClass_UAdMobFunctions, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAdMobFunctions), 3266473121U) },
	};
}; // Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h__Script_AdMobPlugin_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h__Script_AdMobPlugin_907651129{
	TEXT("/Script/AdMobPlugin"),
	Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h__Script_AdMobPlugin_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AdMobPlugin_Source_Public_AdMobFunctions_h__Script_AdMobPlugin_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
