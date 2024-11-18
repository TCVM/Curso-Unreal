// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayTroller.generated.h"

/**
 * 
 */
UCLASS()
class BLANK2_API APlayTroller : public APlayerController
{
	GENERATED_BODY()
public:
	void SetupInputComponent() override;
	void MoveFrontal(float AxisValue);
	void MoveLateral(float AxisValue);
	void Turn(float AxisValue);
	void Up(float AxisValue);
};


