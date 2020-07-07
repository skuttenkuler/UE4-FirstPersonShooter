// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"


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
        
        //get blackboard then set player location to blackboard
        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        //get blackboard then set pawn location to blackboard
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    };
}
void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

bool AShooterAIController::IsDead() const
{
    //get the pawn and cast
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    //check if controlled character(pawn) is dead
    if(ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }
    return true;
}
