// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StageInfoWidget.generated.h"

/**
 * Ŭ���� �������� ������ ��Ÿ�� Widget class 
   ��������, ����������, �������� ���� ��Ÿ��.
 */
DECLARE_DELEGATE_OneParam(FOnClickStageReady, int32);

UCLASS()
class SAMPLECODE_API UStageInfoWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	int32 curStageIndex_ = 0;

protected:
	UPROPERTY(BlueprintReadOnly) class UTextBlock* recommendPowerText_;

public:
	FOnClickStageReady onClickStageReadyDelegate;

protected:
	void SetMonster(int32 monsterIndex);
	void SetRecommendPower(int32 recommendPower);
	void SetReward(int32 rewardIndex);
	
	UFUNCTION() void OnClickStageReady();
public:
	void SetStageInfo(int32 stageIndex);
	int32 GetStageIndex() { return curStageIndex_; }
};
