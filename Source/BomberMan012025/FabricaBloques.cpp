// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaBloques.h"
#include "BloqueAcero.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"


// Sets default values
AFabricaBloques::AFabricaBloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the {game}ñ starts or when spawned
void AFabricaBloques::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AFabricaBloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABloque* AFabricaBloques::CrearBloque(FString tipoBloque, FVector Posicion)
{

	if (tipoBloque.Equals("Acero"))
	{
		return GetWorld()->SpawnActor<ABloqueAcero>
			(ABloqueAcero::StaticClass(), Posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Concreto"))
	{
		return GetWorld()->SpawnActor<ABloqueConcreto>
			(ABloqueConcreto::StaticClass(), Posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Ladrillo"))
	{
		return GetWorld()->SpawnActor<ABloqueLadrillo>
			(ABloqueLadrillo::StaticClass(), Posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Madera"))
	{
		return GetWorld()->SpawnActor<ABloqueMadera>
			(ABloqueMadera::StaticClass(), Posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	return nullptr;
}
