// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

using UnrealBuildTool;
public class NoFabButton : ModuleRules
{
	public NoFabButton(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"CoreUObject",
				"ToolMenus",
				"Slate"
			}
		);
	}
}
