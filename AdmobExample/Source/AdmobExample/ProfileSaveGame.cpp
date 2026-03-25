#include "ProfileSaveGame.h"

UProfileSaveGame::UProfileSaveGame()
{
    SaveSlotName = TEXT("ProfileSlot");
    UserIndex = 0;

    UserName = TEXT("Guest User");
    UserEmail = TEXT("guest@example.com");
    UserBio = TEXT("Hello! I am using the FlutterUMG plugin in Unreal Engine.");
}
