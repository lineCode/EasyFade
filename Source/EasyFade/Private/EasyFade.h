// Copyright 2023 Metaseven. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FEasyFadeModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
};
