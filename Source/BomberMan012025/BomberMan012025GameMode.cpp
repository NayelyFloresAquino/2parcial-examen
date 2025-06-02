// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan012025GameMode.h"
#include "BomberMan012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Laberinto_Concreto_1.h"
#include "Director.h"
#include "Kismet/GameplayStatics.h"
#include "FabricaBloques.h"
#include "BloqueBurbuja.h"
#include "LaberintoClon.h"


ABomberMan012025GameMode::ABomberMan012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
void ABomberMan012025GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Spawn del Builder
	ALaberinto_Concreto_1* Builder = GetWorld()->SpawnActor<ALaberinto_Concreto_1>(ALaberinto_Concreto_1::StaticClass());

	// Spawn del Director
	ADirector* Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());

	if (Builder && Director)
	{
		// Asignamos el builder al director
		Director->SetBuilder(Builder);

		Director->construirlaberintodesolomuros();


	}

	ABloqueBurbuja* prototipo = GetWorld()->SpawnActor<ABloqueBurbuja>(ABloqueBurbuja::StaticClass(), FVector(-720.0f, 250.0f, 130.0f), FRotator::ZeroRotator);
	if (prototipo)
	{
		FVector Pos = prototipo->GetActorLocation();
		FVector posicion2 = Pos + FVector(150.0f, 100.0f, 0.0f);
		float Dis = 1000.0f;
		AActor* clon = prototipo->Clonar(posicion2, Dis);

		if (clon)
		{
			clon->SetActorLocation(Pos);
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("¡Clon creado correctamente!"));

	}
	ALaberintoClon* protoripo = GetWorld()->SpawnActor<ALaberintoClon>(ALaberintoClon::StaticClass(), FVector(-720.0f, 250.0f, 130.0f), FRotator::ZeroRotator);
	{
		FVector Pos = protoripo->GetActorLocation();
		FVector posicion2 = Pos + FVector(150.0f, 100.0f, 0.0f);
		float Dis = 1000.0f;
		AActor* clon = protoripo->Clonar(posicion2, Dis);
		if (clon)
		{
			clon->SetActorLocation(Pos);
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("¡Clon creado correctamente!"));
	}




	/*
	AFabricaBloques* FabricaBloques = GetWorld()->SpawnActor<AFabricaBloques>(AFabricaBloques::StaticClass());


	ABloque* FabricaBloques = GetWorld()->Spaw
	/*


	/*
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Bloque Spawning"));

	int32 MaxAltura = 3;      // Número de capas en el eje Z
	float AlturaBloque = 100.0f; // Distancia entre capas
	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{
			int32 valor = aMapaBloques[fila][columna];

			if (valor != 0) // Si no es espacio vacío
			{
				for (int32 altura = 0; altura < MaxAltura; ++altura) // Bucle para la altura
				{
					FVector posicionBloque = FVector(XInicial + columna * AnchoBloque, YInicial + fila * LargoBloque, ZInicial + altura * AlturaBloque); // Incrementar Z

					// Llamamos a la función para generar un bloque
					SpawnBloque(posicionBloque, valor);
				}
			}
		}
	}

	*/
}
	// Recorremos la matriz para generar los bloques
	/* 

	for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{
			int32 valor = aMapaBloques[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque = FVector(
					XInicial + columna * AnchoBloque,
					YInicial + fila * LargoBloque,
					20.0f); // Z queda en 0 (altura del bloque)

				// Llamamos a la función para generar un bloque
				//SpawnBloque(posicionBloque, valor);
				switch (valor)
				{
				case 1: // Madera
					FabricaBloques->CrearBloque("Madera", posicionBloque);
					//SpawnBloque(posicionBloque, 1);
					break;
				case 2: // Ladrillo
					FabricaBloques->CrearBloque("Ladrillo", posicionBloque);
					break;
				case 3: // Concreto
					FabricaBloques->CrearBloque("Concreto", posicionBloque);
					break;
				case 4: // Acero
					FabricaBloques->CrearBloque("Acero", posicionBloque);
				default:
					break;
				}
			}
		}
	}

	//GetWorld()->GetTimerManager().SetTimer(tHDestruirBloques, this, &ABomberman_LABGameMode::DestruirBloque, 2.0f, true);
}
*/

/* 


void ABomberMan012025GameMode::SpawnBloque(FVector posicionBloque, int32 tipoBloque)
{
	
		//ABloque* BloqueGenerado = nullptr;
		ABloque* BloqueGenerado = nullptr;
		// Elegir tipo de bloque basado en el valor
		if (tipoBloque == 4)
		{
			BloqueGenerado = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		}
		else if (tipoBloque == 3)
		{
			BloqueGenerado = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		}
		else if (tipoBloque == 2)
		{
			BloqueGenerado = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		}
		else if (tipoBloque == 1)
		{
			BloqueGenerado = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
		}
		else {
			return;
		}
		// Agregar el bloque al TArray si fue generado
		if (BloqueGenerado)
		{
			aBloques.Add(BloqueGenerado);
		}
	
}
*/
/* 
void ABomberMan012025GameMode::DestruirBloque()
{
	//Seleccionar aleatoriamente un bloque del array ABloques para su eliminacion
	int numeroBloques = aBloques.Num();
	int NumeroAleatorio = FMath::RandRange(1, numeroBloques);

	if (aBloques.Num() > 0)
	{
		BloqueActual = aBloques[NumeroAleatorio]; // Obtén el primer bloque
		if (BloqueActual)
		{
			BloqueActual->Destroy();
			// Realiza operaciones con el bloque
			//primerBloque->SetActorLocation(FVector(100.0f, 100.0f, 100.0f));
		}
	}
}
*/
