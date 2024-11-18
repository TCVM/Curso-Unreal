// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Objective.generated.h"

UCLASS()
class FAST_API AObjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjective();

	UPROPERTY(EditAnywhere, Category = Objective)
		UBoxComponent* BoxComp;
	UPROPERTY(EditAnywhere, Category = Objective)
		float X;
	UPROPERTY(EditAnywhere, Category = Objective)
		float Y;
	UPROPERTY(EditAnywhere, Category = Objective)
		float Z;
	UPROPERTY(EditAnywhere, Category = Objective)
		FVector RotSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
