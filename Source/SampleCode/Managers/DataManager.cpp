// Fill out your copyright notice in the Description page of Project Settings.

#include "DataManager.h"

void UDataManager::SetUpdates(const FUpdates& updates)
{
	if (updates.stages.Num() > 0)
		SetStage(updates.stages);
}
void UDataManager::SetStage(const TArray<FStage>& stages)
{
	stages_ = stages_;
}
const TArray<FStage>& UDataManager::GetStages()
{
	return stages_;
}
const FStage* UDataManager::GetStageById(int32 id)
{
	for (int32 i = 0; i < stages_.Num(); ++i)
	{
		if (stages_[i].id == id)
			return &stages_[i];
	}
	return nullptr;
}
const FStage* UDataManager::GetStageByStageIndex(int32 stageIndex)
{
	for (int32 i = 0; i < stages_.Num(); ++i)
	{
		if (stages_[i].index == stageIndex)
			return &stages_[i];
	}
	return nullptr;
}
