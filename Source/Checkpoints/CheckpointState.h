#pragma once

#include "CoreMinimal.h"
#include "CheckpointStateComponent.h"
#include "LapMarkerComponent.h"

DECLARE_MULTICAST_DELEGATE(FOnRaceWonDelegate);

/**
 * A singleton that tracks the checkpoints & lap markers
 * needed to finish a lap and/or win a race
 */
class CHECKPOINTS_API CheckpointState
{
public:
    static CheckpointState& GetInstance();
    bool HitCheckpoint(int32 index);
    bool HitLapMarker();
    void RegisterCheckpoint(int32 index, UCheckpointStateComponent* component);
    FOnRaceWonDelegate OnRaceWon;

private:
    CheckpointState() = default;
	~CheckpointState() = default;
    CheckpointState(const CheckpointState&) = delete;
    CheckpointState& operator=(const CheckpointState&) = delete;

    int32 LastCheckpointIndex = 0;
    int32 LapCount = 0;
    const int32 LapWinThreshold = 2;
    bool RaceWon = false;
    ULapMarkerComponent* lapMarker;
    TArray<UCheckpointStateComponent*> checkpoints;

    void ResetAllCheckpoints();
};