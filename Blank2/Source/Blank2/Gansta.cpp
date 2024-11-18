// Fill out your copyright notice in the Description page of Project Settings.


#include "Gansta.h"
#include "UObject/ConstructorHelpers.h"
#include "time.h"

// Sets default values
AGansta::AGansta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Creando el objeto"));
	srand(time(NULL));
	Velocidad = 100.0f;
	Tiempo = 0.0f;
	Random = rand() % 3 + 1;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");

	if (Random == 1) 
	{
		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_TableRound.SM_TableRound'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
	}
	if (Random == 2)
	{
		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
	}
	if (Random == 3)
	{
		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
	}
	
}

// Called when the game starts or when spawned
void AGansta::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("comienza el juego"));
}

// Called every frame
void AGansta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Tick"));
	FVector NewLocation=GetActorLocation();
	float DeltaHeight = FMath::Sin(Velocidad * (Tiempo + DeltaTime)) - FMath::Sin(Velocidad * Tiempo);
	NewLocation.Z += DeltaHeight * 20.0f;
	//NewLocation.X += DeltaHeight * 20.0f;
	//NewLocation.Y += DeltaHeight * 20.0f;
	Tiempo += DeltaTime;
	SetActorLocation(NewLocation);

	UE_LOG(LogTemp, Warning, TEXT("La posicion en Z es %f"), NewLocation.Z);
}

