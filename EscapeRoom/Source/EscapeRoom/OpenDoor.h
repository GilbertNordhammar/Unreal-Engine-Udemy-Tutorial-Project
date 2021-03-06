// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	/*UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;*/

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* _pressurePlate;
	UPROPERTY(EditAnywhere)
		float _openAngle = 90.0;
	UPROPERTY(EditAnywhere)
		float _pressurePlateWeigthThreshold = 100.0;

	// Delegates
	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpen;
	UPROPERTY(BlueprintAssignable)
		FOnCloseRequest OnClose;

	float GetMassOfActorsOnPressurePlate();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
