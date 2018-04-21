// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "PuzzleManager.generated.h"

/**
 * 
 */

class UUserWidget;

UCLASS(Blueprintable)
class MYPROJECT3_API APuzzleManager : public AInfo
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
	virtual void Finish();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> TextWidgetClass;

	UUserWidget* TextWidget;

	virtual void BeginPlay() override;


};
