// Fill out your copyright notice in the Description page of Project Settings.


#include "PController.h"
#include "PlayerCharacter.h"


void APController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &APController::InputMoveForward);
	InputComponent->BindAxis("MoveRight", this, &APController::InputMoveRight);

	InputComponent->BindAxis("Turn", this, &APController::InputTurn);
	InputComponent->BindAxis("LookUp", this, &APController::InputLookUp);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APController::InputJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APController::InputStopJump);
}

void APController::InputMoveForward(float Value)
{
	APlayerCharacter* Control = Cast<APlayerCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveForward(Value);
	}
}
void APController::InputMoveRight(float Value)
{
	APlayerCharacter* Control = Cast<APlayerCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveRight(Value);
	}
}
void APController::InputJump()
{
	APlayerCharacter* Control = Cast<APlayerCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->Jump();
	}
}
void APController::InputStopJump()
{
	APlayerCharacter* Control = Cast<APlayerCharacter>(GetPawn());

	if (Control != nullptr)
	{
		Control->StopJumping();
	}
}
void APController::InputTurn(float Value)
{
	APlayerCharacter* Control = Cast<APlayerCharacter>(GetPawn());

	if (Control != nullptr)
	{
		AddYawInput(Value);
	}
}
void APController::InputLookUp(float Value)
{
	APlayerCharacter* Control = Cast<APlayerCharacter>(GetPawn());

	if (Control != nullptr)
	{
		AddPitchInput(Value);
	}
}

