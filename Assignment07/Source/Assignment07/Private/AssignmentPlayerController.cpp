// Fill out your copyright notice in the Description page of Project Settings.


#include "AssignmentPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAssignmentPlayerController::AAssignmentPlayerController() : InputMappingContext(nullptr), MoveAction(nullptr), LookAction(nullptr)
{
}

void AAssignmentPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}
