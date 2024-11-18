// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectZone.h"
#include "Biach.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEffectZone::AEffectZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>("Colision");
	BoxComp->SetBoxExtent(FVector(30.0f, 30.0f, 30.0f));
	BoxComp->SetCollisionProfileName(TEXT("Item"));
	BoxComp->SetGenerateOverlapEvents(true);
	RootComponent = BoxComp;

	IsPlayerInside = false;
}
void AEffectZone::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AEffectZone::OnOverlapBegin);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &AEffectZone::OnOverlapEnd);
 }
void AEffectZone::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr)
		return;
	UE_LOG(LogTemp, Warning, TEXT("Begin: %"), *OtherActor->GetName())

	ABiach* pawn = Cast<ABiach>(OtherActor);
	if (pawn != nullptr)
	{
		pawn->SetSlowSpeed();
		TimeToDie = 5.0f;
		IsPlayerInside = true;
	}
}
void AEffectZone::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr)
		return;
	UE_LOG(LogTemp, Warning, TEXT("End: %"), *OtherActor->GetName())
	
	ABiach* pawn = Cast<ABiach>(OtherActor);
	if (pawn != nullptr)
	{
		IsPlayerInside = false;
		pawn->SetNormalSpeed();
		
	}
}

// Called when the game starts or when spawned
void AEffectZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEffectZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(IsPlayerInside)
	{
		TimeToDie -= DeltaTime;
		if (TimeToDie <= 0.0f)
		{
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
	}
}

