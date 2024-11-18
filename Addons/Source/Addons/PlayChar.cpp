// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayChar.h"

// Sets default values
APlayChar::APlayChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

