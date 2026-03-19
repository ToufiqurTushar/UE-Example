#include "AdmobExampleGameInstance.h"
#include "GoogleMobileAdsBPLibrary.h"
#include "FlutterUMGWidgets.h"
#include "AdmobUserWidget.h"

void UAdmobExampleGameInstance::Init()
{
	Super::Init();

	UGoogleMobileAdsBPLibrary::OnAdMobInitializationComplete.AddUObject(this, &UAdmobExampleGameInstance::HandleAdMobInitializationComplete);

	// Set test devices before initializing AdMob
	UGoogleMobileAdsBPLibrary::SetTestDeviceIds({ TEXT("A52928748FF38C59F746DA17232584B7") });

	// Initialize AdMob perfectly equivalent to before runApp
	UGoogleMobileAdsBPLibrary::InitializeAdMob();
}

void UAdmobExampleGameInstance::HandleAdMobInitializationComplete(bool bSuccess, const FString& ErrorMessage)
{
	if (bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("AdMob Initialization Complete Success"));
		ShowToast(TEXT("AdMob Initialization Success (GameInstance)"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AdMob Initialization Failed: %s"), *ErrorMessage);
		ShowToast(FString::Printf(TEXT("AdMob Initialization Failed: %s"), *ErrorMessage));
	}
}

void UAdmobExampleGameInstance::ShowToast(const FString& Message)
{
	if (MainWidget.IsValid() && RootCanvas.IsValid())
	{
		Flutter::Fluttertoast::showToast(MainWidget.Get(), RootCanvas.Get(), Message);
	}
}
