#include "ExampleGameModeBase.h"

#include "../UI/AdmobUserWidget.h"
#include "Blueprint/UserWidget.h"

void AExampleGameModeBase::BeginPlay() {
	Super::BeginPlay();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		auto* AdmobWidgetInstance = CreateWidget<UUserWidget>(PC, UAdmobUserWidget::StaticClass());
		if (AdmobWidgetInstance)
		{
			AdmobWidgetInstance->AddToViewport();
		}
	}
}