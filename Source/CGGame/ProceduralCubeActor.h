// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralCubeActor.generated.h"



UCLASS()
class CGGAME_API AProceduralCubeActor : public AActor
{
	GENERATED_BODY()
	//Describes the 3-D position of a vertex
	TArray<FVector> Positions;
	// Decribes the position of begining sampling at froma texture for each vertex
	TArray<FVector2D> UVs;
	//Every three indices correspondes to a single tirangle
	TArray<int32> TriangleIndices;
	
public:	
	// Sets default values for this actor's properties
	AProceduralCubeActor();
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UProceduralMeshComponent> ProceduralMesh;
};
