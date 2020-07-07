// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = "Update Player Location";
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    //get pawn
    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //if both are not null pointers
    if (PlayerPawn == nullptr)
    {
        return;
    }
    
    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }
    //if have line of sight, set location
    if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
   
}
