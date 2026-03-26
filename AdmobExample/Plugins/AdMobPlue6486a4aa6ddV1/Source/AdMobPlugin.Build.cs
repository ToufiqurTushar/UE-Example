// Copyright (c) 2025 Loko. All Rights Reserved.
using UnrealBuildTool;
using System.IO;

public class AdMobPlugin : ModuleRules
{
	public AdMobPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"DeveloperSettings"
			});

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Launch"
			});
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "AdMobPlugin_APL.xml"));
		}
	}
}
