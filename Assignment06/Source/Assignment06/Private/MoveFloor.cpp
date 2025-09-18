// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveFloor.h"

// Sets default values
AMoveFloor::AMoveFloor()
{
	PrimaryActorTick.bCanEverTick = true;
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComp->SetupAttachment(SceneComp);
	MoveSpeed = 90.0f;
	MaxRange = 300.0f;

}

// Called when the game starts or when spawned
void AMoveFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		StartLocation = GetActorLocation();
		if (StartLocation.Y >= MaxRange || StartLocation.Y < 0.0f)
		{
			MoveSpeed *= -1;
		}
		AddActorLocalOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.0f));
	}
}

