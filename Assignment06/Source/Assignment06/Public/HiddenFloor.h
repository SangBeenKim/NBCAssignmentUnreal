// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HiddenFloor.generated.h"

UCLASS()
class ASSIGNMENT06_API AHiddenFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHiddenFloor();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "C++Classes|RootComponent")
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Classes|StaticMeshComponent")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "C++Classes|Visible")
	bool bVisible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Classes|Visible")
	float ToggleInterval;
	FTimerHandle ToggleTimer;
	UFUNCTION()
	void ToggleVisible();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
