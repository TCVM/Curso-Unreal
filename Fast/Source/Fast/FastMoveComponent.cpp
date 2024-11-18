// Fill out your copyright notice in the Description page of Project Settings.


#include "FastMoveComponent.h"

void UFastMoveComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);



	FVector movimiento = ConsumeInputVector() * DeltaTime * MaxWalkSpeed;

	if (!movimiento.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(movimiento, UpdatedComponent->GetComponentRotation(), true, Hit);
	}
}