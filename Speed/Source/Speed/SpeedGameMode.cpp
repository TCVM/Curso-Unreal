// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SpeedGameMode.h"
#include "SpeedHUD.h"
#include "SpeedCharacter.h"
#include "ControllerSpeed.h"
#include "UObject/ConstructorHelpers.h"

ASpeedGameMode::ASpeedGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PlayerControllerClass = AControllerSpeed::StaticClass();

	// use our custom HUD class
	HUDClass = ASpeedHUD::StaticClass();
}
