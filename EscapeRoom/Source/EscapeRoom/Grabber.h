// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

#define OUT

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		AActor* _itemToGrab;
	UPROPERTY(EditAnywhere)
		float _grabReach = 120.0f;
	UInputComponent* _inputComponent;
	UPhysicsHandleComponent* _physicsHandle;

	void Grab();
	void Release();
	void FindAndStoreRefrencesToComponentsNeededToGrab();
	void FindAndStoreReferenceToInputComponent();
	void FindAndStoreReferenceToPhysicsHandleComponent();
	void BindGrabAndRelaseActions();
	FHitResult GetFirstPhysicsBodyInReach();
	void MoveGrabbedComponent();
	void GetLineTraceCoordinates(OUT FVector& startingCoordinate, OUT FVector& endingCoordinate);
	void GetLineTraceStartPoint(OUT FVector& startingCoordinate);
	void GetLineTraceEndPoint(OUT FVector& endingCoordinate);
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
