// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AssignmentPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class ASSIGNMENT07_API AAssignmentPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAssignmentPlayerController();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++|Inputs")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++|Inputs")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++|Inputs")
	UInputAction* LookAction;
	
	virtual void BeginPlay() override;
};
