using UnrealBuildTool;
using System.IO;

public class GoogleMobileAds : ModuleRules
{
	public GoogleMobileAds(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			}
		);

		// Android specific dependencies via UPL
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "GoogleMobileAds_UPL_Android.xml"));
		}

		// iOS specific dependencies
		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PCHUsage = ModuleRules.PCHUsageMode.NoSharedPCHs;

			PublicFrameworks.AddRange(
				new string[]
				{
					"StoreKit",
					"SystemConfiguration",
					"CoreTelephony",
					"AdSupport",
					"MessageUI",
					"EventKit",
					"EventKitUI",
					"CoreMedia",
					"AVFoundation",
					"MediaPlayer",
					"AudioToolbox",
					"WebKit"
				}
			);
			
			PublicWeakFrameworks.AddRange(
				new string[]
				{
					"AppTrackingTransparency"
				}
			);
			
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(PluginPath, "GoogleMobileAds_UPL_IOS.xml"));

			bEnableObjCAutomaticReferenceCounting = true;
		}
	}
}
