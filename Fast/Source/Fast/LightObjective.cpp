// Fill out your copyright notice in the Description page of Project Settings.


#include "LightObjective.h"
#include "FastestChar.h"
#include "Kismet/GameplayStatics.h"

void ALightObjective::Interact(AFastestChar* FastChar)
{
	
	FastChar->AddKey(KeyName);
	Destroy();

}