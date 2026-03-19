#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AdmobExampleGameInstance.generated.h"

class UAdmobUserWidget;
class UCanvasPanel;

/**
 * Custom GameInstance to handle early application startup logic, similar to Flutter's runApp.
 */
UCLASS()
class ADMOBEXAMPLE_API UAdmobExampleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UFUNCTION()
	void HandleAdMobInitializationComplete(bool bSuccess, const FString& ErrorMessage);

	void SetMainWidget(UAdmobUserWidget* InWidget, UCanvasPanel* InRoot) { MainWidget = InWidget; RootCanvas = InRoot; }
	void ShowToast(const FString& Message);

private:
	TWeakObjectPtr<UAdmobUserWidget> MainWidget;
	TWeakObjectPtr<UCanvasPanel> RootCanvas;
};
