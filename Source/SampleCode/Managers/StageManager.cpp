// Fill out your copyright notice in the Description page of Project Settings.

#include "StageManager.h"
#include "SampleCodeGameInstance.h"
#include "Etc/Defines.h"

bool UStageManager::IsChapterOpen(int32 chapterIndex)
{
	/*
	 <é�� ���� üũ ����>
	1. ù��° é���� ��
	2. ���� é���� ���������� ��� Ŭ���� ���� ��
	*/
	FTB_Chapter* chapterTB = TABLE_MGR->TB_Chapter(chapterIndex);
	if (chapterTB == nullptr)
		return false;

	if (chapterTB->index == StageDefine::FIRST_CHAPTER)
		return true;
	
	if (!IsChpaterClear(chapterTB->index))
		return false;
	
	return true;
}
bool UStageManager::IsChpaterClear(int32 chapterIndex)
{
	/* 
	 < é�� Ŭ���� üũ ����>
	 1. ���� é�Ϳ� �ִ� ���������� ���� Ŭ���� ���� ���
	    (Ŭ������ �������� ������ �������� �޾ƿ�) 
	*/
	const TMap<int32, FTB_Stage*> stageTBs = TABLE_MGR->get_tbStage();
	if (stageTBs.Num() <= 0)
		return false;

	for (auto& iter : stageTBs)
	{
		if (iter.Value->chapterIndex != chapterIndex)
			continue;
		if (!DATA_MGR->GetStageByStageIndex(iter.Value->index))
			return false;
		if(!IsStageClear(iter.Value->index))
			return false;
	}
	return true;
}
bool UStageManager::IsStageOpen(int32 stageIndex)
{
	/*
	 <�������� ���� üũ ����>
	 1. �ش� ���������� �ش��ϴ� é�Ͱ� ���µǾ� �־�� ��.
	 2. ù é���� ù ���������� ��
	 3. ���� ���������� Ŭ���� ���� ��
	*/
	FTB_Stage* stageTB = TABLE_MGR->TB_Stage(stageIndex);
	if (stageTB == nullptr)
		return false;

	if (!IsChapterOpen(stageTB->chapterIndex))
		return false;

	if (stageTB->index == StageDefine::FIRST_STAGE)
		return true;

	//3.1. 2��° �̻� ����������� ���� ���������� clear �ƴ��� üũ
	int32 preStageIndex = stageTB->index - StageDefine::STAGE;
	const FStage* stage = DATA_MGR->GetStageByStageIndex(preStageIndex);
	return stage != nullptr && stage->clear > 0;
}
bool UStageManager::IsStageClear(int32 stageIndex)
{
	/*
	 <�������� Ŭ���� üũ ����>
	 1. �������� ��Ŷ�� clear�� 1�϶� Ŭ����
	 2. �������� ������ �������� ������
	*/
	FTB_Stage* stageTB = TABLE_MGR->TB_Stage(stageIndex);
	if (stageTB == nullptr)
		return false;

	const FStage* stage = DATA_MGR->GetStageByStageIndex(stageIndex);
	return stage != nullptr && stage->clear > 0;
}

