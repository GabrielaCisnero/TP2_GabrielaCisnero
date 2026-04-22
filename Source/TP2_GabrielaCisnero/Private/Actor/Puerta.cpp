// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Puerta.h"
#include "Actor/Altar.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

// Sets default values
APuerta::APuerta()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APuerta::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> Altares;
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAltar::StaticClass(),Altares);
	
	for (AActor* Actor : Altares)
	{
		AAltar* Altar = Cast<AAltar>(Actor);
		if (Altar)
		{
			Altar->OnAltarActivado.AddDynamic(this,&APuerta::AltarActivado);
		}
	}
	
}

void APuerta::AltarActivado()
{
	AltaresActivados++;
	
	GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Cyan, TEXT("El altar se activo"));
	if (AltaresActivados >= AltaresNecesarios)
	{
		GetWorldTimerManager().SetTimer(TimerPuerta,this, &APuerta::AbrirPuerta,TiempoApertura,false);
	}
}

// Called every frame
void APuerta::AbrirPuerta()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Yellow, TEXT("Puerta abierta"));
	
	Destroy();
}


