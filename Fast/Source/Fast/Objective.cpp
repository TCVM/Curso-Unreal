// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"

// Sets default values
AObjective::AObjective()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>("Colision");
	BoxComp->SetBoxExtent(FVector(X, Y, Z));
	BoxComp->SetCollisionProfileName(TEXT("Objective"));
	BoxComp->SetGenerateOverlapEvents(true);
	RootComponent = BoxComp;
	RotSpeed = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AObjective::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjective::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat quat = GetActorQuat();

	FQuat rotX(FVector::ForwardVector, 0.1f * RotSpeed.X * DeltaTime);
	FQuat rotY(FVector::RightVector, 0.1f * RotSpeed.Y * DeltaTime);
	FQuat rotZ(FVector::UpVector, 0.1f * RotSpeed.Z * DeltaTime);
	
	quat = quat * rotX * rotY * rotZ;

	SetActorRotation(quat);
}

