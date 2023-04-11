// Fill out your copyright notice in the Description page of Project Settings.


#include "PW_Fish.h"

// Sets default values
APW_Fish::APW_Fish()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	Mesh->BodyInstance.bLockXTranslation = true;
	Mesh->BodyInstance.bLockYTranslation = true;
	Mesh->BodyInstance.bLockXRotation = true;
	Mesh->BodyInstance.bLockYRotation = true;
	Mesh->BodyInstance.bLockZRotation = true;
	

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(Mesh);
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SocketOffset = FVector(0, 400, 0);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void APW_Fish::BeginPlay()
{
	Super::BeginPlay();
	
	Mesh->SetSimulatePhysics(true);
	Mesh->BodyInstance.bNotifyRigidBodyCollision = true;
	Mesh->OnComponentHit.AddDynamic(this, &APW_Fish::OnPillarHit);

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
}

// Called every frame
void APW_Fish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APW_Fish::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APW_Fish::Jump);
}

void APW_Fish::Jump()
{
	UE_LOG(LogTemp, Warning, TEXT("Jumping!"));

	Mesh->BodyInstance.SetLinearVelocity(FVector::UpVector*JumpForce, false);
}

void APW_Fish::OnPillarHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	FString HitActorName = OtherActor->GetFName().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Hit by %s"), *HitActorName);

	GetWorld()->GetFirstPlayerController()->SetPause(true);

	UUserWidget* WDGRetry = CreateWidget<UUserWidget>(GetGameInstance(), WidgetClass);
	WDGRetry->AddToViewport();

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}


