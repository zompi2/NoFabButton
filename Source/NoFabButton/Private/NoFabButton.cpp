// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#include "NoFabButton.h"
#include "ToolMenus.h"

IMPLEMENT_MODULE(FNoFabButton, NoFabButton)

#if (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION == 5)
void FNoFabButton::StartupModule()
{
	OnPostModulesLoadedDelegateHandle = FCoreDelegates::OnAllModuleLoadingPhasesComplete.AddRaw(this, &FNoFabButton::OnPostModulesLoaded);
}

void FNoFabButton::ShutdownModule()
{
	FCoreDelegates::OnPostEngineInit.Remove(OnPostModulesLoadedDelegateHandle);
}

void FNoFabButton::OnPostModulesLoaded()
{
	if ((IsRunningCommandlet() == false) && (IsRunningGame() == false) && FSlateApplication::IsInitialized())
	{
		if (UToolMenu* ToolMenu = UToolMenus::Get()->ExtendMenu("ContentBrowser.Toolbar"))
		{
			if (FToolMenuSection* ToolSection = ToolMenu->FindSection("New"))
			{
				ToolSection->Blocks.RemoveAll([](const FToolMenuEntry& Block) { return Block.Name == "OpenFabWindow"; });
			}
		}		
	}
}
#endif