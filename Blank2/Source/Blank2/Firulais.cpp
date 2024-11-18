// Fill out your copyright notice in the Description page of Project Settings.


#include "Firulais.h"

// Sets default values
AFirulais::AFirulais()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocidad = 0.0f;
	Tiempo = 0.0f;
	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;
}

// Called when the game starts or when spawned
void AFirulais::BeginPlay()
{
	Super::BeginPlay();

	
}	

// Called every frame
void AFirulais::Tick(float DeltaTime)
{  
	
	Tiempo += DeltaTime;
	Super::Tick(DeltaTime);
	float MCcombo = Velocidad * Tiempo;
	FRotator NewRotation = FRotator(PitchValue, YawValue, RollValue);
	NewRotation.Pitch *= MCcombo;
	NewRotation.Yaw *= MCcombo;
	NewRotation.Roll *= MCcombo;
	SetActorRotation(NewRotation);
}

