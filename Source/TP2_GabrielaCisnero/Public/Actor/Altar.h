// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractInterface.h"
#include "TimerManager.h"
#include "Altar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAltarActivado);

UCLASS()
class AAltar : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAltar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact_Implementation(AActor* Interactor) override;
	
	UPROPERTY(BlueprintAssignable)
	FOnAltarActivado OnAltarActivado;
	
private:

UPROPERTY(EditAnywhere)
float TiempoActivacion = 3.f;

bool bActivado = false;

FTimerHandle TimerHandle;

void ActivarAltar();
};
