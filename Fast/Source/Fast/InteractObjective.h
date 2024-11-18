// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "InteractObjective.generated.h"

class AFastestChar;
/**
 * 
 */
UCLASS()
class FAST_API AInteractObjective : public AObjective
{
	GENERATED_BODY()

public:
		virtual void Interact(AFastestChar* FastChar);
	
};
