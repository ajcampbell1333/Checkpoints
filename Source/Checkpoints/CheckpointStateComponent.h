#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "CheckpointStateComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResetCheckpoint);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHECKPOINTS_API UCheckpointStateComponent : public UBoxComponent
{
	GENERATED_BODY()

public:	
	UCheckpointStateComponent();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnResetCheckpoint OnResetCheckpoint;

	UFUNCTION(BlueprintCallable, Category = "Checkpoint State")
	bool HitCheckpoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint State", meta = (ToolTip = "The ordered index number of this checkpoint relative to all others on the racetrack, starting at 1"))
	int32 index;

protected:
	virtual void BeginPlay() override;
};