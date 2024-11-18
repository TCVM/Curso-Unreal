// Fill out your copyright notice in the Description page of Project Settings.


#include "FastWall.h"
#include "Kismet/GameplayStatics.h"
#include "FastestChar.h"


// Sets default values
AFastWall::AFastWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BoxComp = CreateDefaultSubobject<UBoxComponent>("Colision");
	BoxComp->SetBoxExtent(FVector(X, Y, Z));
	BoxComp->SetCollisionProfileName(TEXT("Wall"));
	BoxComp->SetGenerateOverlapEvents(true);
	RootComponent = BoxComp;

	IsPlayerInside = false;

}

void AFastWall::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AFastWall::OnOverlapBegin);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &AFastWall::OnOverlapEnd);
}
void AFastWall::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr)
		return;
	UE_LOG(LogTemp, Warning, TEXT("Begin: %"), *OtherActor->GetName())

		AFastestChar* Character = Cast<AFastestChar>(OtherActor);
	if (Character != nullptr)
	{
		Character->SetSlowSpeed();
		TimeToFall = 1.0f;
		IsPlayerInside = true;
	}
}

void AFastWall::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr)
		return;
	UE_LOG(LogTemp, Warning, TEXT("End: %"), *OtherActor->GetName())

		AFastestChar* Character = Cast<AFastestChar>(OtherActor);
	if (Character != nullptr)
	{
		IsPlayerInside = false;
		Character->SetNormalSpeed();

	}

}


// Called when the game starts or when spawned
void AFastWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFastWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPlayerInside)
	{
		TimeToFall -= DeltaTime;
		if (TimeToFall <= 0.0f)
		{
			IsPlayerInside = false;
		}
	}


}

