// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_FlatFish.h"

APC_FlatFish::APC_FlatFish()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APC_FlatFish::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FlatFish Character."));
}

void APC_FlatFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APC_FlatFish::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APC_FlatFish::Jump);
}

void APC_FlatFish::Jump()
{
}



