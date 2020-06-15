// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Managers/TableManager.h"
#include "Managers/DataManager.h"
#include "Managers/StageManager.h"
#include "SampleCodeGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECODE_API USampleCodeGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
private:
	UPROPERTY() UTableManager* tableManager;
	UPROPERTY() UDataManager* dataManager;
	UPROPERTY() UStageManager* stageManager;

public:
	virtual void Init() override;

	UTableManager* GetTableManager()	{ return tableManager; }
	UDataManager* GetDataManager()		{ return dataManager; }
	UStageManager* GetStageManager()	{ return stageManager; }
};

#define GAME_INSTANCE			(Cast<USampleCodeGameInstance>(GetWorld()->GetGameInstance()))
#define TABLE_MGR				(GAME_INSTANCE->GetTableManager())
#define DATA_MGR				(GAME_INSTANCE->GetDataManager())
#define STAGE_MANAGER			(GAME_INSTANCE->GetStageManager())