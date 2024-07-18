// Copyright Epic Games, Inc. All Rights Reserved.

#include "CheckpointsWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UCheckpointsWheelRear::UCheckpointsWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}