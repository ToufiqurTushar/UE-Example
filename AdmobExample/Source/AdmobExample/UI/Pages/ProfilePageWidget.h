#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProfilePageWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UProfilePageWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void NativeConstruct() override;

public:
	UFUNCTION() void OnEditProfileClicked();
	UFUNCTION() void OnSaveProfileClicked();
	UFUNCTION() void OnNameChanged(const FText& Text);
	UFUNCTION() void OnEmailChanged(const FText& Text);
	UFUNCTION() void OnBioChanged(const FText& Text);

private:
	class UWidget* BuildProfileViewPage();
	class UWidget* BuildProfileEditPage();
	void LoadProfile();

	class UWidgetSwitcher* ProfileSwitcher = nullptr;

	FString CurrentName;
	FString CurrentEmail;
	FString CurrentBio;

	class UTextBlock* ProfileNameText = nullptr;
	class UTextBlock* ProfileEmailText = nullptr;
	class UTextBlock* ProfileBioText = nullptr;
};
