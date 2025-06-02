// Fill out your copyright notice in the Description page of Project Settings.


#include "Laberinto_Concreto_1.h"
#include "laberinto.h"
#include "BloqueAcero.h"
#include "BloqueMadera.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "Engine/World.h"

// Sets default values
ALaberinto_Concreto_1::ALaberinto_Concreto_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ALaberinto_Concreto_1::BeginPlay()
{
	Super::BeginPlay();
	Reset();
	buildBloqueMuros();
	//buildBloqueMadera();
	//builBloqueConcreto();
	//buildBloqueLadrillo();
	
}

// Called every frame
void ALaberinto_Concreto_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ALaberinto_Concreto_1::Reset()
{
	if (laberintoactual)
	{
		laberintoactual->Destroy();
		laberintoactual = nullptr;
	}

	if (GetWorld())
	{
		FVector Posicion = GetActorLocation() + FVector(0, 0, 200);
		FRotator Rotacion = FRotator::ZeroRotator;
		
		laberintoactual = GetWorld()->SpawnActor<ALaberinto>(ALaberinto::StaticClass(), Posicion, Rotacion);
		if (laberintoactual)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("¡Laberinto generado correctamente!"));
		}
	}
}

void ALaberinto_Concreto_1::buildBloqueMuros()
{
	if (laberintoactual)
	{
		for (int32 i = 0; i < laberintoactual->aMapaBloques.Num(); i++)
		{
			for (int32 j = 0; j < laberintoactual->aMapaBloques[i].Num(); j++)
			{
				if (laberintoactual->aMapaBloques[i][j] == 4)
				{
					FVector Pos = FVector(
						laberintoactual->XInicial + j * laberintoactual->AnchoBloque,
						laberintoactual->YInicial + i * laberintoactual->LargoBloque,
						laberintoactual->ZInicial

					);
					GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), Pos, FRotator::ZeroRotator);
				}
			}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("build muros"));
}

void ALaberinto_Concreto_1::buildBloqueConcreto()
{
	if (laberintoactual)
	{
		for (int32 i = 0; i < laberintoactual->aMapaBloques.Num(); i++)
		{
			for (int32 j = 0; j < laberintoactual->aMapaBloques[i].Num(); j++)
			{
				if (laberintoactual->aMapaBloques[i][j] == 3)
				{
					FVector Pos = FVector(
						laberintoactual->XInicial + j * laberintoactual->AnchoBloque,
						laberintoactual->YInicial + i * laberintoactual->LargoBloque,
						laberintoactual->ZInicial

					);
					GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), Pos, FRotator::ZeroRotator);
				}
			}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("build concreto"));
}

void ALaberinto_Concreto_1::buildBloqueLadrillo()
{
	if (laberintoactual)
	{
		for (int32 i = 0; i < laberintoactual->aMapaBloques.Num(); i++)
		{
			for (int32 j = 0; j < laberintoactual->aMapaBloques[i].Num(); j++)
			{
				if (laberintoactual->aMapaBloques[i][j] == 2)
				{
					FVector Pos = FVector(
						laberintoactual->XInicial + j * laberintoactual->AnchoBloque,
						laberintoactual->YInicial + i * laberintoactual->LargoBloque,
						laberintoactual->ZInicial

					);
					GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), Pos, FRotator::ZeroRotator);
				}
			}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("build ladrillo"));
}
void ALaberinto_Concreto_1::buildBloqueMadera()
{
	if (laberintoactual && GetWorld())
	{
		for (int32 i = 0; i < laberintoactual->aMapaBloques.Num(); i++)
		{
			for (int32 j = 0; j < laberintoactual->aMapaBloques[i].Num(); j++)
			{
				if (laberintoactual->aMapaBloques[i][j] == 1)
				{
					FVector Pos = FVector(
						laberintoactual->XInicial + j * laberintoactual->AnchoBloque,
						laberintoactual->YInicial + i * laberintoactual->LargoBloque,
						laberintoactual->ZInicial
					);
					GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), Pos, FRotator::ZeroRotator);
				}
			}
		}
	}
}

ALaberinto* ALaberinto_Concreto_1::GetLaberinto()
{
	return laberintoactual;
}


