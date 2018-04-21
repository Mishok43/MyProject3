// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"


void APuzzleManager::BeginPlay()
{
	Super::BeginPlay();

	TextWidget = CreateWidget<UUserWidget>(GetWorld(), TextWidgetClass);
	TextWidget->AddToViewport();

	EnableInput(GetWorld()->GetFirstPlayerController());
}

void APuzzleManager::Finish()
{
	DisableInput(GetWorld()->GetFirstPlayerController());

	TextWidget->RemoveFromParent();
}



