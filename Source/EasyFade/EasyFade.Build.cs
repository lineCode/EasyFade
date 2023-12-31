// Copyright 2023 Metaseven. All Rights Reserved.

using UnrealBuildTool;

public class EasyFade : ModuleRules
{
	public EasyFade(ReadOnlyTargetRules Target) : base(Target)
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
				"SlateCore",
			}
		);
	}
}
