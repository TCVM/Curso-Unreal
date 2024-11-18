// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "NeverPawn.generated.h"

/**
 * 
 */
UCLASS()
class BLANK2_API UNeverPawn : public UPawnMovementComponent
{
	GENERATED_BODY()

public:
	
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);
	UPROPERTY(EditAnywhere, Category = NeverPawnMoveComponent)
		float CurrentSpeed = 300.0f;
};
