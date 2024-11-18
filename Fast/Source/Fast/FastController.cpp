// Fill out your copyright notice in the Description page of Project Settings.


#include "FastController.h"
#include "FastestChar.h"
#include "FastProjectile.h"


void AFastController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Bind jump events
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFastController::WallJump);
	//InputComponent->BindAction("Jump", IE_Released, this, &AFastController::StopJumping);

	// Bind fire event
	InputComponent->BindAction("Fire", IE_Pressed, this, &AFastController::OnFire);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AFastController::Interact);

	// Bind movement events
	InputComponent->BindAxis("MoveForward", this, &AFastController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFastController::MoveRight);

	// "turn" handles devices that provide an absolute delta, such as a mouse.
	InputComponent->BindAxis("Turn", this, &AFastController::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AFastController::AddControllerPitchInput);
}

void AFastController::MoveForward(float Value)
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveForward(Value);
	}
}
void AFastController::MoveRight(float Value)
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveRight(Value);
	}
}

void AFastController::Jump()
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		Control->Jump();
	}
}
void AFastController::WallJump()
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		Control->WallJump();
	}
}
void AFastController::StopJumping()
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		Control->StopJumping();
	}
}
void AFastController::AddControllerYawInput(float Value)
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		AddYawInput(Value);
	}
}
void AFastController::AddControllerPitchInput(float Value)
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		AddPitchInput(Value);
	}
}
void AFastController::OnFire()
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		Control->OnFire();
	}
}
void AFastController::Interact()
{
	AFastestChar* Control = Cast<AFastestChar>(GetPawn());

	if (Control != nullptr)
	{
		Control->Interact();
	}
}