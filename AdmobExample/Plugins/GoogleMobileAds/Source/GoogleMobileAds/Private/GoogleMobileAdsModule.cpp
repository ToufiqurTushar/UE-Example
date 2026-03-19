#include "GoogleMobileAdsModule.h"

#include "GoogleMobileAdsSettings.h"
#include "Developer/Settings/Public/ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FGoogleMobileAdsModule"

void FGoogleMobileAdsModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "GoogleMobileAds",
			LOCTEXT("RuntimeSettingsName", "Google Mobile Ads"),
			LOCTEXT("RuntimeSettingsDescription", "Configure AdMob Application IDs"),
			GetMutableDefault<UGoogleMobileAdsSettings>()
		);
	}
}

void FGoogleMobileAdsModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "GoogleMobileAds");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGoogleMobileAdsModule, GoogleMobileAds)
