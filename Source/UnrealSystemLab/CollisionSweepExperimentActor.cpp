// Copyright UnrealSystemLab. All Rights Reserved.

#include "CollisionSweepExperimentActor.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(CollisionSweepExperimentActor)

ACollisionSweepExperimentActor::ACollisionSweepExperimentActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	SetRootComponent(CollisionCapsule);
	CollisionCapsule->InitCapsuleSize(42.0f, 96.0f);
	CollisionCapsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionCapsule->SetCollisionObjectType(ECC_Pawn);
	CollisionCapsule->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionCapsule->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionCapsule->SetSimulatePhysics(false);
	CollisionCapsule->SetGenerateOverlapEvents(false);

	DisplayMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("DisplayMesh"));
	DisplayMesh->SetupAttachment(CollisionCapsule);
	DisplayMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DisplayMesh->SetSimulatePhysics(false);
}

void ACollisionSweepExperimentActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	const FTransform CapsuleTransform = CollisionCapsule->GetComponentTransform();
	DrawDebugCapsule(
		GetWorld(),
		CapsuleTransform.GetLocation(),
		CollisionCapsule->GetScaledCapsuleHalfHeight(),
		CollisionCapsule->GetScaledCapsuleRadius(),
		CapsuleTransform.GetRotation(),
		FColor::Cyan,
		false,
		-1.0f,
		SDPG_Foreground,
		3.0f);
}
