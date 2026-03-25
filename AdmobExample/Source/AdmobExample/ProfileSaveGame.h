#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ProfileSaveGame.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UProfileSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    UProfileSaveGame();

    UPROPERTY(VisibleAnywhere, Category = "Profile")
    FString UserName;

    UPROPERTY(VisibleAnywhere, Category = "Profile")
    FString UserEmail;

    UPROPERTY(VisibleAnywhere, Category = "Profile")
    FString UserBio;

    UPROPERTY(VisibleAnywhere, Category = "Profile")
    FString SaveSlotName;

    UPROPERTY(VisibleAnywhere, Category = "Profile")
    uint32 UserIndex;
};
