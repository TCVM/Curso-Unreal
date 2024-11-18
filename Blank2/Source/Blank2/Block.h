// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "NeverPawn.h"
#include "Block.generated.h"

UCLASS()
class BLANK2_API ABlock : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Pawncito)
		USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere, Category = Pawncito)
		UStaticMeshComponent* SphereVisual;

	UPROPERTY(EditAnywhere, Category = Pawncito)
		UNeverPawn* MoveComponent;

	UPROPERTY(EditAnywhere, Category = Pawncito)
		UCameraComponent* CamComponent;

	UPROPERTY(EditAnywhere, Category = Pawncito)
		USpringArmComponent* SpringComponent;

	UPROPERTY(EditAnywhere, Category = Pawncito)
	float Time;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveFrontal(float AxisValue);
	void MoveLateral(float AxisValue);
	void Turn(float AxisValue);
	void Up(float AxisValue);
};
