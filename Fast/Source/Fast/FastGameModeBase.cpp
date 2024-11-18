// Fill out your copyright notice in the Description page of Project Settings.

#include "FastGameModeBase.h"
#include "FastHUD.h"
#include "FastChar.h"
#include "FastController.h"
#include "UObject/ConstructorHelpers.h"

AFastGameModeBase::AFastGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PlayerControllerClass = AFastController::StaticClass();

	// use our custom HUD class
	HUDClass = AFastHUD::StaticClass();
}
