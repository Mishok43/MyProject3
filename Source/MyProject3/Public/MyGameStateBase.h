// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */

class AGTarger;

UCLASS()
class MYPROJECT3_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite)
	FVector GameCenter;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FVector GameSize;

};
