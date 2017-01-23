// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtelTunk.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegressPerSecond)
{
	// then move the barrel right amount this frame
	//given max elevation speed, at this frame
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate called at speed %f"), DegressPerSecond);
}


