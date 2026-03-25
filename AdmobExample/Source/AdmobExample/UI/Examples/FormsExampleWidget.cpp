#include "FormsExampleWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

using namespace Flutter;

TSharedRef<SWidget> UFormsExampleWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);
    
    auto AppBar = Container()
        .Color(FLinearColor(0.1f, 0.5f, 0.9f, 1.0f))
        .Padding(FMargin(16.f, 15.f))
        .Child(
            Row()(
                ElevatedButton().OnPressed(this, TEXT("OnBackClicked")).Child(
                    Text(TEXT("Back")).Color(FLinearColor::White).FontSize(14)
                ),
                SizedBox(16.f, 1.f),
                Text(TEXT("Complex Forms")).FontSize(20).Color(FLinearColor::White)
            )
        );

    TArray<FString> Countries = { TEXT("USA"), TEXT("UK"), TEXT("Canada"), TEXT("Australia") };

    auto Content = ListView()(
        Flutter::Padding(FMargin(24.f)).Child(
            Column()(
            Text(TEXT("Registration Form")).FontSize(22).Color(FLinearColor::Black),
            SizedBox(1.f, 16.f),
            
            Text(TEXT("Full Name")).FontSize(14).Color(FLinearColor::Gray),
            SizedBox(1.f, 4.f),
            TextField().HintText(TEXT("John Doe")).OnChanged(this, TEXT("OnNameChanged")),
            SizedBox(1.f, 12.f),
            
            Text(TEXT("Email Address")).FontSize(14).Color(FLinearColor::Gray),
            SizedBox(1.f, 4.f),
            TextField().HintText(TEXT("john@example.com")).OnChanged(this, TEXT("OnEmailChanged")),
            SizedBox(1.f, 12.f),
            
            Text(TEXT("Password")).FontSize(14).Color(FLinearColor::Gray),
            SizedBox(1.f, 4.f),
            TextField().HintText(TEXT("Enter password")).IsPassword(true).OnChanged(this, TEXT("OnPasswordChanged")),
            SizedBox(1.f, 12.f),

            Text(TEXT("Country (Dropdown)")).FontSize(14).Color(FLinearColor::Gray),
            SizedBox(1.f, 4.f),
            DropdownList().Options(Countries).Selected(TEXT("USA")).OnChanged(this, TEXT("OnCountryChanged")),
            SizedBox(1.f, 12.f),

            Text(TEXT("Gender (Radio)")).FontSize(14).Color(FLinearColor::Gray),
            SizedBox(1.f, 4.f),
            Row().MainAxisAlignment(0)(
                [this]() {
                    Radio R = Radio().IsChecked(true).OnChanged(this, TEXT("OnGenderMaleChanged"));
                    MaleRadioBtn = R.Widget;
                    return R;
                }(),
                Text(TEXT("Male ")).Color(FLinearColor::Black),
                
                [this]() {
                    Radio R = Radio().IsChecked(false).OnChanged(this, TEXT("OnGenderFemaleChanged"));
                    FemaleRadioBtn = R.Widget;
                    return R;
                }(),
                Text(TEXT("Female ")).Color(FLinearColor::Black)
            ),
            SizedBox(1.f, 12.f),

            Text(TEXT("Skills (Multiple Checkboxes)")).FontSize(14).Color(FLinearColor::Gray),
            SizedBox(1.f, 4.f),
            Row().MainAxisAlignment(0)(
                Checkbox().OnChanged(this, TEXT("OnSkillCppChanged")), Text(TEXT("C++ ")).Color(FLinearColor::Black),
                Checkbox().OnChanged(this, TEXT("OnSkillUEChanged")), Text(TEXT("Unreal Engine")).Color(FLinearColor::Black)
            ),
            SizedBox(1.f, 12.f),

            Row().MainAxisAlignment(0)(
                Checkbox().OnChanged(this, TEXT("OnTermsChanged")),
                SizedBox(8.f, 1.f),
                Text(TEXT("I accept the Terms and Conditions")).FontSize(14).Color(FLinearColor::Black)
            ),

            SizedBox(1.f, 24.f),
            ElevatedButton().OnPressed(this, TEXT("OnSubmitClicked")).Child(
                Flutter::Padding(FMargin(24.f, 14.f)).Child(Text(TEXT("Validate and Dump JSON")).FontSize(16).Color(FLinearColor::White))
            )
        )
    ));

    auto Root = Container().Color(FLinearColor::White).Child(
        Column()(
            AppBar,
            Expanded().Child(Content)
        )
    );

    if (WidgetTree) WidgetTree->RootWidget = Root.Widget;
    return Root.Widget->TakeWidget();
}
void UFormsExampleWidget::OnBackClicked() { RemoveFromParent(); }
void UFormsExampleWidget::OnNameChanged(const FText& Text) { NameStr = Text.ToString(); }
void UFormsExampleWidget::OnEmailChanged(const FText& Text) { EmailStr = Text.ToString(); }
void UFormsExampleWidget::OnPasswordChanged(const FText& Text) { PasswordStr = Text.ToString(); }
void UFormsExampleWidget::OnTermsChanged(bool bIsChecked) { bTermsAccepted = bIsChecked; }
void UFormsExampleWidget::OnGenderMaleChanged(bool bIsChecked) { 
    if (bIsChecked) {
        GenderStr = TEXT("Male"); 
        if (FemaleRadioBtn) FemaleRadioBtn->SetIsChecked(false);
    }
}
void UFormsExampleWidget::OnGenderFemaleChanged(bool bIsChecked) { 
    if (bIsChecked) {
        GenderStr = TEXT("Female"); 
        if (MaleRadioBtn) MaleRadioBtn->SetIsChecked(false);
    }
}
void UFormsExampleWidget::OnCountryChanged(FString SelectedItem, ESelectInfo::Type SelectionType) { CountryStr = SelectedItem; }
void UFormsExampleWidget::OnSkillCppChanged(bool bIsChecked) { bSkillCpp = bIsChecked; }
void UFormsExampleWidget::OnSkillUEChanged(bool bIsChecked) { bSkillUE = bIsChecked; }

