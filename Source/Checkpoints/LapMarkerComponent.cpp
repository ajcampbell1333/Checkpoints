#include "LapMarkerComponent.h"
#include "CheckpointState.h"

void ULapMarkerComponent::BeginPlay()
{
    Super::BeginPlay();
    CheckpointState::GetInstance().OnRaceWon.AddLambda([this]()
    {
        UE_LOG(LogTemp, Log, TEXT("Lambda executed"));
        OnFinish.Broadcast();
    });
}

bool ULapMarkerComponent::HitLapMarker()
{
	return CheckpointState::GetInstance().HitLapMarker();
}