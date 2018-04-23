// Copyright 1998-2014 Epic MyProject3s, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class MyProject3ServerTarget : TargetRules
{
    public MyProject3ServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
        ExtraModuleNames.Add("MyProject3");

    }


}