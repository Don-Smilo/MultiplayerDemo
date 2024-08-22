// Fill out your copyright notice in the Description page of Project Settings.


#include "InGamePlayerController.h"
#include "InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include <EnhancedInputSubsystems.h>

void AInGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AInGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AInGamePlayerController::TogglePause);
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("Input Component NOT FOUND"));
	}
}

void AInGamePlayerController::TogglePause(const FInputActionValue& Value)
{
	AInGameHUD* InGameHud = Cast<AInGameHUD>(GetHUD());
	if (InGameHud)
	{
		if (!bIsPaused)
		{
			InGameHud->PauseMenuShow();
		}

		else
		{
			InGameHud->PauseMenuHide();
		}

		bIsPaused = !bIsPaused;
	}
}
