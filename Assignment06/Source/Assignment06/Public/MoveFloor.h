// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveFloor.generated.h"

UCLASS()
class ASSIGNMENT06_API AMoveFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveFloor();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "C++Classes|RootComponent")
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Classes|StaticMeshComponent")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Classes|Variables")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Classes|Variables")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Classes|Variables")
	float MaxRange;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
