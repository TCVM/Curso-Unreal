// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Walls.generated.h"

UCLASS()
class SPEED_API AWalls : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWalls();

	virtual void PostInitializeComponents() override;

UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Wall)
		UBoxComponent* BoxComp;
	UPROPERTY(EditAnywhere, Category = Wall)
		float X;
	UPROPERTY(EditAnywhere, Category = Wall)
		float Y;
	UPROPERTY(EditAnywhere, Category = Wall)
		float Z;

	float TimeToFall;
	bool IsPlayerInside;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
