// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puerta.generated.h"

UCLASS()
class TP2_GABRIELACISNERO_API APuerta : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuerta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame

private:
	
	FTimerHandle TimerPuerta;
	
	UPROPERTY(EditAnywhere)
	float TiempoApertura = 5.f;
	
	UPROPERTY(EditAnywhere)
	int AltaresActivados = 0;
	
	UPROPERTY(EditAnywhere)
	int AltaresNecesarios = 3;
	
	UFUNCTION()
	void AltarActivado();
	UFUNCTION()
	void AbrirPuerta();
};
