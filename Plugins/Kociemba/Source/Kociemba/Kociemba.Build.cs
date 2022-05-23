// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Kociemba : ModuleRules
{
	public Kociemba(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"KociembaLibrary",
				"Projects"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);


		/*string KociembaIncludePath = Path.Combine(ModuleDirectory, "../../Include/Win64/Kociemba");
		PublicIncludePaths.AddRange(new string[] { KociembaIncludePath });

		//LIB
		string KociembaLibraryPath = Path.Combine(ModuleDirectory, "../../ThirdParty/KociembaDLL/Win64");
		PublicLibraryPaths.Add(KociembaLibraryPath);
		PublicAdditionalLibraries.Add(Path.Combine(KociembaLibraryPath, "KociembaDLL.lib"));

		//DLL
		PublicDelayLoadDLLs.Add("KociembaDLL.dll");
		RuntimeDependencies.Add(Path.Combine(KociembaLibraryPath, "KociembaDLL.dll"));//*/
	}
}
