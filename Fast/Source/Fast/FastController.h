// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FastController.generated.h"

/**
 * 
 */
UCLASS()
class FAST_API AFastController : public APlayerController
{
	GENERATED_BODY()
	

public:

	void SetupInputComponent()override;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	//	float BaseTurnRate;

	///** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	//	float BaseLookUpRate;

	/** Fires a projectile. */
	void OnFire();
	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	void Jump();

	void WallJump();

	void StopJumping();

	void AddControllerYawInput(float Value);

	void AddControllerPitchInput(float Value);

	void Interact();
};
