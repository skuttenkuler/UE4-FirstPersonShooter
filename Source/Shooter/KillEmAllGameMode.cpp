// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

void AKillEmAllGameMode::PawnKilled(APawn* Pawnkilled)
{
    Super::PawnKilled(Pawnkilled);
    
    //check if pawn is player controller
    APlayerController* PlayerController = Cast<APlayerController>(Pawnkilled->GetController());
    if(PlayerController != nullptr)
    {
        EndGame(false);
    }
}
    
void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    //return range obj that goes over controllers in level
    //loop over every controller in level
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        //determine whether player is winner or AI is winner
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        //put focus of player controller
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);

//        if (bIsPlayerWinner)
//        {
//            Controller->GameHasEnded(nullptr, bIsPlayerController)
//        }
//        else
//        {
//            Controller->GameHasEnded(nullptr, !bIsPlayerController)
//        }
    }
}

