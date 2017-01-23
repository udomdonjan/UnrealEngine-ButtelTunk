// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS()
class BUTTELTUNK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegressPerSecond);
	
private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20; //sensible default

	
};
