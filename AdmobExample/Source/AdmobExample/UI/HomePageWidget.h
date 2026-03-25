// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Widgets/SWidget.h"
#include "ProfileSaveGame.h"

#include "HomePageWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UHomePageWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
    int32 CurrentTabIndex = 0;
    void SwitchTab(int32 Index);

	UFUNCTION() void OnTab0Clicked();
	UFUNCTION() void OnTab1Clicked();
	UFUNCTION() void OnTab2Clicked();
	UFUNCTION() void OnTab3Clicked();
	UFUNCTION() void OnTab4Clicked();

	void HandleRewardEarned();
	void HandleBannerAdLoadFailed(const FString& ErrorMessage);
	void HandleInitializationComplete(bool bSuccess, const FString& ErrorMessage);

    UPROPERTY()
    UCanvasPanel* Root;
    
    UPROPERTY()
    class UWidgetSwitcher* BodySwitcher;

    UPROPERTY()
    class UHorizontalBox* BottomNavBar;

	UPROPERTY()
	UTextBlock* BannerPlaceholder;
};
