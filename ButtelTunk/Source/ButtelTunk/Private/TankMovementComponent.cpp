// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtelTunk.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	//TODO Prevent double speed due to dual control use.
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward throw: %f"), Throw)

}

