// Fill out your copyright notice in the Description page of Project Settings.


#include "NeverPawn.h"

void UNeverPawn::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector movimiento = ConsumeInputVector() * DeltaTime * CurrentSpeed;

	if (!movimiento.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(movimiento, UpdatedComponent->GetComponentRotation(), true, Hit);
	}
}