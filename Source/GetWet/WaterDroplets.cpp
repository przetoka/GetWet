// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterDroplets.h"

void AWaterDroplets::SpawnDroplets()
{
}

// Sets default values
AWaterDroplets::AWaterDroplets()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaterDroplets::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaterDroplets::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

