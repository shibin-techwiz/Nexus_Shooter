// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 *
 */
UCLASS()
class TP_SHOOTER_API AKillEmAllGameMode : public ATP_ShooterGameModeBase
{
   GENERATED_BODY()

public:
   virtual void PawnKilled(APawn *PawnKilled) override;

   private:
      void EndGame(bool bIsPlayerWinner);
};



// // Fill out your copyright notice in the Description page of Project Settings.

// #pragma once

// #include "CoreMinimal.h"
// #include "GameFramework/PlayerController.h"
// #include "Blueprint/UserWidget.h"
// #include "ShooterPlayerController.generated.h"

// /**
//  *
//  */
// UCLASS()
// class TP_SHOOTER_API AShooterPlayerController : public APlayerController
// {
// 	GENERATED_BODY()

// public:
// 	void GameHasEnded(class AActor *EndGameFocus = nullptr, bool bIsWinner = false) override;

// private:
// 	UPROPERTY(EditAnywhere)
// 	TSubclassOf<UUserWidget> WinScreenClass;

// 	UPROPERTY(EditAnywhere)
// 	TSubclassOf<UUserWidget> LoseScreenClass;

// 	UPROPERTY(EditAnywhere)
// 	float RestartDelay = 5;

// 	FTimerHandle RestartTimer;
// };
