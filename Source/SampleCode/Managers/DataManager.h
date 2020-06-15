// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Etc/Structs.h"
#include "DataManager.generated.h"

/**
 * 
   - �������� �������� ��Ŷ���� �����ϰ� �����ϴ� �Ŵ��� Ŭ����
   - �������� Update, Get, Set, Save�� DataManager�� ���ؼ��� ����.
   - 
 */
UCLASS(Abstract)
class SAMPLECODE_API UDataManager : public UObject
{
	GENERATED_BODY()

private:
	TArray<struct FStage> stages_;

public:
	void SetUpdates(const struct FUpdates& updates);
	void SetStage(const TArray<struct FStage>& stages);
	const TArray<struct FStage>& GetStages();
	const struct FStage* GetStageById(int32 id);
	const struct FStage* GetStageByStageIndex(int32 stageIndex);
};
