// Copyright (c) 2025 Loko. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FAdMobPluginModule : public IModuleInterface
{
public:
	/** Called when the module is loaded into memory */
	virtual void StartupModule() override;

	/** Called before the module is unloaded from memory */
	virtual void ShutdownModule() override;
};
