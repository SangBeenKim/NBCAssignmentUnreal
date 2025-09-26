// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateFloor.h"

// Sets default values
ARotateFloor::ARotateFloor()
{
	PrimaryActorTick.bCanEverTick = true;
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComp->SetupAttachment(SceneComp);
	RotationSpeed = 90.0f;

}

// Called when the game starts or when spawned
void ARotateFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

}

