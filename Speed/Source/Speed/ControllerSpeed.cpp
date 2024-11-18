// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerSpeed.h"
#include "SpeedCharacter.h"
#include "Components/InputComponent.h"
#include "SpeedProjectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h"


void AControllerSpeed::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Bind jump events
	InputComponent->BindAction("Jump", IE_Pressed, this, &AControllerSpeed::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AControllerSpeed::StopJumping);

	// Bind fire event
	InputComponent->BindAction("Fire", IE_Pressed, this, &AControllerSpeed::OnFire);

	// Bind movement events
	InputComponent->BindAxis("MoveForward", this, &AControllerSpeed::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AControllerSpeed::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &AControllerSpeed::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AControllerSpeed::AddControllerPitchInput);
}

//void AControllerSpeed::OnFire()
//{
//	// try and fire a projectile
//	if (ProjectileClass != NULL)
//	{
//		UWorld* const World = GetWorld();
//		if (World != NULL)
//		{
//			if (bUsingMotionControllers)
//			{
//				const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
//				const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
//				World->SpawnActor<ASpeedProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
//			}
//			else
//			{
//				const FRotator SpawnRotation = GetControlRotation();
//				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
//				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
//
//				//Set Spawn Collision Handling Override
//				FActorSpawnParameters ActorSpawnParams;
//				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
//
//				// spawn the projectile at the muzzle
//				World->SpawnActor<ASpeedProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
//			}
//		}
//	}
//
//	// try and play the sound if specified
//	if (FireSound != NULL)
//	{
//		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
//	}
//
//	// try and play a firing animation if specified
//	if (FireAnimation != NULL)
//	{
//		// Get the animation object for the arms mesh
//		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
//		if (AnimInstance != NULL)
//		{
//			AnimInstance->Montage_Play(FireAnimation, 1.f);
//		}
//	}
//}

void AControllerSpeed::MoveForward(float Value)
{
	ASpeedCharacter* Control = Cast<ASpeedCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveForward(Value);
	}
}
void AControllerSpeed::MoveRight(float Value)
{
	ASpeedCharacter* Control = Cast<ASpeedCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveRight(Value);
	}
}

void AControllerSpeed::Jump()
{
	ASpeedCharacter* Control = Cast<ASpeedCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->Jump();
	}
}
void AControllerSpeed::StopJumping()
{
	ASpeedCharacter* Control = Cast<ASpeedCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->StopJumping();
	}
}
void AControllerSpeed::AddControllerYawInput(float Value)
{
	ASpeedCharacter* Control = Cast<ASpeedCharacter>(GetPawn());

	if (Control != nullptr)
	{
		AddYawInput(Value);
	}
}
void AControllerSpeed::AddControllerPitchInput(float Value)
{
	ASpeedCharacter* Control = Cast<ASpeedCharacter>(GetPawn());

	if (Control != nullptr)
	{
		AddPitchInput(Value);
	}
}
void AControllerSpeed::OnFire()
{
	ASpeedCharacter* Control = Cast<ASpeedCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->OnFire();
	}
}
