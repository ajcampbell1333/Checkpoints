// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CheckpointsPawn.h"
#include "CheckpointsSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class CHECKPOINTS_API ACheckpointsSportsCar : public ACheckpointsPawn
{
	GENERATED_BODY()
	
public:

	ACheckpointsSportsCar();
};
