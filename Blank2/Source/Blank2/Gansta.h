// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gansta.generated.h"

UCLASS()
class BLANK2_API AGansta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGansta();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, Category = Test)
	float Velocidad;
	UPROPERTY(EditAnywhere, Category = GranAMV)
	float Tiempo;
	int Random;
	virtual void BeginPlay() override;
	UStaticMeshComponent* Mesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
