// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be last include

/**
 * 
 */
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

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333f;
	
};
