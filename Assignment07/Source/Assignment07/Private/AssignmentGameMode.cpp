// Fill out your copyright notice in the Description page of Project Settings.


#include "AssignmentGameMode.h"
#include "AssignmentPawn.h"
#include "AssignmentPlayerController.h"

AAssignmentGameMode::AAssignmentGameMode()
{
	DefaultPawnClass = AAssignmentPawn::StaticClass();
	PlayerControllerClass = AAssignmentPlayerController::StaticClass();
}
