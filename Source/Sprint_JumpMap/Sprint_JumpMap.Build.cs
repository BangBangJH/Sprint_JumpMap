// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Sprint_JumpMap : ModuleRules
{
	public Sprint_JumpMap(ReadOnlyTargetRules Target) : base(Target)
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
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Sprint_JumpMap",
			"Sprint_JumpMap/Variant_Platforming",
			"Sprint_JumpMap/Variant_Combat",
			"Sprint_JumpMap/Variant_Combat/AI",
			"Sprint_JumpMap/Variant_SideScrolling",
			"Sprint_JumpMap/Variant_SideScrolling/Gameplay",
			"Sprint_JumpMap/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
