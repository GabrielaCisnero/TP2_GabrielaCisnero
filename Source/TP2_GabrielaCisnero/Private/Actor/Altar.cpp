// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Altar.h"
#include "TimerManager.h"
#include "Engine/Engine.h"
// Sets default values
AAltar::AAltar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAltar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAltar::Interact_Implementation(AActor* Interactor)
{
	GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Green,TEXT("Altar activado"));
	
	if (bActivado) return;
	
	GetWorldTimerManager().SetTimer(TimerHandle,this, &AAltar::ActivarAltar,TiempoActivacion,false);
}



void AAltar::ActivarAltar()
{
	bActivado = true;

	OnAltarActivado.Broadcast();
}
