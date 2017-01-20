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

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) //Side-effect: it is going to ray-trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Location: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}

}

///Get world location of linetrace through crosshair, if true hits landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find crosshair pos in px coords  
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	auto ScreenLocation = FVector2D(ViewPortSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation);

	// deproject screen pos of cursor to world direction
	//line trace along look direction - see what we hit
	return true;
}

