// Fill out your copyright notice in the Description page of Project Settings.

#include "StageInfoWidget.h"
#include "SampleCodeGameInstance.h"
#include "TextBlock.h"

void UStageInfoWidget::SetStageInfo(int32 stageIndex)
{
	FTB_Stage* stageTB = TABLE_MGR->TB_Stage(stageIndex);
	if (stageTB == nullptr)
		return;

	curStageIndex_ = stageIndex;

	SetMonster(stageTB->monsterIndex);
	SetRecommendPower(stageTB->recommendPower);
	SetReward(stageTB->rewardIndex01);
	SetReward(stageTB->rewardIndex02);
	SetReward(stageTB->rewardIndex03);
}
void UStageInfoWidget::SetMonster(int32 monsterIndex)
{
	if (monsterIndex <= 0)
		return;

	//몬스터 정보를 셋팅함 -> 구현 X
}
void UStageInfoWidget::SetRecommendPower(int32 recommendPower)
{
	if (recommendPowerText_ == nullptr)
		return;

	recommendPowerText_->SetText(FText::AsNumber(recommendPower));
}
void UStageInfoWidget::SetReward(int32 rewardIndex)
{
	if (rewardIndex <= 0)
		return;

	//보상 정보를 셋팅함  -> 구현 X
}
void UStageInfoWidget::OnClickStageReady()
{
	onClickStageReadyDelegate.ExecuteIfBound(curStageIndex_);
}