// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Blueprint/UserWidget.h"
#include "PC_FlatFish.generated.h"


UCLASS()
class GETWET_API APC_FlatFish : public APaperCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere)
		float JumpForce = 100.f;

public:
	APC_FlatFish();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Jump() override;
};
