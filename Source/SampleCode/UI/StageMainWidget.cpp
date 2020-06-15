// Fill out your copyright notice in the Description page of Project Settings.

#include "StageMainWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SampleCodeGameInstance.h"
#include "Etc/Defines.h"
#include "Etc/Util.h"
#include "UI/StageIconWidget.h"
#include "UI/StageInfoWidget.h"

#include "Image.h"
#include "TextBlock.h"

void UStageMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (stageInfo_ == nullptr)
		return;
	stageInfo_->onClickStageReadyDelegate.BindUObject(this, &UStageMainWidget::OnClickBattleReady);
} 

void UStageMainWidget::NativeDestruct()
{
	Super::NativeDestruct();

	for (int32 i = 0; i < stageIcons_.Num(); ++i)
		stageIcons_[i]->onClickStageIconDelegate.Unbind();

	stageIcons_.Empty();
	stageInfo_->onClickStageReadyDelegate.Unbind();
	selectedStageIcon_ = nullptr;
}

void UStageMainWidget::Init(int32 chapterIndex)
{
	int32 index = 0;
	chapterIndex > 0 ? index = chapterIndex : index = STAGE_MANAGER->GetCurChapterIndex();

	FTB_Chapter* chapterTB = TABLE_MGR->TB_Chapter(index);
	if (chapterTB == nullptr)
		return;

	STAGE_MANAGER->SetCurChapterIndex(chapterTB->index);
	SetBackground(chapterTB->chapterBGPath);
	SetChpaterName(chapterTB->name);
	SetStage(chapterTB->index);
	OnClickStageIcon(STAGE_MANAGER->GetCurStageIndex());
}

void UStageMainWidget::SetBackground(FText& bgPath)
{
	if (chapterBG_ == nullptr)
		return;
	UUtil::SetImage(chapterBG_, bgPath);
}
void UStageMainWidget::SetChpaterName(FText& name)
{
	if (chapterNameText_ == nullptr)
		return;
	chapterNameText_->SetText(name);
}
void UStageMainWidget::SetStage(int32 chapterIndex)
{
	TArray<FTB_Stage*> stageTBs = STAGE_MANAGER->GetStagesByChapterIndex(chapterIndex);
	if (stageTBs.Num() <= 0)
		return;

	if (stageTBs.Num() > stageIcons_.Num())
		CreateStageIcons(stageTBs.Num() - stageIcons_.Num());

	for (int32 i = 0; i < stageIcons_.Num(); ++i)
	{
		stageIcons_[i]->SetVisibility(ESlateVisibility::Visible);
		stageIcons_[i]->onClickStageIconDelegate.Unbind();
		stageIcons_[i]->onClickStageIconDelegate.BindUObject(this, &UStageMainWidget::OnClickStageIcon);
		stageIcons_[i]->SetStageIcon(stageTBs[i]->index);
	}

	for (int32 i = stageTBs.Num(); i < stageIcons_.Num(); ++i)
		stageIcons_[i]->SetVisibility(ESlateVisibility::Collapsed);
}
void UStageMainWidget::CreateStageIcons(int32 createCount)
{
	for (int32 i = 0; i < createCount; ++i)
	{
		UStageIconWidget* createWidget = CreateWidget< UStageIconWidget>(GetWorld()->GetFirstPlayerController(), stageIconWidget.LoadSynchronous());
		if (createWidget == nullptr)
			return;
		stageIcons_.Emplace(createWidget);
	}
}
void UStageMainWidget::SetStageInfo(int32 stageIndex)
{
	stageInfo_->SetStageInfo(stageIndex);
}

void UStageMainWidget::OnClickStageIcon(int32 stageIndex)
{
	if(selectedStageIcon_ != nullptr)
		selectedStageIcon_->SetSelectIcon(false);
	
	STAGE_MANAGER->SetCurStageIndex(stageIndex);

	for (auto& iter : stageIcons_)
	{
		if (iter->GetStageIndex() == stageIndex)
		{
			selectedStageIcon_ = iter;
			selectedStageIcon_->SetSelectIcon(true);
			break;
		}
	}
	SetStageInfo(stageIndex);
}
void UStageMainWidget::OnClickBattleReady(int32 stageIndex)
{
	FTB_Stage* stageTB = TABLE_MGR->TB_Stage(stageIndex);
	if (stageTB == nullptr)
		return;

	//1. 재화가 있는지 체크 한다.
	//if(!IsEnoughWealth(wealthIndex))
	//	return;

	//2. 오픈되어있는 챕터 인지 체크
	if (!STAGE_MANAGER->IsChapterOpen(stageTB->chapterIndex))
		return;

	//3. 오픈되어있는 스테이지 인지 체크
	if (!STAGE_MANAGER->IsStageOpen(stageTB->index))
		return;

	//4. 셋팅 페이지로 이동하기 전에 스테이지 매니저에 현재 상태를 저장한다. 
	STAGE_MANAGER->SetCurChapterIndex(stageTB->chapterIndex);
	STAGE_MANAGER->SetCurStageIndex(stageTB->index);

	//5. 전투 레벨로 이동
	UGameplayStatics::OpenLevel(this, "BattleLevel");
}