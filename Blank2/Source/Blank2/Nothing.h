// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Nothing.generated.h"



UCLASS()
class BLANK2_API ANothing : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANothing();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UPROPERTY(EditAnywhere, Category = Scale)
		//float ScaleSpeed;
	//UPROPERTY(EditAnywhere, Category = Scale)
		//float ScaleMax;
	//UPROPERTY(EditAnywhere, Category = Scale)
		//float ScaleMin;

	//bool IsGrowing;

	UPROPERTY(EditAnywhere, Category = Item)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = Item)
		float ScaleSpeed;
	UPROPERTY(EditAnywhere, Category = Item)
		float Amplitude;
	UPROPERTY(EditAnywhere, Category = Item)
	float TotalTime;

	UPROPERTY(EditAnywhere, Category = Item)
		FVector RotSpeed;
	UPROPERTY(EditAnywhere, Category = Item)
		UBoxComponent* BoxComp;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};	
