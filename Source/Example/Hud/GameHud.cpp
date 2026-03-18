#include "GameHud.h"
#include "Example/Page/Splash/SplashPage.h"
#include "Blueprint/UserWidget.h"

void AGameHud::BeginPlay() {
	Super::BeginPlay();

	auto* SplashPage = CreateWidget<UUserWidget>(GetWorld(), USplashPage::StaticClass());
	if (SplashPage)
	{
		SplashPage->AddToViewport();
	}
}
