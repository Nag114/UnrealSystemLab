// Copyright UnrealSystemLab. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionSweepExperimentActor.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;

/**
 * A stationary visual starting point for the single-wall collision experiment.
 *
 * The capsule is the movement and collision root. DisplayMesh is intentionally
 * collision-free so changing its appearance cannot change the experiment volume.
 */
UCLASS(BlueprintType, Blueprintable)
class UNREALSYSTEMLAB_API ACollisionSweepExperimentActor : public AActor
{
	GENERATED_BODY()

public:
	ACollisionSweepExperimentActor();

	virtual void Tick(float DeltaSeconds) override;

	/** The actual collision shape that later steps will move with Sweep. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision Sweep Experiment|Components")
	TObjectPtr<UCapsuleComponent> CollisionCapsule;

	/** The visible template character. It never contributes collision to the experiment. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision Sweep Experiment|Components")
	TObjectPtr<USkeletalMeshComponent> DisplayMesh;
};
