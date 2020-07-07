// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::BeginPlay()
{
    //at begginning of play get pawn then SetFocus method to Pawn
    Super::BeginPlay();
    //AI
    if(AIBehavior != nullptr)
    {
        //run behavior tree
        RunBehaviorTree(AIBehavior);
        //get playerpawn
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
        //get blackboard then set playerlocation to blackboard
        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        
    };
}
void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    //get pawn
//    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
//    //navigation
//    
//    
//    //if line of sight
//    if(LineOfSightTo(PlayerPawn))
//    {
//        //set focus
//        SetFocus(PlayerPawn);
//        //move to
//        MoveToActor(PlayerPawn, AcceptanceRadius);
//        
//    }
//    else
//    {
//        //clearFocus
//        ClearFocus(EAIFocusPriority::Gameplay);
//        //stop movement
//        StopMovement();
//    }
//        
      
}
