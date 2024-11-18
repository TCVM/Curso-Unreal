// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractObjective.h"
#include "Components/BoxComponent.h"
#include "LightObjective.generated.h"

/**
 * 
 */
UCLASS()
class FAST_API ALightObjective : public AInteractObjective
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Objective)
		FString KeyName;
	
		

	void Interact(AFastestChar* FastChar) override;
};
