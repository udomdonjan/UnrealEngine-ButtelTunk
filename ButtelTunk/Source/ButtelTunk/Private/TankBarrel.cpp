// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtelTunk.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// then move the barrel right amount this frame
	//given max elevation speed, at this frame
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel-Elevate called at speed %f"), Time, RelativeSpeed);
}


