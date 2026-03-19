#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "FlutterInkWell.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInkWellClicked, int32, Index);

/**
 * Custom button for FlutterUMG InkWell implementation.
 */
UCLASS()
class FLUTTERUMG_API UFlutterInkWell : public UButton
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flutter")
	int32 Index = -1;

	UPROPERTY(BlueprintAssignable, Category = "Flutter")
	FOnInkWellClicked OnInkWellClicked;

	UFlutterInkWell();

protected:
	virtual void SynchronizeProperties() override;

private:
	UFUNCTION()
	void HandleInternalClick();
};
