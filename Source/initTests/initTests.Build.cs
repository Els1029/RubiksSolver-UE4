// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class initTests : ModuleRules
{
	public initTests(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });


		//Includes
		//string KociembaIncludePath = Path.Combine(ModuleDirectory, "../../Include/Win64/Kociemba");
		//PublicIncludePaths.AddRange(new string[] { KociembaIncludePath });//*/

		//LIB
		// KociembaLibraryPath = Path.Combine(ModuleDirectory, "../../ThirdParty/KociembaDLL/Win64");
		//PublicLibraryPaths.Add(KociembaLibraryPath);
		//PublicAdditionalLibraries.Add(Path.Combine(KociembaLibraryPath, "KociembaDLL.lib"));//*/

		//DLL
		/*PublicDelayLoadDLLs.Add("KociembaDLL.dll");
		RuntimeDependencies.Add(Path.Combine(KociembaLibraryPath, "KociembaDLL.dll"));//*/
																					  //DLL
		//PublicDelayLoadDLLs.Add("KociembaCPP.dll");
		//RuntimeDependencies.Add(Path.Combine(Path.Combine(ModuleDirectory, "../../Binaries/Win64"), "KociembaCPP.dll"));//*/

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
