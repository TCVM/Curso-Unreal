// Fill out your copyright notice in the Description page of Project Settings.


#include "Controlster.h"
#include "Charlester.h"


void AControlster::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AControlster::InputMoveForward);
	InputComponent->BindAxis("MoveRight", this, &AControlster::InputMoveRight);

	InputComponent->BindAxis("Turn", this, &AControlster::InputTurn);
	InputComponent->BindAxis("LookUp", this, &AControlster::InputLookUp);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AControlster::InputJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AControlster::InputStopJump);
}

void AControlster::InputMoveForward(float Value)
{
	ACharlester* Control = Cast<ACharlester>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveForward(Value);
	}
}
void AControlster::InputMoveRight(float Value)
{
	ACharlester* Control = Cast<ACharlester>(GetPawn());

	if (Control != nullptr)
	{
		Control->MoveRight(Value);
	}
}
void AControlster::InputJump()
{
	ACharlester* Control = Cast<ACharlester>(GetPawn());

	if (Control != nullptr)
	{
		Control->Jump();
	}
}
void AControlster::InputStopJump()
{
	ACharlester* Control = Cast<ACharlester>(GetPawn());

	if (Control != nullptr)
	{
		Control->StopJumping();
	}
}
void AControlster::InputTurn(float Value)
{
	ACharlester* Control = Cast<ACharlester>(GetPawn());

	if (Control != nullptr)
{
		AddYawInput(Value);
	}
}
void AControlster::InputLookUp(float Value)
{
	ACharlester* Control = Cast<ACharlester>(GetPawn());

	if (Control != nullptr)
	{
		AddPitchInput(Value);
	}
}
