// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtelTunk.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI has no Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI has Tank: %s"), *ControlledTank->GetName());
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



