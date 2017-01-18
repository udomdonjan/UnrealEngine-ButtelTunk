// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtelTunk.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not got A Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Got A Tank: %s"), *ControlledTank->GetName());
	}

}

void ATankPlayerController::Tick( float DeltaTime )
{

	Super::Tick( DeltaTime );

	AimTowardsCrosshair();

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//get world location of linetrace through crosshair
	//if it gits the landscape
		//tell controlled tank to aim at this point
}


