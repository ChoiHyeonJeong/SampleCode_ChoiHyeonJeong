// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Etc/Structs.h"
#include "DataManager.generated.h"

/**
 * 
   - 서버에서 내려오는 패킷들을 저장하고 관리하는 매니저 클래스
   - 데이터의 Update, Get, Set, Save는 DataManager를 통해서만 가능.
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
