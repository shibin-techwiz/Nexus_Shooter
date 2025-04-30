// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TP_ShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TP_SHOOTER_API ATP_ShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
 
   virtual void PawnKilled(APawn* PawnKilled);
	
};
