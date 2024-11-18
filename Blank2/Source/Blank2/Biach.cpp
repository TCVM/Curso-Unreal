// Fill out your copyright notice in the Description page of Project Settings.


#include "Biach.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABiach::ABiach()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Physics
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    RootComponent = SphereComponent;
    SphereComponent->InitSphereRadius(40.0f);
    SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
    SphereComponent->SetNotifyRigidBodyCollision(true);
    SphereComponent->SetGenerateOverlapEvents(true);

    //Representación visual​
    SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual"));
    SphereVisual->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'"));

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
void ABiach::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABiach::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABiach::MoveFrontal(float AxisValue)
{
    FVector inputVector = AxisValue * GetActorForwardVector();
    MoveComponent->AddInputVector(inputVector);
    }

void ABiach::MoveLateral(float AxisValue)
{
    FVector inputVector = AxisValue * GetActorRightVector();
    MoveComponent->AddInputVector(inputVector);
    }

void ABiach::Turn(float AxisValue)
{
    FRotator NewRotation = GetActorRotation();
NewRotation.Yaw += AxisValue;
    SetActorRotation(NewRotation);
    }

void ABiach::Up(float AxisValue)
{
    FRotator NewRotation = GetActorRotation();
    NewRotation.Pitch += AxisValue;
    SetActorRotation(NewRotation);
}

void ABiach::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    SphereComponent->OnComponentHit.AddDynamic(this, &ABiach::OnHit);
    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABiach::OnOverlapBegin);
}

void ABiach::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor == nullptr)
        return;
   
    UE_LOG(LogTemp, Warning, TEXT("hit %s"), *OtherActor->GetName());
}

void ABiach::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor == nullptr)
        return;

    //OtherActor->Destroy();
}
void ABiach::SetSlowSpeed()
{
    MoveComponent->CurrentSpeed = 100.0f;
}
void ABiach::SetNormalSpeed()
{
    MoveComponent->CurrentSpeed = 300.0f;
}