// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	//Colision
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	//Movimiento
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->bOrientRotationToMovement = true;
	Movement->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	Movement->JumpZVelocity = 600.0f;
	Movement->AirControl = 0.2f;

	//Camara
	CameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraSpring->SetupAttachment(RootComponent);
	CameraSpring->TargetArmLength = 300.0f;
	CameraSpring->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraSpring, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Control
void APlayerCharacter::MoveRight(float Value)
{
	AController* Control = GetController();
	if ((GetController() != nullptr) && (!FMath::IsNearlyZero(Value)))
	{
		FRotator Rotation = Control->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Forward, Value);
	}
}

void APlayerCharacter::MoveForward(float Value)
{
	AController* Control = GetController();
	if ((GetController() != nullptr) && (!FMath::IsNearlyZero(Value)))
	{
		FRotator Rotation = Control->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Right, Value);
	}
}

