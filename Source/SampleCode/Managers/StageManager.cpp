// Fill out your copyright notice in the Description page of Project Settings.

#include "StageManager.h"
#include "SampleCodeGameInstance.h"
#include "Etc/Defines.h"

bool UStageManager::IsChapterOpen(int32 chapterIndex)
{
	/*
	 <챕터 오픈 체크 조건>
	1. 첫번째 챕터일 때
	2. 이전 챕터의 스테이지를 모두 클리어 했을 때
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
	 < 챕터 클리어 체크 조건>
	 1. 같은 챕터에 있는 스테이지를 전부 클리어 했을 경우
	    (클리어한 스테이지 정보는 서버에서 받아옴) 
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
	 <스테이지 오픈 체크 조건>
	 1. 해당 스테이지에 해당하는 챕터가 오픈되어 있어야 함.
	 2. 첫 챕터의 첫 스테이지일 때
	 3. 이전 스테이지를 클리어 했을 때
	*/
	FTB_Stage* stageTB = TABLE_MGR->TB_Stage(stageIndex);
	if (stageTB == nullptr)
		return false;

	if (!IsChapterOpen(stageTB->chapterIndex))
		return false;

	if (stageTB->index == StageDefine::FIRST_STAGE)
		return true;

	//3.1. 2번째 이상 스테이지라면 이전 스테이지가 clear 됐는지 체크
	int32 preStageIndex = stageTB->index - StageDefine::STAGE;
	const FStage* stage = DATA_MGR->GetStageByStageIndex(preStageIndex);
	return stage != nullptr && stage->clear > 0;
}
bool UStageManager::IsStageClear(int32 stageIndex)
{
	/*
	 <스테이지 클리어 체크 조건>
	 1. 스테이지 패킷의 clear가 1일때 클리어
	 2. 스테이지 정보는 서버에서 내려줌
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
	 1. curChapterIndex_ = 0 이라면 게임 접속 뒤 한번도 플레이 하지 않은 것이고 플레이할 챕터인덱스를 리턴함.
	 2. 게임 접속 후 한번이라도 게임을 플레이 했다면 저장되어 있는 챕터인덱스를 리턴함
	 3. 아이디 생성 뒤 전투를 한번도 하지 않았다면 첫번째 챕터 인덱스를 리턴함.
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
	1. curStageIndex_ = 0 이라면 게임 접속 뒤 한번도 플레이 하지 않은 것이고 플레이할 스테이지 인덱스를 리턴함.
	2. 게임 접속 후 한번이라도 게임을 플레이 했다면 저장되어 있는 스테이지 인덱스를 리턴함
	3. 아이디 생성 뒤 전투를 한번도 하지 않았다면 첫번째 스테이지 인덱스를 리턴함.
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
	< 스테이지 미션 정보 >
	1. 미션 정보는 서버에서 내려줌 ( 비트플래그 사용, 스테이지 패킷의 missions)
	2. 실제 UI 에서 나타내기 위해 미션 클리어 여부를 개수로 나타내야함.
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