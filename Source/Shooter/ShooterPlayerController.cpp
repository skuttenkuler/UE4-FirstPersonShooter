// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    
    //user lost widget
    UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
    //If not a null pointer add to widget viewport
    if(LoseScreen != nullptr)
    {
        LoseScreen->AddToViewport();
    }
    
//    UE_LOG(LogTemp, Warning, TEXT("GAME OVER"));
    //get timer and execute level restart after timer delay
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
