// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"


class UStaticMeshComponent;

UCLASS()
class BOMBERMAN012025_API ABloque : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloque();

protected:
	// componente de malla estatica

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* MallaBloque;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	float FloatSpeed;
	float RotationSpeed;
	bool bPuedeMoverse;
	bool bPuedeRotar;
	bool bPuedeDestruirse;
	bool bPuedeExplotar;
	bool bPuedeProtegerse;
	//virtual void Protegerse() = 0;
	// ABloque* CrearBloque(FString tipoBloque);    //que tipo de bloque va a tener static
	//virtual ABloque*CrearBloque(FString tipoBloque)
		//PURE_VIRTUAL(APotionShop::ConcoctPotion, return nullptr;);

};
