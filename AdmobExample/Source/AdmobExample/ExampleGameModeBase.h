// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ExampleGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ADMOBEXAMPLE_API AExampleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
    virtual void BeginPlay() override;
};
