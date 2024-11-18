// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Biach.h"
#include "PlayTroller.h"
#include "Charlester.h"
#include "Controlster.h"
#include "UObject/ConstructorHelpers.h"


AMyGameModeBase::AMyGameModeBase()
{
	ConstructorHelpers::FClassFinder<APawn> CharlesBP(TEXT("/Game/BP_Charlester"));
	if (CharlesBP.Succeeded())
	{
		DefaultPawnClass = CharlesBP.Class;
	}
	
	PlayerControllerClass = AControlster::StaticClass();

}
