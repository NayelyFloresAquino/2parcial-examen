// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "ProtypeClonar.h"
#include "BloqueBurbuja.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN012025_API ABloqueBurbuja : public ABloque , public IProtypeClonar
{
	GENERATED_BODY()

public:
	ABloqueBurbuja();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override; // FUNCION DE MOVIMIENTO
	virtual AActor* Clonar(FVector Pos, float Dis) override;
private:
	FVector PosicionInicial;
	float DistanciaObjetivo = 1000.0f; // Distancia de movimiento
};
