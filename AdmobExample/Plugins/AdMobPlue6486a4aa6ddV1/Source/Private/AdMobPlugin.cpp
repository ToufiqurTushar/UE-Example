// Copyright (c) 2025 Loko. All Rights Reserved.
#include "AdMobPlugin.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FAdMobPluginModule, AdMobPlugin)

void FAdMobPluginModule::StartupModule()
{
	// Runtime-only module; nothing special needed here
}

void FAdMobPluginModule::ShutdownModule()
{
	// Cleanup if needed
}
