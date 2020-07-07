// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn* Pawnkilled)
{
    Super::PawnKilled(Pawnkilled);
    UE_LOG(LogTemp, Warning, TEXT("You done killed em."));
}
