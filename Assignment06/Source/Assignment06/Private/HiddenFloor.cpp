// Fill out your copyright notice in the Description page of Project Settings.


#include "HiddenFloor.h"

// Sets default values
AHiddenFloor::AHiddenFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComp->SetupAttachment(SceneComp);
	bVisible = true;
	ToggleInterval = 2.0f;
}

void AHiddenFloor::ToggleVisible()
{
	bVisible = !bVisible;

	SetActorHiddenInGame(!bVisible);
	SetActorEnableCollision(bVisible);
}
// Called when the game starts or when spawned
void AHiddenFloor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(ToggleTimer, this, &AHiddenFloor::ToggleVisible, ToggleInterval, true);
	
}

// Called every frame
void AHiddenFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

