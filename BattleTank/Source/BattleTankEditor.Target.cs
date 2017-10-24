// Free to Play. By SoNa Games

using UnrealBuildTool;
using System.Collections.Generic;

public class BattleTankEditorTarget : TargetRules
{
	public BattleTankEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        bUseUnityBuild = false;
        bUsePCHFiles = false;

		ExtraModuleNames.AddRange( new string[] { "BattleTank" } );
	}
}
