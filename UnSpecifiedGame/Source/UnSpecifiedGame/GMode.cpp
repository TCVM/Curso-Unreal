// Fill out your copyright notice in the Description page of Project Settings.


#include "GMode.h"
#include "PlayerCharacter.h"
#include "PController.h"
#include "UObject/ConstructorHelpers.h"

AGMode::AGMode()
{
	ConstructorHelpers::FClassFinder<APawn> PlayerBP(TEXT("/Game/BP_PlayerCharacter"));
	if (PlayerBP.Succeeded())
	{
		DefaultPawnClass = PlayerBP.Class;
	}

	PlayerControllerClass = APController::StaticClass();

}