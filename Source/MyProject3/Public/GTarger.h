// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GTarger.generated.h"

UCLASS()
class MYPROJECT3_API AGTarger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGTarger();

	UPROPERTY(BlueprintReadOnly)
	bool bIsSquare;

	UPROPERTY(BlueprintReadOnly)
	FColor color;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetIsSquare(const bool isSquare);

	void SetColor(const FColor& _color);
	
};
