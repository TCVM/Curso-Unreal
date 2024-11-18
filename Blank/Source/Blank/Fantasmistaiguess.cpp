// Fill out your copyright notice in the Description page of Project Settings.


#include "Fantasmistaiguess.h"
#include "GameFramework/Actor.h"
#include "Fantasmitaiguess.generated.h"

DEFINE_LOG_CATEGORY(Fantasmitaiguess);

// Sets default values
AFantasmistaiguess::AFantasmistaiguess()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Velocidad = 20.0f;
	Tiempo = 100.0f;
	Amplitud = 0.0f;

}

// Called when the game starts or when spawned
void AFantasmistaiguess::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(Fantasmitaiguess, Warning, TEXT("Esto es el begin play"));
}

// Called every frame
void AFantasmistaiguess::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Tiempo += DeltaTime;

	FVector pos = GetActorLocation();

	float DeltaHeitght = FMath::Sin(Velocidad * (Tiempo + DeltaTime))
		- FMath::Sin(Velocidad * Tiempo);
	pos.Z += Velocidad * DeltaTime * Amplitud;
	Tiempo += DeltaTime;

	SetActorLocation(pos);
}

