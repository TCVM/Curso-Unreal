// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AFirstCharacter::AFirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

}

// Called when the game starts or when spawned
void AFirstCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

//
//void AFirstCharacter::MoveForward(float Value)
//{
//	AController* Control = GetController();
//	if ((GetController() != nullptr) && (!FMath::IsNearlyZero(Value)))
//	{
//		FRotator Rotation = Control->GetControlRotation();
//		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
//		FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
//		AddMovementInput(Forward, Value);
//	}
//}
//
//void AFirstCharacter::MoveRight(float Value)
//{
//	AController* Control = GetController();
//	if ((GetController() != nullptr) && (!FMath::IsNearlyZero(Value)))
//	{
//		FRotator Rotation = Control->GetControlRotation();
//		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
//		FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
//		AddMovementInput(Right, Value);
//	}
//}


// Called every frame
void AFirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

