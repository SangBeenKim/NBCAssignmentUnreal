// Fill out your copyright notice in the Description page of Project Settings.


#include "AssignmentPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Gameframework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "AssignmentPlayerController.h"
#include "EnhancedInputComponent.h"

// Sets default values
AAssignmentPawn::AAssignmentPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootCapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(RootCapsuleComp);

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComp->SetupAttachment(RootCapsuleComp);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComp->SetupAttachment(RootCapsuleComp);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = false;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	LookSensitive = 1.0f;
	MoveSpeed = 5.0f;
}

// Called when the game starts or when spawned
void AAssignmentPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAssignmentPawn::Move(const FInputActionValue& value)
{
	if (!Controller) return;

	const FVector2D MoveInput = value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddActorLocalOffset(FVector(MoveInput.X * MoveSpeed, 0.0f, 0.0f));
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddActorLocalRotation(FRotator(0.0f, MoveInput.Y * MoveSpeed, 0.0f));
	}
}

void AAssignmentPawn::Look(const FInputActionValue& value)
{

	FVector2D LookInput = value.Get<FVector2D>();
	FRotator Rotation = SpringArmComp->GetRelativeRotation();
	
	Rotation.Yaw += LookInput.X * LookSensitive;
	Rotation.Pitch = FMath::Clamp(Rotation.Pitch + LookInput.Y * LookSensitive, -80.0f, 80.0f);
	SpringArmComp->SetRelativeRotation(Rotation);
}

// Called every frame
void AAssignmentPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAssignmentPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AAssignmentPlayerController* PlayerController = Cast<AAssignmentPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &AAssignmentPawn::Move);
			}

			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(PlayerController->LookAction, ETriggerEvent::Triggered, this, &AAssignmentPawn::Look);
			}
		}
	}
}

