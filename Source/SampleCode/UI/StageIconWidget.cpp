// Fill out your copyright notice in the Description page of Project Settings.

#include "StageIconWidget.h"
#include "SampleCodeGameInstance.h"
#include "Etc/Defines.h"
#include "TextBlock.h"
#include "Image.h"

bool UStageIconWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	for (int32 i = 0; i < StageDefine::MAX_MISSION_COUNT; ++i)
	{
		UImage* list = Cast<UImage>(GetWidgetFromName(*FString::Printf(TEXT("missionStar_%d"), i)));
		if (list)
			missionStars_.Emplace(list);
	}
	return true;
}
void UStageIconWidget::SetStageIcon(int32 stageIndex)
{
	FTB_Stage* stageTB = TABLE_MGR->TB_Stage(stageIndex);
	if (stageTB == nullptr)
		return;

	curStageIndex_ = stageIndex;

	SetName(stageTB->name);
	SetMission();
	SetStageOpen();
	SetStageClear();
	SetSelectIcon(false);
}
void UStageIconWidget::SetName(FText& name)
{
	if (stageNameText_ == nullptr)
		return;

	stageNameText_->SetText(name);
}
void UStageIconWidget::SetMission()
{
	int32 missionCount = STAGE_MANAGER->GetMissionClearCountByStageIndex(curStageIndex_);

	for (int32 i = 0; i < StageDefine::MAX_MISSION_COUNT; ++i)
		missionStars_[i]->SetVisibility(missionCount > i ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
}
void UStageIconWidget::SetStageOpen()
{
	if (lockImg_ == nullptr)
		return;

	bool IsOpen = STAGE_MANAGER->IsStageOpen(curStageIndex_);
	IsOpen ? lockImg_->SetVisibility(ESlateVisibility::Visible) : lockImg_->SetVisibility(ESlateVisibility::Collapsed);
}
void UStageIconWidget::SetStageClear()
{
	if (clearImg_ == nullptr)
		return;

	bool IsClear = STAGE_MANAGER->IsStageClear(curStageIndex_);
	IsClear ? clearImg_->SetVisibility(ESlateVisibility::Visible) : clearImg_->SetVisibility(ESlateVisibility::Collapsed);
}
void UStageIconWidget::SetSelectIcon(bool isSelect)
{
	if (selectImg_ == nullptr)
		return;

	isSelected_ = isSelect;
	isSelected_ ? selectImg_->SetVisibility(ESlateVisibility::SelfHitTestInvisible) : selectImg_->SetVisibility(ESlateVisibility::Collapsed);
}
void UStageIconWidget::OnClickStageIcon()
{
	if (isSelected_ == true)
		return;

	onClickStageIconDelegate.ExecuteIfBound(curStageIndex_);
}

