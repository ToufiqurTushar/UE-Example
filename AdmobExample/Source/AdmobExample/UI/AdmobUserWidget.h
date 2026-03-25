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

#include "AdmobUserWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UAdmobUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
    int32 CurrentTabIndex = 0;
    void SwitchTab(int32 Index);

	UFUNCTION() void OnTab0Clicked();
	UFUNCTION() void OnTab1Clicked();
	UFUNCTION() void OnTab2Clicked();
	UFUNCTION() void OnTab3Clicked();
	UFUNCTION() void OnTab4Clicked();

    UWidget* BuildAdsPage();
    UWidget* BuildListPage();
    UWidget* BuildProfilePage();
    UWidget* BuildRankingPage();
    UWidget* BuildAboutPage();

    UFUNCTION()
    void OnEditProfileClicked();

    UFUNCTION()
    void OnSaveProfileClicked();

    UFUNCTION()
    void OnNameChanged(const FText& Text);

    UFUNCTION()
    void OnEmailChanged(const FText& Text);

    UFUNCTION()
    void OnBioChanged(const FText& Text);

    UWidget* BuildProfileViewPage();
    UWidget* BuildProfileEditPage();

    UFUNCTION()
    void OnRankingAddClicked();

    UFUNCTION()
    void OnRankingRemoveClicked();

    UFUNCTION()
    void OnRankingShuffleClicked();

    void LoadProfile();

    struct FRankingItem {
        int32 Id;
        FString Name;
        int32 Score;
        UWidget* Widget = nullptr;
        float CurrentY = 0.0f;
        float TargetY = 0.0f;
        float Opacity = 0.0f;
        float TargetOpacity = 1.0f;
        bool bIsRemoving = false;
    };

    TArray<FRankingItem> RankingItems;
    UCanvasPanel* RankingCanvas = nullptr;
    class USizeBox* RankingSizeBox = nullptr;
    int32 NextRankingId = 0;
    
    float CurrentRankingHeight = 0.0f;
    float TargetRankingHeight = 0.0f;

    FString CurrentName;
    FString CurrentEmail;
    FString CurrentBio;

    UPROPERTY()
    class UWidgetSwitcher* ProfileSwitcher;

    UPROPERTY()
    class UTextBlock* ProfileNameText;

    UPROPERTY()
    class UTextBlock* ProfileEmailText;

    UPROPERTY()
    class UTextBlock* ProfileBioText;

	void HandleRewardEarned();
	void HandleBannerAdLoadFailed(const FString& ErrorMessage);
	void HandleInitializationComplete(bool bSuccess, const FString& ErrorMessage);

	UFUNCTION()
	void OnCheckInitClicked();

	UFUNCTION()
    void OnListItemClicked(int32 Index);

	UFUNCTION()
	void OnShowInterstitialClicked();

	UFUNCTION()
	void OnShowRewardedClicked();

	UFUNCTION()
	void OnShowBannerClicked();

	UFUNCTION()
	void OnHideBannerClicked();

    UPROPERTY()
    UCanvasPanel* Root;
    
    UPROPERTY()
    class UWidgetSwitcher* BodySwitcher;

    UPROPERTY()
    class UHorizontalBox* BottomNavBar;

	UPROPERTY()
	UTextBlock* BannerPlaceholder;
};
