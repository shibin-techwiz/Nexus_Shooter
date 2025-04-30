// Fill out your copyright notice in the Description page of Project Settings.

#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn *PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

    if (PlayerController != nullptr)
    {
        EndGame(false);
    }
    // For loop over shooter AI in wordl
    // is not dead ?
    // Return
    for (AShooterAIController *Controller : TActorRange<AShooterAIController>(GetWorld()))
        if (!Controller->IsDead())
        {
            return;
        }
    EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}


// // Fill out your copyright notice in the Description page of Project Settings.

// #include "ShooterPlayerController.h"
// #include "TimerManager.h"
// #include "Blueprint/UserWidget.h"

// void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner)
// {
//     Super::GameHasEnded(EndGameFocus, bIsWinner);

//     if (bIsWinner)
//     {
//         UUserWidget *WinScreen = CreateWidget(this, WinScreenClass);

//         if (WinScreen != nullptr)
//         {
//             WinScreen->AddToViewport();
//         }
//     }
//     else
//     {
//         UUserWidget *LoseScreen = CreateWidget(this, LoseScreenClass);

//         if (LoseScreen != nullptr)
//         {
//             LoseScreen->AddToViewport();
//         }
//     }

//     GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
// }
