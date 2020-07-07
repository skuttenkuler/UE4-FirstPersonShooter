// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"


UCLASS()
class SHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
    
    void PullTrigger();
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
private:
    UPROPERTY(VisibleAnywhere)
    USceneComponent* Root;
    
    UPROPERTY(VisibleAnywhere)
    USkeletalMeshComponent* Mesh;
    //gun flash
    UPROPERTY(EditAnywhere)
    UParticleSystem* MuzzleFlash;
    //gun sound
    UPROPERTY(EditAnywhere)
    USoundBase* MuzzleSound;
    //impact
    UPROPERTY(EditAnywhere)
    UParticleSystem* ImpactEffect;
    //impact sound
    UPROPERTY(EditAnywhere)
    USoundBase* ImpactSound;
    
    UPROPERTY(EditAnywhere)
    float MaxRange = 1000;
    
    UPROPERTY(EditAnywhere)
    float Damage = 10;
    
    
    bool GunTrace(FHitResult &Hit, FVector& ShotDirection);
    AController* GetOwnerController() const;


};
