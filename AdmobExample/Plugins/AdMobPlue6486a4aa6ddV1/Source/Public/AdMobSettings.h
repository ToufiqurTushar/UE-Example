// Copyright (c) 2025 Loko. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AdMobSettings.generated.h"

UCLASS(Config = Engine, DefaultConfig, meta = (DisplayName = "AdMob Settings"))
class UAdMobSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    // AppID
    UPROPERTY(EditAnywhere, Config, Category = "AdMob")
    FString AppID;
};
