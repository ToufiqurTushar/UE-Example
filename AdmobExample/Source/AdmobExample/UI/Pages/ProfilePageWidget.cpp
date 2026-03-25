#include "ProfilePageWidget.h"
#include "FlutterUMGWidgets.h"
#include "Kismet/GameplayStatics.h"
#include "ProfileSaveGame.h"
#include "AdmobExampleGameInstance.h"

using namespace Flutter;

void UProfilePageWidget::NativeConstruct() {
    Super::NativeConstruct();
    LoadProfile();
}

TSharedRef<SWidget> UProfilePageWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);
    
    if (CurrentName.IsEmpty()) {
        LoadProfile();
    }

    auto Stack = IndexedStack().Index(0)(
        BuildProfileViewPage(),
        BuildProfileEditPage()
    );
    ProfileSwitcher = Cast<UWidgetSwitcher>(Stack.Widget);
    
    return ProfileSwitcher->TakeWidget();
}

UWidget* UProfilePageWidget::BuildProfileViewPage() {
    Flutter::Text NameTextWidget = Flutter::Text(CurrentName).FontSize(18);
    ProfileNameText = NameTextWidget.Widget;

    Flutter::Text EmailTextWidget = Flutter::Text(CurrentEmail).FontSize(18);
    ProfileEmailText = EmailTextWidget.Widget;

    Flutter::Text BioTextWidget = Flutter::Text(CurrentBio).FontSize(16);
    ProfileBioText = BioTextWidget.Widget;

    return Flutter::Padding(FMargin(16.0f)).Child(
        Flutter::Column().MainAxisAlignment(0)(
            Flutter::Center()(Flutter::Text(TEXT("User Profile")).FontSize(24)),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::Card().SetElevation(4.0f).SetBorderRadius(8.0f).Child(
                Flutter::Padding(FMargin(16.0f)).Child(
                    Flutter::Column().MainAxisAlignment(0)(
                        Flutter::Text(TEXT("Name:")).FontSize(14).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)),
                        Flutter::SizedBox(1.0f, 4.0f),
                        NameTextWidget,
                        Flutter::SizedBox(1.0f, 16.0f),
                        Flutter::Text(TEXT("Email:")).FontSize(14).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)),
                        Flutter::SizedBox(1.0f, 4.0f),
                        EmailTextWidget,
                        Flutter::SizedBox(1.0f, 16.0f),
                        Flutter::Text(TEXT("Bio:")).FontSize(14).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)),
                        Flutter::SizedBox(1.0f, 4.0f),
                        BioTextWidget
                    )
                )
            ),
            Flutter::SizedBox(1.0f, 30.0f),
            Flutter::Center()(
                Flutter::ElevatedButton()
                    .OnPressed(this, TEXT("OnEditProfileClicked"))
                    .Child(Flutter::Padding(FMargin(16.0f, 8.0f)).Child(Flutter::Text(TEXT("Edit Profile")).FontSize(16).Color(FLinearColor::White)))
            )
        )
    ).Widget;
}

UWidget* UProfilePageWidget::BuildProfileEditPage() {
    return Flutter::Padding(FMargin(16.0f)).Child(
        Flutter::Column().MainAxisAlignment(0)(
            Flutter::Center()(Flutter::Text(TEXT("Edit Profile")).FontSize(24)),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::TextField().Text(CurrentName).HintText(TEXT("Name")).OnChanged(this, TEXT("OnNameChanged")),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::TextField().Text(CurrentEmail).HintText(TEXT("Email")).OnChanged(this, TEXT("OnEmailChanged")),
            Flutter::SizedBox(1.0f, 20.0f),
            Flutter::TextField().Text(CurrentBio).HintText(TEXT("Bio")).OnChanged(this, TEXT("OnBioChanged")),
            Flutter::SizedBox(1.0f, 30.0f),
            Flutter::Center()(
                Flutter::ElevatedButton()
                    .OnPressed(this, TEXT("OnSaveProfileClicked"))
                    .Child(Flutter::Padding(FMargin(16.0f, 8.0f)).Child(Flutter::Text(TEXT("Save Profile")).FontSize(16).Color(FLinearColor::White)))
            )
        )
    ).Widget;
}

void UProfilePageWidget::LoadProfile() {
    if (UGameplayStatics::DoesSaveGameExist(TEXT("ProfileSlot"), 0)) {
        if (UProfileSaveGame* LoadedGame = Cast<UProfileSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("ProfileSlot"), 0))) {
            CurrentName = LoadedGame->UserName;
            CurrentEmail = LoadedGame->UserEmail;
            CurrentBio = LoadedGame->UserBio;
            return;
        }
    }
    
    CurrentName = TEXT("Guest User");
    CurrentEmail = TEXT("guest@example.com");
    CurrentBio = TEXT("Hello! I am using the FlutterUMG plugin in Unreal Engine.");
}

void UProfilePageWidget::OnEditProfileClicked() {
    if (ProfileSwitcher) {
        ProfileSwitcher->SetActiveWidgetIndex(1);
    }
}

void UProfilePageWidget::OnSaveProfileClicked() {
    if (UProfileSaveGame* SaveGameInstance = Cast<UProfileSaveGame>(UGameplayStatics::CreateSaveGameObject(UProfileSaveGame::StaticClass()))) {
        SaveGameInstance->UserName = CurrentName;
        SaveGameInstance->UserEmail = CurrentEmail;
        SaveGameInstance->UserBio = CurrentBio;
        UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("ProfileSlot"), 0);
        
        if (ProfileNameText) ProfileNameText->SetText(FText::FromString(CurrentName));
        if (ProfileEmailText) ProfileEmailText->SetText(FText::FromString(CurrentEmail));
        if (ProfileBioText) ProfileBioText->SetText(FText::FromString(CurrentBio));

        if (ProfileSwitcher) {
            ProfileSwitcher->SetActiveWidgetIndex(0);
        }
        
        if (auto* GI = Cast<UAdmobExampleGameInstance>(GetGameInstance())) {
            GI->ShowToast(TEXT("Profile Saved!"));
        }
    }
}

void UProfilePageWidget::OnNameChanged(const FText& Text) { CurrentName = Text.ToString(); }
void UProfilePageWidget::OnEmailChanged(const FText& Text) { CurrentEmail = Text.ToString(); }
void UProfilePageWidget::OnBioChanged(const FText& Text) { CurrentBio = Text.ToString(); }
