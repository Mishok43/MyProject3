// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleManager.h"
#include "PuzzleSquares.generated.h"


class AGTarger;

/**
 * 
 */
UCLASS(Blueprintable)
class MYPROJECT3_API APuzzleSquares : public APuzzleManager
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
	virtual void Finish() override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<AGTarger> TargetClass;
	
	UFUNCTION(BlueprintCallable)
	void GenerateSquares();

	UPROPERTY(EditDefaultsOnly)
	int NumbrHorizontalRegions;

	UPROPERTY(EditDefaultsOnly)
	int NumbrVerticalRegions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FColor WinColor;

	UPROPERTY(EditDefaultsOnly)
	TArray<FColor> PossibleColors;

	TArray<AGTarger*> Squares;
};
