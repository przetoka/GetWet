// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaterDroplets.generated.h"

UCLASS()
class GETWET_API AWaterDroplets : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
		TArray<UStaticMeshComponent*> Droplets;

	UPROPERTY(EditAnywhere)
		float MoveSpeed = 100.f;

	UPROPERTY(EditDefaultsOnly)
		UStaticMesh* DropletsMesh;

	UPROPERTY(EditDefaultsOnly)
		USceneComponent* Root;

	UFUNCTION(BlueprintCallable)
		void SpawnDroplets();
	
public:	
	// Sets default values for this actor's properties
	AWaterDroplets();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
