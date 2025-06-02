// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPrototypeClon.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIPrototypeClon : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN012025_API IIPrototypeClon
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//1.- Esta interfaz se encarga de clonar un actor en una posicion indicada y con una distancia indicada
	virtual  class AActor* Clonar(FVector Pos, float Dis) = 0; // esta funcion se encarga de clonar el actor en la posicion indicada y con la distancia indicada
};
