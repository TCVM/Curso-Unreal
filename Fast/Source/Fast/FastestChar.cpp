// Fill out your copyright notice in the Description page of Project Settings.


#include "FastestChar.h"
#include "FastController.h"
#include "FastProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFastestChar::AFastestChar()
{
	

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f); //Preguntar
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));
	GetCapsuleComponent()->SetNotifyRigidBodyCollision(true);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	//FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	JumpHeight = 540.f;
}

// Called when the game starts or when spawned
void AFastestChar::BeginPlay()
{
	Super::BeginPlay();

	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

}

void AFastestChar::CheckInteraction()
{
	LookedTarget = nullptr;
	FVector From = GetActorLocation() + FVector(0,0,60);
	FVector To = From + FirstPersonCameraComponent->GetForwardVector() * InteractionDistance;

	//DrawDebugLine(GetWorld(), From, To, FColor::Yellow, false, 0.1f);
	
	FHitResult HitResult;
	bool Hit = GetWorld()->LineTraceSingleByChannel(HitResult, From, To, ECC_Visibility);

	if (Hit)
	{
		if (HitResult.Actor != nullptr)
		{
			LookedTarget = Cast<AInteractObjective>(HitResult.Actor);
			UE_LOG(LogTemp, Warning, TEXT("Hit con actor: %s a distancia: %.2f "), *HitResult.Actor->GetName(), HitResult.Distance);
		}
	}
}

void AFastestChar::MoveForward(float Value)
{
	AController* Control = GetController();
	if ((GetController() != nullptr) && (!FMath::IsNearlyZero(Value)))
	{
		FRotator Rotation = Control->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Forward, Value);
	}
}

void AFastestChar::MoveRight(float Value)
{
	AController* Control = GetController();
	if ((GetController() != nullptr) && (!FMath::IsNearlyZero(Value)))
	{
		FRotator Rotation = Control->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Right, Value);
	}
}
void AFastestChar::OnFire()
{
	AController* Control = GetController();
	if ((GetController() != nullptr))
	{
		// try and fire a projectile
		if (ProjectileClass != NULL)
		{
			UWorld* const World = GetWorld();
			if (World != NULL)
			{
				/*if (bUsingMotionControllers)
				{
					const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
					const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
					World->SpawnActor<AFastProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
				}
				else
				{*/
					const FRotator SpawnRotation = GetControlRotation();
					// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
					const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

					//Set Spawn Collision Handling Override
					FActorSpawnParameters ActorSpawnParams;
					ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

					// spawn the projectile at the muzzle
					World->SpawnActor<AFastProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
				//}
			}
		}

		// try and play the sound if specified
		if (FireSound != NULL)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		// try and play a firing animation if specified
		if (FireAnimation != NULL)
		{
			// Get the animation object for the arms mesh
			UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
			if (AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
		}
	}
}


void AFastestChar::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AFastestChar::OnHit);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AFastestChar::OnOverlapBegin);
}

void AFastestChar::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("hit %s"), *OtherActor->GetName());
}

void AFastestChar::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr)
		return;
	WallJumpCounter = 0;
	//OtherActor->Destroy();
}

void AFastestChar::SetSlowSpeed()
{
UCharacterMovementComponent* Movement = GetCharacterMovement();
	//Movement->MaxWalkSpeed = 100.0f;
	Movement->GravityScale = 1.0;
}
void AFastestChar::SetNormalSpeed()
{
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	//Movement->MaxWalkSpeed = 1500.0f;
	Movement->GravityScale = 1;
}

void AFastestChar::Landed(const FHitResult& Hit)
{
	WallJumpCounter = 0;
}

void AFastestChar::WallJump()
{
	if (WallJumpCounter < 1)
		ACharacter::LaunchCharacter(FVector(0, 0, JumpHeight), false, true);
	WallJumpCounter++;
}
void AFastestChar::Interact()
{
	if (LookedTarget != nullptr)
	{
	LookedTarget->Interact(this);
	Pickedup++;

	if (Pickedup == 3)
		{
			UGameplayStatics::OpenLevel(this, "MainMenu", false);
		}
	}
}

void AFastestChar::AddKey(FString KeyName) 
{
	Keys.Add(KeyName);
}

// Called every frame
void AFastestChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckInteraction();

}

// Called to bind functionality to input
void AFastestChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

