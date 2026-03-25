#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AdmobExampleGameInstance.generated.h"

class UHomePageWidget;
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

	void SetMainWidget(UHomePageWidget* InWidget, UCanvasPanel* InRoot);
	void ShowToast(const FString& Message);

private:
	TWeakObjectPtr<UHomePageWidget> MainWidget;
	TWeakObjectPtr<UCanvasPanel> RootCanvas;
};
