#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AdmobExampleGameInstance.generated.h"

/**
 * Custom GameInstance to handle early application startup logic, similar to Flutter's runApp.
 */
UCLASS()
class ADMOBEXAMPLE_API UAdmobExampleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
};
