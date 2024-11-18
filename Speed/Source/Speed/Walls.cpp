// Fill out your copyright notice in the Description page of Project Settings.


#include "Walls.h"
#include "Kismet/GameplayStatics.h"
#include "SpeedCharacter.h"

// Sets default values
AWalls::AWalls()
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

void AWalls::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AWalls::OnOverlapBegin);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &AWalls::OnOverlapEnd);
}
void AWalls::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor == nullptr)
		return;
	UE_LOG(LogTemp, Warning, TEXT("Begin: %"), *OtherActor->GetName())

		ASpeedCharacter* Character = Cast<ASpeedCharacter>(OtherActor);
	if (Character != nullptr)
	{
			/*Character->SetSlowSpeed();
			TimeToFall = 5.0f;*/
			IsPlayerInside = true;
	}
}

void AWalls::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr)
		return;
	UE_LOG(LogTemp, Warning, TEXT("End: %"), *OtherActor->GetName())

		ASpeedCharacter* Character = Cast<ASpeedCharacter>(OtherActor);
	if (Character != nullptr)
	{
		IsPlayerInside = false;
	//Character->SetNormalSpeed();

	}

}

//// Called when the game starts or when spawned
void AWalls::BeginPlay()
{
	Super::BeginPlay();


}
//
//// Called every frame
void AWalls::Tick(float DeltaTime)
{
	Supr::Tick(DeltaTime);

	if (IsPlayerInside)
	{
		TimeToFall -= DeltaTime;
		if (TimeToFall <= 0.0f)
		{
			IsPlayerInside = false;
		}
	}

}

