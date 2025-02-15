// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERDEMO_API AInGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
	void PauseMenuShow();

	UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
	void PauseMenuHide();
};
