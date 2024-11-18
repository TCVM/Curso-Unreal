// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABlock::ABlock()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    Time = 0.0f;
    // Physics
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    RootComponent = SphereComponent;
    SphereComponent->InitSphereRadius(40.0f);
    SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

    //Representación visual​
    SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual"));
    SphereVisual->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Statue.SM_Statue'"));

    if (SphereVisualAsset.Succeeded())
    {
        SphereVisual->SetStaticMesh(SphereVisualAsset.Object);

        SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));

        SphereVisual->SetWorldScale3D(FVector(0.8f));
    }

    // Movement
    MoveComponent = CreateDefaultSubobject<UNeverPawn>("Movement");
    MoveComponent->SetUpdatedComponent(RootComponent);

    // Spring arm
    SpringComponent = CreateDefaultSubobject<USpringArmComponent>("Spring");
    SpringComponent->SetupAttachment(RootComponent);
    SpringComponent->SetRelativeRotation(FRotator(-30.f, 0.f, 0.f));
    SpringComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
    SpringComponent->TargetArmLength = 300.0f;
    SpringComponent->bEnableCameraLag = true;
    SpringComponent->bEnableCameraRotationLag = true;
    SpringComponent->CameraLagSpeed = 3.0f;

    // Camera
    CamComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
    CamComponent->SetupAttachment(SpringComponent, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABlock::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("Frontal", this, &ABlock::MoveFrontal);
    PlayerInputComponent->BindAxis("Lateral", this, &ABlock::MoveLateral);
    PlayerInputComponent->BindAxis("MouseLookX", this, &ABlock::Turn);
    //PlayerInputComponent->BindAxis("MouseLookY", this, &ASis::Up);
}
void ABlock::MoveFrontal(float AxisValue)
{
    FVector inputVector = AxisValue * GetActorForwardVector();
    MoveComponent->AddInputVector(inputVector);
}

void ABlock::MoveLateral(float AxisValue)
{
    FVector inputVector = AxisValue * GetActorRightVector();
    MoveComponent->AddInputVector(inputVector);
}

void ABlock::Turn(float Deltatime)
{
    Time = Deltatime;
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += Time;
    SetActorRotation(NewRotation);
}

void ABlock::Up(float AxisValue)
{
    FRotator NewRotation = GetActorRotation();
    NewRotation.Pitch += AxisValue;
    SetActorRotation(NewRotation);
}


