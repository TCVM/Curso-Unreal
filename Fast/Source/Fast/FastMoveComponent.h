// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FastMoveComponent.generated.h"

/**
 * 
 */
UCLASS()
class FAST_API UFastMoveComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	

public:

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);
};
