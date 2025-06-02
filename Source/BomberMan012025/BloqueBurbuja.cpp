// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueBurbuja.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

ABloqueBurbuja::ABloqueBurbuja()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
}
void ABloqueBurbuja::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // Guardar la posición inicial
}
void ABloqueBurbuja::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector PosicionActual = GetActorLocation();
    float DistanciaRecorrida = PosicionActual.X - PosicionInicial.X;

    if (DistanciaRecorrida < DistanciaObjetivo) 
    {
        PosicionActual.X += 70.0f * DeltaTime;
        SetActorLocation(PosicionActual);

    }
}
AActor* ABloqueBurbuja::Clonar(FVector Pos, float Dis)
{
	UWorld* World = GetWorld();
	if (!World) 
	{
		return nullptr; // Si no hay un mundo, no se puede clonar
	}
	FActorSpawnParameters Params;
	AActor* clon = World->SpawnActor<ABloqueBurbuja>(GetClass(), Pos, FRotator::ZeroRotator);

	if (clon)
	{
		ABloqueBurbuja* BloqueClon = Cast<ABloqueBurbuja>(clon);
		if (BloqueClon) 
		{
			BloqueClon->SetActorLocation(Pos);
			//BloqueClon->SetActorScale3D(FVector(Dis));
			BloqueClon->PosicionInicial = Pos; // Establecer la posición inicial del clon

			BloqueClon->SetActorEnableCollision(false); // Habilitar colisiones para el clon

			FString Mensaje = FString::Printf(TEXT("Clon creado en la posición: X=%f, Y=%F, Z=%F"), Pos.X, Pos.Y, Pos.Z);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Mensaje);
		
		}
	
	}

	return clon;
}