#include "ExampleGameModeBase.h"

#include "../UI/HomePageWidget.h"
#include "Blueprint/UserWidget.h"

void AExampleGameModeBase::BeginPlay() {
	Super::BeginPlay();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		auto* AdmobWidgetInstance = CreateWidget<UUserWidget>(PC, UHomePageWidget::StaticClass());
		if (AdmobWidgetInstance)
		{
			AdmobWidgetInstance->AddToViewport();
		}
	}
}