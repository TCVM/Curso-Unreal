// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fantasmistaiguess.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(Fantasmitaiguess, Log, Log);

UCLASS()
class BLANK_API AFantasmistaiguess : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFantasmistaiguess();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float Tiempo;
	float Velocidad;
	float Amplitud;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
