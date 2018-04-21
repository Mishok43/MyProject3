// Fill out your copyright notice in the Description page of Project Settings.

#include "GTarger.h"


// Sets default values
AGTarger::AGTarger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGTarger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGTarger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGTarger::SetIsSquare(const bool isSquare)
{
	bIsSquare = isSquare;
}

void AGTarger::SetColor(const FColor & _color)
{
	color = _color;
}

