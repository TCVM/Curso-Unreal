// Fill out your copyright notice in the Description page of Project Settings.

#include "Nothing.h"

// Sets default values
ANothing::ANothing()
{	BoxComp = CreateDefaultSubobject<UBoxComponent>("Colision");
	BoxComp->SetBoxExtent(FVector(30.0f, 30.0f, 30.0f));
	BoxComp->SetCollisionProfileName(TEXT("Item"));
	RootComponent = BoxComp;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//IsGrowing = true;
	//ScaleSpeed = 1.0f;
	//ScaleMax = 3.0f;
	//ScaleMin = 1.0f;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Malla");
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	ScaleSpeed = 1.0f;
	Amplitude = 0.2f;
	RotSpeed = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void ANothing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANothing::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	//FVector escala = GetActorScale3D();

	//if (escala.X > ScaleMax)
		//IsGrowing = false;
	//if (escala.X < ScaleMin)
		//IsGrowing = true;
	//if (IsGrowing)
	//{
		//escala += FVector::OneVector * ScaleSpeed * DeltaTime;

	//}
	//else
	//{
		//escala -= FVector::OneVector * ScaleSpeed * DeltaTime;
	//}

	//SetActorScale3D(escala);

	FVector escala = GetActorScale3D();
	TotalTime += DeltaTime;
	escala = FVector::OneVector + Amplitude * FMath::Sin(TotalTime * ScaleSpeed);
	SetActorScale3D(escala);

	FRotator rot = GetActorRotation();
	rot.Roll += RotSpeed.X * DeltaTime;
	rot.Pitch += RotSpeed.Y * DeltaTime;
	rot.Yaw += RotSpeed.Z * DeltaTime;
	SetActorRotation(rot);
	

}

