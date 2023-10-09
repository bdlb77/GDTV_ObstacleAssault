// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move plat foward

	// get current location
	FVector CurrentLocation = GetActorLocation();

	// add vector to that location
	// CurrentLocation.Y += 1;
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
	// set location
	SetActorLocation(CurrentLocation);
	// send platform back if gone too far

	// check how far we've moved
	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved > MoveDistance)
	{
		// Get a normalized vector of Veloctity 
		FVector MoveDirectionVelocity = PlatformVelocity.GetSafeNormal();
		// calculate distance from current StartLocation (CurrLocation)
		StartLocation = StartLocation + MoveDirectionVelocity * MoveDistance;
		SetActorLocation(StartLocation);
		// Reverse Direction
		PlatformVelocity = -PlatformVelocity;
	}
	// reverse dire		cttion of motion if gone too far

}

