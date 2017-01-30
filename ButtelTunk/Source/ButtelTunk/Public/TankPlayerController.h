// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be last include

class ATank;

UCLASS()
class BUTTELTUNK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so shot 
	// would hit where the crosshair intersects the world.
	void AimTowardsCrosshair();

	// return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const; 

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
