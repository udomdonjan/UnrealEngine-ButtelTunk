// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; // Forward declaration 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUTTELTUNK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReferance(UTankBarrel* BarrelToSet);

	//TODO add setTurrentReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:

	UTankBarrel* Barrel = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);

};
