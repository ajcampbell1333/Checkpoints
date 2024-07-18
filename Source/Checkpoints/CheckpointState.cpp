#include "CheckpointState.h"

CheckpointState& CheckpointState::GetInstance()
{
	static CheckpointState Instance;
	return Instance;
}

bool CheckpointState::HitCheckpoint(int32 index)
{
	if (index == LastCheckpointIndex + 1)
	{
		LastCheckpointIndex = index;
		UE_LOG(LogTemp, Log, TEXT("Hit Checkpoint %d"), LastCheckpointIndex);

		return true;
	}
	else return false;
}

void CheckpointState::RegisterCheckpoint(int32 index, UCheckpointStateComponent* component)
{
	if (index > 0)
	{
		checkpoints.Add(component);
		UE_LOG(LogTemp, Log, TEXT("Registered Checkpoint %d"), index);
	}
	else if (index == 0)
	{
		ULapMarkerComponent* possibleLapMarker = Cast<ULapMarkerComponent>(component);
		if (possibleLapMarker)
		{
			lapMarker = possibleLapMarker;
			UE_LOG(LogTemp, Log, TEXT("Registered lap marker"));
		}
		else UE_LOG(LogTemp, Error, TEXT("Checkpoint index 0 should be used only for the Lap Marker."));
	}
}

bool CheckpointState::HitLapMarker()
{
	if (LastCheckpointIndex == checkpoints.Num())
	{
		LapCount++;
		if (LapCount >= LapWinThreshold)
		{
			RaceWon = true;
			OnRaceWon.Broadcast();
		}
		else LastCheckpointIndex = 0;
		ResetAllCheckpoints();
		return true;
	}
	else return false;
}

void CheckpointState::ResetAllCheckpoints()
{
	for (UCheckpointStateComponent* Component : checkpoints)
	{
		if (Component)
		{
			Component->OnResetCheckpoint.Broadcast();
		}
	}
}