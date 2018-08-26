// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindAndStoreRefrencesToComponentsNeededToGrab();
	BindGrabAndRelaseActions();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//GetFirstPhysicsBodyInReach();

	if(_physicsHandle->GetGrabbedComponent())
		MoveGrabbedComponent();
}

void UGrabber::BindGrabAndRelaseActions()
{
	_inputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (_inputComponent == nullptr)
	{
		return;
	}

	_inputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	_inputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FHitResult hitResults;
	FVector lineTraceStartPoint, lineTraceEndPoint;
	GetLineTraceCoordinates(OUT lineTraceStartPoint, OUT lineTraceEndPoint);
	FCollisionQueryParams traceQueryParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(hitResults, lineTraceStartPoint, lineTraceEndPoint, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), traceQueryParameters);

	AActor* actor = hitResults.GetActor();
	if (actor)
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *actor->GetName());

	return hitResults;
}

void UGrabber::MoveGrabbedComponent()
{
	FVector newPosition;
	GetLineTraceEndPoint(newPosition);

	_physicsHandle->SetTargetLocation(newPosition);
}

void UGrabber::GetLineTraceCoordinates(OUT FVector& startingCoordinate, OUT FVector& endingCoordinate)
{
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(playerViewPointLocation, playerViewPointRotation);

	startingCoordinate = playerViewPointLocation;
	endingCoordinate = playerViewPointLocation + playerViewPointRotation.Vector() * _grabReach;
}

void UGrabber::GetLineTraceStartPoint(OUT FVector& startingCoordinate)
{
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(playerViewPointLocation, playerViewPointRotation);

	startingCoordinate = playerViewPointLocation;
}

void UGrabber::GetLineTraceEndPoint(OUT FVector& endingCoordinate)
{
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(playerViewPointLocation, playerViewPointRotation);

	endingCoordinate = playerViewPointLocation + playerViewPointRotation.Vector() * _grabReach;
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("%s: Grab called!"), *GetOwner()->GetActorLabel());

	auto componentToGrab = GetFirstPhysicsBodyInReach().GetComponent();
	if (componentToGrab)
	{
		_physicsHandle->GrabComponent(componentToGrab, FName(EName::NAME_None), componentToGrab->GetOwner()->GetActorLocation(), true);
	}

}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("%s: Release called!"), *GetOwner()->GetActorLabel());

	_physicsHandle->ReleaseComponent();
}

void UGrabber::FindAndStoreRefrencesToComponentsNeededToGrab()
{
	FindAndStoreReferenceToInputComponent();
	FindAndStoreReferenceToPhysicsHandleComponent();
}

void UGrabber::FindAndStoreReferenceToInputComponent()
{
	_inputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (_inputComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing input component"), *GetOwner()->GetName());
	}
}

void UGrabber::FindAndStoreReferenceToPhysicsHandleComponent()
{
	_physicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (_physicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing physics handle component"), *GetOwner()->GetName());
	}
}

