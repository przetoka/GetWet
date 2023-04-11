// Fill out your copyright notice in the Description page of Project Settings.


#include "Pillars.h"

void APillars::SpawnPillars()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning Pillars and dropplets"));

	for (size_t i = 0; i < Pillars.Num(); i++)
	{
		if(Pillars[i])
			Pillars[i]->DestroyComponent();
	}

	Pillars.Empty();

	for (size_t i = 0; i < PillarsTop.Num(); i++)
	{
		if (PillarsTop[i])
			PillarsTop[i]->DestroyComponent();
	}

	PillarsTop.Empty();

	for (size_t i = 0; i < NumOfPillars; i++)
	{
		UStaticMeshComponent* smc = (UStaticMeshComponent*)AddComponentByClass(UStaticMeshComponent::StaticClass(), false, FTransform(), true);
		UStaticMeshComponent* smcTop = (UStaticMeshComponent*)AddComponentByClass(UStaticMeshComponent::StaticClass(), false, FTransform(), true);

		int height = FMath::RandRange(MinHeight, MaxHeight);

		if (smc)
		{
			smc->RegisterComponent();
			smc->SetMobility(EComponentMobility::Movable);
			smc->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			smc->SetRelativeLocation(smc->GetRelativeLocation() + FVector(0, PillarGap * i, height * 50));
			smc->SetWorldScale3D(FVector(PillarX, PillarY, 5));
			smc->SetStaticMesh(PillarMesh);
			Pillars.Add(smc);
		}

		if (smcTop)
		{
			smcTop->RegisterComponent();
			smcTop->SetMobility(EComponentMobility::Movable);
			smcTop->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			smcTop->SetRelativeLocation(smcTop->GetRelativeLocation() + FVector(0, PillarGap * i, height * 50 + VerticalPillarGap));
			smcTop->SetWorldScale3D(FVector(PillarX, PillarY, 5));
			smcTop->SetStaticMesh(PillarMesh);
			PillarsTop.Add(smcTop);
		} 
	}
}

// Sets default values
APillars::APillars()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
}

// Called when the game starts or when spawned
void APillars::BeginPlay()
{
	Super::BeginPlay();
	
}

void APillars::OnConstruction(const FTransform& Transform)
{
	SpawnPillars();
}

// Called every frame
void APillars::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (size_t i = 0; i < Pillars.Num(); i++)
	{
		int height = FMath::RandRange(MinHeight, MaxHeight);
		if (Pillars[i]) {
			if (Pillars[i]->GetRelativeLocation().Y < -1 * (PillarGap * (NumOfPillars - 5)))
			{
				Pillars[i]->SetRelativeLocation(FVector(0, PillarGap * 3, height * 50));
			}
			else
			{
				Pillars[i]->SetRelativeLocation(Pillars[i]->GetRelativeLocation() + FVector(0, MoveSpeed * DeltaTime, 0));
			}
		}

		if (PillarsTop[i]) {
			if (PillarsTop[i]->GetRelativeLocation().Y < -1 * (PillarGap * (NumOfPillars - 5)))
			{
				PillarsTop[i]->SetRelativeLocation(FVector(0, PillarGap * 3, height * 50 + VerticalPillarGap));
			}
			else
			{
				PillarsTop[i]->SetRelativeLocation(PillarsTop[i]->GetRelativeLocation() + FVector(0, MoveSpeed * DeltaTime, 0));
			}
		}
	}
}

