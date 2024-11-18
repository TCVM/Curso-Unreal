// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Controlster.generated.h"

/**
 * 
 */
UCLASS()
class BLANK2_API AControlster : public APlayerController
{
	GENERATED_BODY()
public:

    void SetupInputComponent()override;

    void InputMoveForward(float Value);
    void InputMoveRight(float Value);

    void InputJump();
    void InputStopJump();

    void InputTurn(float Value);
    void InputLookUp(float Value);
};
