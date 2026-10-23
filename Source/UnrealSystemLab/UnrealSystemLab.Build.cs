// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealSystemLab : ModuleRules
{
	public UnrealSystemLab(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UnrealSystemLab",
			"UnrealSystemLab/Variant_Platforming",
			"UnrealSystemLab/Variant_Platforming/Animation",
			"UnrealSystemLab/Variant_Combat",
			"UnrealSystemLab/Variant_Combat/AI",
			"UnrealSystemLab/Variant_Combat/Animation",
			"UnrealSystemLab/Variant_Combat/Gameplay",
			"UnrealSystemLab/Variant_Combat/Interfaces",
			"UnrealSystemLab/Variant_Combat/UI",
			"UnrealSystemLab/Variant_SideScrolling",
			"UnrealSystemLab/Variant_SideScrolling/AI",
			"UnrealSystemLab/Variant_SideScrolling/Gameplay",
			"UnrealSystemLab/Variant_SideScrolling/Interfaces",
			"UnrealSystemLab/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
