// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class NOFABBUTTON_API FNoFabButton : public IModuleInterface
{

protected:

#if (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION == 5)
	void StartupModule() override;
	void ShutdownModule() override;
	void OnPostModulesLoaded();
	FDelegateHandle OnPostModulesLoadedDelegateHandle;
#endif
};
