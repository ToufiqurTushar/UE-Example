#include "LandingGameModeBase.h"
#include "Example/Hud/GameHud.h"

ALandingGameModeBase::ALandingGameModeBase()
{
    HUDClass = AGameHud::StaticClass();
}

void ALandingGameModeBase::BeginPlay() {
    Super::BeginPlay();
}
