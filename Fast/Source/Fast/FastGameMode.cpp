// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FastGameMode.h"
#include "FastHUD.h"
#include "FastCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFastGameMode::AFastGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFastHUD::StaticClass();
}