void UFormsExampleWidget::OnSubmitClicked() { 
    if (!WidgetTree || !WidgetTree->RootWidget) return;
    auto RootCanvas = Cast<UCanvasPanel>(WidgetTree->RootWidget);
    
    // Validation
    if (NameStr.TrimStartAndEnd().IsEmpty()) {
        Fluttertoast::showToast(this, RootCanvas, TEXT("Error: Name is required")); return;
    }
    if (EmailStr.TrimStartAndEnd().IsEmpty() || !EmailStr.Contains(TEXT("@"))) {
        Fluttertoast::showToast(this, RootCanvas, TEXT("Error: Valid Email is required")); return;
    }
    if (PasswordStr.Len() < 6) {
        Fluttertoast::showToast(this, RootCanvas, TEXT("Error: Password must be 6+ characters")); return;
    }
    if (!bTermsAccepted) {
        Fluttertoast::showToast(this, RootCanvas, TEXT("Error: You must accept the terms")); return;
    }

    // Build JSON
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField(TEXT("name"), NameStr);
    JsonObject->SetStringField(TEXT("email"), EmailStr);
    JsonObject->SetStringField(TEXT("password_length"), FString::FromInt(PasswordStr.Len()));
    JsonObject->SetStringField(TEXT("gender"), GenderStr);
    JsonObject->SetStringField(TEXT("country"), CountryStr);
    JsonObject->SetBoolField(TEXT("skill_cpp"), bSkillCpp);
    JsonObject->SetBoolField(TEXT("skill_unreal_engine"), bSkillUE);
    JsonObject->SetBoolField(TEXT("terms_accepted"), bTermsAccepted);

    FString OutputString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    UE_LOG(LogTemp, Warning, TEXT("Form Submitted JSON: %s"), *OutputString);
    Fluttertoast::showToast(this, RootCanvas, TEXT("Valid Form! Check Logs.")); 
}
