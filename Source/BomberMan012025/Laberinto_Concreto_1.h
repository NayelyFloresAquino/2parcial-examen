// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ILaberintoBuilder.h"
#include "Laberinto_Concreto_1.generated.h"

UCLASS()
class BOMBERMAN012025_API ALaberinto_Concreto_1 : public AActor, public IILaberintoBuilder
{
	GENERATED_BODY()

private:
	UPROPERTY()
	ALaberinto* laberintoactual = nullptr;
private:

	//prototipo del bloquemadera
	UPROPERTY()
	class ABloqueMadera* PrototipBloqueMadera;

	
public:	
	// Sets default values for this actor's properties
	ALaberinto_Concreto_1();

	virtual void Reset() override;
	virtual void buildBloqueMuros() override;
	virtual void buildBloqueConcreto() override;
	virtual void buildBloqueLadrillo() override;
	virtual void buildBloqueMadera() override;
    virtual ALaberinto* GetLaberinto() override;
	// Implementacion del metodo cloneBloqueMadera
	//virtual ABloqueMadera* CloneBloqueMadera() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
