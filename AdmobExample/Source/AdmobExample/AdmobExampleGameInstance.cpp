#include "AdmobExampleGameInstance.h"
#include "GoogleMobileAdsBPLibrary.h"

void UAdmobExampleGameInstance::Init()
{
	Super::Init();

	// Set test devices before initializing AdMob
	UGoogleMobileAdsBPLibrary::SetTestDeviceIds({ TEXT("A52928748FF38C59F746DA17232584B7") });

	// Initialize AdMob perfectly equivalent to before runApp
	UGoogleMobileAdsBPLibrary::InitializeAdMob();
}
