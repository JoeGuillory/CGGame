// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralCubeActor.h"
#include "ProceduralMeshComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AProceduralCubeActor::AProceduralCubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
	SetRootComponent(ProceduralMesh);

}

void AProceduralCubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugPoint(GetWorld(), Positions[0]+ RootComponent->GetRelativeLocation(), 10.0f, FColor::Blue);
	DrawDebugPoint(GetWorld(), Positions[1]+ RootComponent->GetRelativeLocation(),10.0f, FColor::Green);
	DrawDebugPoint(GetWorld(), Positions[2]+ RootComponent->GetRelativeLocation(),10.0f, FColor::Yellow);
	DrawDebugPoint(GetWorld(), Positions[3]+ RootComponent->GetRelativeLocation(),10.0f, FColor::Red);
	DrawDebugPoint(GetWorld(), Positions[4]+ RootComponent->GetRelativeLocation(),10.0f, FColor::Blue);
	DrawDebugPoint(GetWorld(), Positions[5]+ RootComponent->GetRelativeLocation(),10.0f, FColor::Green);
	DrawDebugPoint(GetWorld(), Positions[6]+ RootComponent->GetRelativeLocation(),10.0f, FColor::Yellow);
	DrawDebugPoint(GetWorld(), Positions[7]+ RootComponent->GetRelativeLocation(),10.0f, FColor::Red);
}

// Called when the game starts or when spawned
void AProceduralCubeActor::BeginPlay()
{
	Super::BeginPlay();

	Positions.Add(FVector(0, 50, 50)); // 1st vert
	Positions.Add(FVector(0, -50, -50)); // 2nd vert
	Positions.Add(FVector(0, -50, 50)); // 3rd vert
	Positions.Add(FVector(0, 50, -50));
	Positions.Add(FVector(-100, 50, 50));
	Positions.Add(FVector(-100, -50,-50));
	Positions.Add(FVector(-100, -50,50));
	Positions.Add(FVector(-100, 50,-50));
	UVs.Add({ 1,1 });
	UVs.Add({ 0,0 });
	UVs.Add({ 1,0 });
	TriangleIndices.Add(0);
	TriangleIndices.Add(1);
	TriangleIndices.Add(2);

	TriangleIndices.Add(3);
	TriangleIndices.Add(1);
	TriangleIndices.Add(0);

	TriangleIndices.Add(4);
	TriangleIndices.Add(3);
	TriangleIndices.Add(0);

	TriangleIndices.Add(7);
	TriangleIndices.Add(3);
	TriangleIndices.Add(4);

	TriangleIndices.Add(2);
	TriangleIndices.Add(5);
	TriangleIndices.Add(6);

	TriangleIndices.Add(1);
	TriangleIndices.Add(5);
	TriangleIndices.Add(2);

	TriangleIndices.Add(4);
	TriangleIndices.Add(2);
	TriangleIndices.Add(6);

	TriangleIndices.Add(0);
	TriangleIndices.Add(2);
	TriangleIndices.Add(4);

	TriangleIndices.Add(6);
	TriangleIndices.Add(7);
	TriangleIndices.Add(4);

	TriangleIndices.Add(5);
	TriangleIndices.Add(7);
	TriangleIndices.Add(6);
	//Bottom
	TriangleIndices.Add(5);
	TriangleIndices.Add(3);
	TriangleIndices.Add(7);

	TriangleIndices.Add(1);
	TriangleIndices.Add(3);
	TriangleIndices.Add(5);
	ProceduralMesh->CreateMeshSection(0, Positions, TriangleIndices, TArray<FVector>(), UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	ProceduralMesh->CastShadow = false;
}

