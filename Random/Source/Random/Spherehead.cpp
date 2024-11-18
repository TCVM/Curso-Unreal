// Fill out your copyright notice in the Description page of Project Settings.


#include "Spherehead.h"

// Sets default values
ASpherehead::ASpherehead()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpherehead::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame 
void ASpherehead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

