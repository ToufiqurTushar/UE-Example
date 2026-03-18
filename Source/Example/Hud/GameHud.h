#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHud.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLE_API AGameHud : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
