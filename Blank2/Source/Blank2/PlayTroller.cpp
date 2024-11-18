// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayTroller.h"
#include "Biach.h"
#include "Components/InputComponent.h"

void APlayTroller::SetupInputComponent()
{
    Super::SetupInputComponent();

   InputComponent->BindAxis("Frontal", this, &APlayTroller::MoveFrontal);
   InputComponent->BindAxis("Lateral", this, &APlayTroller::MoveLateral);
   InputComponent->BindAxis("MouseLookX", this, &APlayTroller::Turn);
   InputComponent->BindAxis("MouseLookY", this, &APlayTroller::Up);
}

void APlayTroller::MoveFrontal(float AxisValue)
{
   
    ABiach* Biach = Cast<ABiach>(GetPawn());
    if (Biach != nullptr)
    {
        Biach->MoveFrontal(AxisValue);
    }
}
void APlayTroller::MoveLateral(float AxisValue)
{

    ABiach* Biach = Cast<ABiach>(GetPawn());
    if (Biach != nullptr)
    {
        Biach->MoveLateral(AxisValue);
    }
}
void APlayTroller::Turn(float AxisValue)
{
    
    ABiach* Biach = Cast<ABiach>(GetPawn());
    if (Biach != nullptr)
    {
        Biach->Turn(AxisValue);
    }
}
void APlayTroller::Up(float AxisValue)
{
    
    ABiach* Biach = Cast<ABiach>(GetPawn());
    if (Biach != nullptr)
    {
        Biach->Up(AxisValue);
    }
}