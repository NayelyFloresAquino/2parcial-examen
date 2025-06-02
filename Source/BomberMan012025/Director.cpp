// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"

// Sets default values
ADirector::ADirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void ADirector::SetBuilder(TScriptInterface<IILaberintoBuilder> NuevoBuilder)
{
	Builder = NuevoBuilder; // Asignar el builder
}
void ADirector::construirlaberintodesolomuros() // esto hace que construya el laberinto o madera o lo que sea
{
	if (!Builder) return; // Verificar si el builder está asignado

	Builder->Reset(); // Reiniciar el builder antes de construir un nuevo laberinto
	Builder->buildBloqueMuros();
	Builder->buildBloqueMadera(); // Aquí puedes agregar más bloques según sea necesario
	//Builder->buildBloqueConcreto();
	//Builder->ClonarBloqueMadera(3, 5);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LABERINTOE	SPAWNEADO"));
}

// Called when the game starts or when spawned
void ADirector::BeginPlay() //
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

