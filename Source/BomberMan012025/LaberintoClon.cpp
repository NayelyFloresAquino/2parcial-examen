// Fill out your copyright notice in the Description page of Project Settings.


#include "LaberintoClon.h"
#include "BloqueAcero.h"
#include "BloqueMadera.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "Engine/World.h"

// Sets default values
ALaberintoClon::ALaberintoClon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALaberintoClon::BeginPlay()
{
	Super::BeginPlay();

	GenerarMitadDerecha();
	GenerarMitadIzquierda();
	
}
void ALaberintoClon::GenerarMitadDerecha()
{
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Generando mitad derecha del laberinto"));

    for (int32 Fila = 0; Fila < aMapaBloques.Num(); ++Fila)
    {
        for (int32 Columna = 9; Columna < aMapaBloques[Fila].Num(); ++Columna)
        {
            int32 TipoBloque = aMapaBloques[Fila][Columna];
            if (TipoBloque != 0)
            {
                FVector PosicionDerecha = FVector(XInicial + Columna * AnchoBloque, YInicial + Fila * LargoBloque, ZInicial);
                SpawnBloque(PosicionDerecha, TipoBloque);
            }
        }
    }
}
void ALaberintoClon::GenerarMitadIzquierda()
{
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("Clonando mitad izquierda"));

    for (int32 Fila = 0; Fila < aMapaBloques.Num(); ++Fila)
    {
        for (int32 Columna = 9; Columna < aMapaBloques[Fila].Num(); ++Columna)
        {
            int32 TipoBloque = aMapaBloques[Fila][Columna];
            if (TipoBloque != 0)
            {
                FVector PosicionIzquierda = FVector(XInicial - Columna * AnchoBloque, YInicial + Fila * LargoBloque, ZInicial);
                SpawnBloque(PosicionIzquierda, TipoBloque);
            }
        }
    }
}
AActor* ALaberintoClon::Clonar(FVector Pos, float Dis)
{
    UWorld* World = GetWorld();
    if (World)
    {
        Pos.X += Dis;
        return World->SpawnActor<ALaberintoClon>(GetClass(), Pos, FRotator::ZeroRotator);
    }
    return nullptr;
}
// Called every frame
void ALaberintoClon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

