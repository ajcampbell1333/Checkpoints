// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CheckpointStateComponent.h"
#include "LapMarkerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinish);

/**
 * Tallies laps completed and confirms win condition
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHECKPOINTS_API ULapMarkerComponent : public UCheckpointStateComponent
{
	GENERATED_BODY()
	
private:
	UFUNCTION(BlueprintCallable, Category = "Checkpoint State")
	bool HitLapMarker();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnFinish OnFinish;

protected:
	virtual void BeginPlay() override;
};