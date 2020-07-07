// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn* Pawnkilled)
{
    Super::PawnKilled(Pawnkilled);
    
    //check if pawn is player controller
    APlayerController* PlayerController = Cast<APlayerController>(Pawnkilled->GetController());
    if(PlayerController != nullptr)
    {
        PlayerController->GameHasEnded(nullptr, false);
    }
}
