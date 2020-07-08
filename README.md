# Shooter Game

A simple C++ shooter game built with Unreal Engine 4. Kill the enemies before they kill you.

![Alt text](./Images/fps_gif.gif "Preview")

## Download and Play! (Mac Only)
* [Shooter Game Download](https://drive.google.com/file/d/1xCx58DOInB2ab-Tz6o3s90EH0vwnEX89/view?usp=sharing)

## Technologies Used

* [Unreal Engine 4](https://www.unrealengine.com/en-US/)
* [C++](http://www.cplusplus.com/doc/tutorial/)


## Code Snippets

Line Tracing for bullets by getting shooter location on level and calcutlating the endpoint.

```cpp
   bool AGun::GunTrace(FHitResult &Hit,FVector& ShotDirection)
{
   AController *OwnerController = GetOwnerController();
    //if can't get a controller, can't do a gun trace
   if (OwnerController == nullptr)
       return false;
   FVector Location;
   FRotator Rotation;
   OwnerController->GetPlayerViewPoint(Location, Rotation);
   
   //origin of shot
   ShotDirection = -Rotation.Vector();
   //bullet endpoint
   FVector End = Location + Rotation.Vector() * MaxRange;

   //add paramaters(actors) that should be ignored by line trace
   FCollisionQueryParams Params;
   //owner of gun should not be hit by own gun
   Params.AddIgnoredActor(this);
   Params.AddIgnoredActor(GetOwner());
   //return result of line trace
   return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}
//method to get shooter
AController* AGun::GetOwnerController() const
{
    APawn *OwnerPawn = Cast<APawn>(GetOwner());
    if (OwnerPawn == nullptr)
        return nullptr;
    return OwnerPawn->GetController();
}
  ```

Methods to apply damage points to ShooterCharacters. If health reaches 0, initiate death animation then detach camera and gun componenets.
  ```cpp
  float AShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
    float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
    DamageToApply = FMath::Min(Health, DamageToApply);
    Health -= DamageToApply;
    UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);
    //if dead then detach controller and set the capsule collision to no collision
    if(IsDead())
    {
        //get game mode
        AShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AShooterGameModeBase>();
        if (GameMode != nullptr)
        {
            GameMode->PawnKilled(this);
        }
        DetachFromControllerPendingDestroy();
        GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
       
        

    }
    return DamageToApply;
}

  ```

# Author
  * Sam Kuttenkuler
    - [Github](https://www.github.com/skuttenkuler)
    - [LinkedIn](https://www.linkedin.com/in/skdev91)

# Map City16

[Unreal Environments](https://www.patreon.com/UnrealEnvironments?alert=2)