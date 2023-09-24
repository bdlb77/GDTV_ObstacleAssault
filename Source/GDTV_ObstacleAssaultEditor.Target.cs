// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class GDTV_ObstacleAssaultEditorTarget : TargetRules
{
	public GDTV_ObstacleAssaultEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "GDTV_ObstacleAssault" } );
	}
}
