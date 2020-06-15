// Fill out your copyright notice in the Description page of Project Settings.

#include "SampleCodeGameInstance.h"

void USampleCodeGameInstance::Init() 
{
	Super::Init();

	tableManager = NewObject<UTableManager>(this);
	dataManager = NewObject<UDataManager>(this);
	stageManager = NewObject<UStageManager>(this);
}


