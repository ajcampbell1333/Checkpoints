// Copyright Epic Games, Inc. All Rights Reserved.

#include "CheckpointsWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UCheckpointsWheelFront::UCheckpointsWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}