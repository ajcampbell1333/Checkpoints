// Copyright Epic Games, Inc. All Rights Reserved.

#include "CheckpointsGameMode.h"
#include "CheckpointsPlayerController.h"

ACheckpointsGameMode::ACheckpointsGameMode()
{
	PlayerControllerClass = ACheckpointsPlayerController::StaticClass();
}
