#include "CheckpointStateComponent.h"
#include "CheckpointState.h"


UCheckpointStateComponent::UCheckpointStateComponent()
{
    SetCollisionProfileName(TEXT("Trigger"));
    SetGenerateOverlapEvents(true);
}

void UCheckpointStateComponent::BeginPlay()
{
	CheckpointState::GetInstance().RegisterCheckpoint(index, this);
}

bool UCheckpointStateComponent::HitCheckpoint()
{
	return CheckpointState::GetInstance().HitCheckpoint(index);
}
