// Copyright Epic Games, Inc. All Rights Reserved.


#include "RafalPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "RafalCameraManager.h"

ARafalPlayerController::ARafalPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ARafalCameraManager::StaticClass();
}

void ARafalPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
