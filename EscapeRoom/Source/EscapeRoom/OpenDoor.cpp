// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Components/PrimitiveComponent.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	if (!_pressurePlate)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s - %s: There's no pressure plate assigned!"), *GetOwner()->GetActorLabel(), *this->GetName());
	}

	_closedAngle = GetOwner()->GetActorRotation().Yaw;
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!_pressurePlate)
	{
		return;
	}

	if (GetMassOfActorsOnPressurePlate() > _pressurePlateWeigthThreshold)
	{
		OpenDoor();
	}
	else
	{
		CloseDoor();
	}
}

void UOpenDoor::OpenDoor()
{
	auto yaw = _openAngle;
	float roll = GetOwner()->GetActorRotation().Roll;
	float pitch = GetOwner()->GetActorRotation().Pitch;
	GetOwner()->SetActorRotation(FRotator(pitch, yaw, roll));
}

void UOpenDoor::CloseDoor()
{
	auto yaw = _closedAngle;
	float roll = GetOwner()->GetActorRotation().Roll;
	float pitch = GetOwner()->GetActorRotation().Pitch;
	GetOwner()->SetActorRotation(FRotator(pitch, yaw, roll));
}

float UOpenDoor::GetMassOfActorsOnPressurePlate()
{
	float totalMass = 0.0;

	TArray<AActor*> overlappingActors;
	_pressurePlate->GetOverlappingActors(overlappingActors);
	
	for (const auto& actor : overlappingActors)
	{
		totalMass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return totalMass;
}

