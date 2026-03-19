#include "GoogleMobileAdsRuntimeSettings.h"

UGoogleMobileAdsRuntimeSettings::UGoogleMobileAdsRuntimeSettings(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // Safely defaults to Google's standard test Application IDs
    AdMobAppID_Android = TEXT("ca-app-pub-3940256099942544~3347511713");
    AdMobAppID_IOS = TEXT("ca-app-pub-3940256099942544~1458002511");
}
