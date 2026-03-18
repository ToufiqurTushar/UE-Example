// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Widgets/SWidget.h"

#include "AdmobUserWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UAdmobUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	void HandleRewardEarned();

	UFUNCTION()
	void OnShowInterstitialClicked();

	UFUNCTION()
	void OnShowRewardedClicked();

    UPROPERTY()
    UCanvasPanel* Root;
    
    UPROPERTY()
    UTextBlock* AppBarText;

	UPROPERTY()
	UVerticalBox* CenterBox;

	UPROPERTY()
	UButton* BtnShowInterstitial;
	
	UPROPERTY()
	UButton* BtnShowRewarded;

	UPROPERTY()
	UTextBlock* BannerPlaceholder;
};
