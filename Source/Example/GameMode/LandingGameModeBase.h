#pragma once
#include "GameFramework/GameModeBase.h"
#include "LandingGameModeBase.generated.h"

UCLASS()
class EXAMPLE_API ALandingGameModeBase : public AGameModeBase {
  GENERATED_BODY()
  
public:
  ALandingGameModeBase();

protected:
  virtual void BeginPlay() override;
};
