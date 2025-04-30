// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "kismet\GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacterr.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehavior != nullptr)
    {
        APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        RunBehaviorTree(AIBehavior);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }
}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

bool AShooterAIController::IsDead() const
{
    AShooterCharacterr *ControlledCharacter = Cast<AShooterCharacterr>(GetPawn());

    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }
    return true;
}
