// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();
    HUD = CreateWidget(this, HUDClass);
          //If not a null pointer add to widget viewport
    if(HUD != nullptr)
      {
          HUD->AddToViewport();
      }
}
void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    HUD->RemoveFromViewport();
    //if user winner display win widget else display loser
    if(bIsWinner)
    {
       UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
       //If not a null pointer add to widget viewport
       if(WinScreen != nullptr)
       {
           WinScreen->AddToViewport();
       }
    }
    else
    {
        //user lost widget
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        //If not a null pointer add to widget viewport
        if(LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }
    
    
//    UE_LOG(LogTemp, Warning, TEXT("GAME OVER"));
    //get timer and execute level restart after timer delay
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}


