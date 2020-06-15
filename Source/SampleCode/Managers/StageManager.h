// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StageManager.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class SAMPLECODE_API UStageManager : public UObject
{
	GENERATED_BODY()

private:
	int32 curChapterIndex_ = 0;
	int32 curStageIndex_ = 0;

public:
	bool IsChapterOpen(int32 chapterIndex);
	bool IsChpaterClear(int32 chapterIndex);
	bool IsStageOpen(int32 stageIndex);
	bool IsStageClear(int32 stageIndex);
	
	void SetCurChapterIndex(int32 chapterIndex);
	int32 GetCurChapterIndex();
	void SetCurStageIndex(int32 stageIndex);
	int32 GetCurStageIndex();

	int32 GetMissionClearCountByStageIndex(int32 stageIndex);
	bool isStageMissionClear(int32 stageIndex, int32 checkIndex);
	TArray<struct FTB_Stage*> GetStagesByChapterIndex(int32 chapterIndex);
};