void UStageManager::SetCurChapterIndex(int32 chapterIndex)
{
	curChapterIndex_ = chapterIndex;
}
int32 UStageManager::GetCurChapterIndex()
{
	/*
	 1. curChapterIndex_ = 0 �̶�� ���� ���� �� �ѹ��� �÷��� ���� ���� ���̰� �÷����� é���ε����� ������.
	 2. ���� ���� �� �ѹ��̶� ������ �÷��� �ߴٸ� ����Ǿ� �ִ� é���ε����� ������
	 3. ���̵� ���� �� ������ �ѹ��� ���� �ʾҴٸ� ù��° é�� �ε����� ������.
	*/

	if (curChapterIndex_ > 0)
		return curChapterIndex_;

	const TArray<FStage> stages = DATA_MGR->GetStages();
	if (stages.Num() <= 0)
		return StageDefine::FIRST_CHAPTER;
	
	int32 maxClearChapterIndex_ = 0;
	int32 maxClearStageIndex_ = 0;
	for (auto& iter : stages)
	{
		FTB_Stage* stageTB = TABLE_MGR->TB_Stage(iter.index);
		if (stageTB == nullptr)
			return 0;

		if (maxClearStageIndex_ < stageTB->index && iter.clear > 0)
		{
			maxClearStageIndex_ = stageTB->index;
			maxClearChapterIndex_ = stageTB->chapterIndex;
		}
	}

	FTB_Stage* nextStageTB = TABLE_MGR->TB_Stage(maxClearStageIndex_ + StageDefine::STAGE);
	if (nextStageTB == nullptr)
	{
		FTB_Chapter* nextChapterTB = TABLE_MGR->TB_Chapter(maxClearChapterIndex_ + StageDefine::CHAPTER);
		if (nextChapterTB != nullptr)
			return nextChapterTB->index;
	}

	return maxClearChapterIndex_;
}
void UStageManager::SetCurStageIndex(int32 stageIndex)
{
	curStageIndex_ = stageIndex;
}
int32 UStageManager::GetCurStageIndex()
{
	/*
	1. curStageIndex_ = 0 �̶�� ���� ���� �� �ѹ��� �÷��� ���� ���� ���̰� �÷����� �������� �ε����� ������.
	2. ���� ���� �� �ѹ��̶� ������ �÷��� �ߴٸ� ����Ǿ� �ִ� �������� �ε����� ������
	3. ���̵� ���� �� ������ �ѹ��� ���� �ʾҴٸ� ù��° �������� �ε����� ������.
	*/

	if (curStageIndex_ > 0)
		return curStageIndex_;

	const TArray<FStage> stages = DATA_MGR->GetStages();
	if (stages.Num() <= 0)
		return StageDefine::FIRST_STAGE;

	int32 maxClearStageIndex_ = 0;
	for (auto& iter : stages)
	{
		FTB_Stage* stageTB = TABLE_MGR->TB_Stage(iter.index);
		if (stageTB == nullptr)
			return 0;

		if (maxClearStageIndex_ < stageTB->index && iter.clear > 0)
			maxClearStageIndex_ = stageTB->index;
	}

	FTB_Stage* nextStageTB = TABLE_MGR->TB_Stage(maxClearStageIndex_ + StageDefine::STAGE);
	if (nextStageTB != nullptr)
		return nextStageTB->index;

	return maxClearStageIndex_;
}
int32 UStageManager::GetMissionClearCountByStageIndex(int32 stageIndex)
{
	/*
	< �������� �̼� ���� >
	1. �̼� ������ �������� ������ ( ��Ʈ�÷��� ���, �������� ��Ŷ�� missions)
	2. ���� UI ���� ��Ÿ���� ���� �̼� Ŭ���� ���θ� ������ ��Ÿ������.
	*/
	int32 count = 0;
	for (int32 i = 0; i < StageDefine::MAX_MISSION_COUNT; ++i)
	{
		if (isStageMissionClear(stageIndex, i))
			++count;
	}
	return count;
}
bool UStageManager::isStageMissionClear(int32 stageIndex, int32 checkIndex)
{
	const FStage * stage = DATA_MGR->GetStageByStageIndex(stageIndex);
	return stage == nullptr ? false : (((stage->missions) & (1 << static_cast<uint32>(checkIndex))) > 0);
}

TArray<FTB_Stage*> UStageManager::GetStagesByChapterIndex(int32 chapterIndex)
{
	TMap<int32, FTB_Stage*> stageTBs = TABLE_MGR->get_tbStage();
	if (stageTBs.Num() <= 0)
		return TArray<FTB_Stage*>();

	TArray<FTB_Stage*> tempStages;
	for (auto& iter : stageTBs)
	{
		if (iter.Value->chapterIndex != chapterIndex)
			continue;
		tempStages.Emplace(iter.Value);
	}
	return tempStages;
}