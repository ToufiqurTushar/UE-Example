#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FormsExampleWidget.generated.h"

UCLASS()
class ADMOBEXAMPLE_API UFormsExampleWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
public:
	UFUNCTION() void OnBackClicked();
	UFUNCTION() void OnNameChanged(const FText& Text);
    UFUNCTION() void OnEmailChanged(const FText& Text);
    UFUNCTION() void OnPasswordChanged(const FText& Text);
    UFUNCTION() void OnTermsChanged(bool bIsChecked);
    
    UFUNCTION() void OnGenderMaleChanged(bool bIsChecked);
    UFUNCTION() void OnGenderFemaleChanged(bool bIsChecked);
    
    UFUNCTION() void OnCountryChanged(FString SelectedItem, ESelectInfo::Type SelectionType);
    
    UFUNCTION() void OnSkillCppChanged(bool bIsChecked);
    UFUNCTION() void OnSkillUEChanged(bool bIsChecked);

    UFUNCTION() void OnSubmitClicked();

private:
    class UCheckBox* MaleRadioBtn = nullptr;
    class UCheckBox* FemaleRadioBtn = nullptr;

    FString NameStr;
    FString EmailStr;
    FString PasswordStr;
    bool bTermsAccepted = false;
    
    FString GenderStr = TEXT("Male");
    FString CountryStr = TEXT("USA");
    bool bSkillCpp = false;
    bool bSkillUE = false;
};
