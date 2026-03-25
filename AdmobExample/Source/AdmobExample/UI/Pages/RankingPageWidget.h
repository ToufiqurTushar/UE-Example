#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RankingPageWidget.generated.h"

USTRUCT(BlueprintType)
struct FRankingItem {
    GENERATED_BODY()

    UPROPERTY()
    int32 Id = 0;

    UPROPERTY()
    FString Name;

    UPROPERTY()
    int32 Score = 0;

    UPROPERTY()
    class UWidget* Widget = nullptr;

    UPROPERTY()
    float CurrentY = 0.0f;

    UPROPERTY()
    float TargetY = 0.0f;

    UPROPERTY()
    float Opacity = 0.0f;

    UPROPERTY()
    float TargetOpacity = 1.0f;

    UPROPERTY()
    bool bIsRemoving = false;
};

UCLASS()
class ADMOBEXAMPLE_API URankingPageWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	UFUNCTION()
	void AnimationTick();

public:
	UFUNCTION() void OnRankingAddClicked();
	UFUNCTION() void OnRankingRemoveClicked();
	UFUNCTION() void OnRankingShuffleClicked();

private:
	UPROPERTY()
	TArray<FRankingItem> RankingItems;

	UPROPERTY()
	class UCanvasPanel* RankingCanvas = nullptr;

	UPROPERTY()
	class USizeBox* RankingSizeBox = nullptr;

	int32 NextRankingId = 0;
	
	float CurrentRankingHeight = 0.0f;
	float TargetRankingHeight = 0.0f;

	FTimerHandle AnimationTimerHandle;
};
