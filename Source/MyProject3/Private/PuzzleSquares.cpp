// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleSquares.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameStateBase.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GTarger.h"

void APuzzleSquares::BeginPlay()
{
	Super::BeginPlay();
	GenerateSquares();
}

void APuzzleSquares::GenerateSquares()
{
	AMyGameStateBase* myGameState = Cast<AMyGameStateBase>(UGameplayStatics::GetGameState(this));

	const auto gameZoneLeftCorner = (myGameState->GameCenter - myGameState->GameSize / 2.0f);
	const auto spawnRegionWidth = myGameState->GameSize.X / NumbrHorizontalRegions;
	const auto spawnRegionHeight = myGameState->GameSize.Y / NumbrVerticalRegions;

	const auto winVRegion = FMath::RandRange(0, NumbrVerticalRegions - 1);
	const auto winHRegion = FMath::RandRange(0, NumbrHorizontalRegions - 1);

	for (int i = 0; i < NumbrVerticalRegions; ++i)
	{
		for (int j = 0; j < NumbrHorizontalRegions; ++j)
		{
			const auto isWinSquare = i == winVRegion && j == winHRegion;
			if (!isWinSquare)
			{
				const auto spawnProbability = FMath::RandRange(0.0f, 1.0f);
				if (spawnProbability < 0.3f)
				{
					continue;
				}
			}

			FActorSpawnParameters squareSpawnParameters = {};
			squareSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			const auto spawnRegionCenter = gameZoneLeftCorner + FVector((j + 0.5f)*spawnRegionWidth, (i + 0.5f)*spawnRegionHeight, 0);
			const auto spawnOffset = FVector(spawnRegionWidth*FMath::RandRange(-0.2f, 0.2f), spawnRegionHeight*FMath::RandRange(-0.2f, 0.2f), 0);

			const auto spawnLocation = spawnRegionCenter + spawnOffset;

			AGTarger* target = GetWorld()->SpawnActor<AGTarger>(TargetClass, spawnLocation, FRotator::ZeroRotator, squareSpawnParameters);
			target->SetIsSquare(isWinSquare);

			Squares.Add(target);

			if (!isWinSquare)
			{
				target->SetActorScale3D(FVector(1.0, FMath::RandRange(0.7f, 1.7f), FMath::RandRange(0.7f, 1.7f)));
			}
			else
			{
				const auto scale = FMath::RandRange(0.7f, 1.7f);
				target->SetActorScale3D(FVector(1.0, scale, scale));
			}


			const FColor ChosenColor = (isWinSquare) ? WinColor : PossibleColors[FMath::RandRange(0, PossibleColors.Num() - 1)];
			target->SetColor(ChosenColor);

			auto test = ChosenColor.ReinterpretAsLinear();

			auto* staticMeshComp = Cast<UStaticMeshComponent>(target->GetComponentByClass(UStaticMeshComponent::StaticClass()));
			UMaterialInstanceDynamic* materialInstance = staticMeshComp->CreateDynamicMaterialInstance(0, staticMeshComp->GetMaterial(0));
			materialInstance->SetVectorParameterValue("Color", ChosenColor.ReinterpretAsLinear());
		}
	}
}

void APuzzleSquares::Finish()
{
	Super::Finish();

	for(auto* square : Squares)
	{
		square->Destroy();
	}
}


