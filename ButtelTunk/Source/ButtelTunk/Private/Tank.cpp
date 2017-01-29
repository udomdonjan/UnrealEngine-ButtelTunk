// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtelTunk.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void ATank::SetBarrelReferance(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReferance(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReferance(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReferance(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrel) { return; }

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
	);

	Projectile->LaunchProjectile(LaunchSpeed);

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
}

