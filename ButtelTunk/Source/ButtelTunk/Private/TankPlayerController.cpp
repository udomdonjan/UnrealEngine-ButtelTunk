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


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


