// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pillars.generated.h"

UCLASS()
class GETWET_API APillars : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		TArray<UStaticMeshComponent*> Pillars;

	UPROPERTY(VisibleAnywhere)
		TArray<UStaticMeshComponent*> PillarsTop;

	UPROPERTY(EditAnywhere)
		int NumOfPillars = 5;

	UPROPERTY(EditAnywhere)
		int MaxHeight = 8;

	UPROPERTY(EditAnywhere)
		int MinHeight = 2;

	UPROPERTY(EditAnywhere)
		double PillarX = 1;

	UPROPERTY(EditAnywhere)
		double PillarY = 1;

	UPROPERTY(EditAnywhere)
		float PillarGap = 100.f;

	UPROPERTY(EditAnywhere)
		float VerticalPillarGap = 800.f;

	UPROPERTY(EditAnywhere)
		float MoveSpeed = 100.f;

	UPROPERTY(EditDefaultsOnly)
		UStaticMesh* PillarMesh;

	UPROPERTY(EditDefaultsOnly)
		USceneComponent* Root;

	UFUNCTION(BlueprintCallable)
		void SpawnPillars();

public:	
	// Sets default values for this actor's properties
	APillars();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
