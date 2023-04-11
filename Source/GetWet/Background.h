// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "Background.generated.h"

UCLASS()
class GETWET_API ABackground : public AActor
{
	GENERATED_BODY()

protected:
	//UPROPERTY(EditAnywhere, Category = Sprites)
	//	class UPaperSpriteComponent* Background1;
public:	
	// Sets default values for this actor's properties
	ABackground();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
