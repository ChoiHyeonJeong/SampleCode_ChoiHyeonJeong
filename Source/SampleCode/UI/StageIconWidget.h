// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StageIconWidget.generated.h"

/**
 * ������ �������� �������� ��Ÿ�� Widget class
   �������� �̸�, ��迩��, Ŭ�����, ���ÿ���, �̼� ���� ������ ����������.
 */
DECLARE_DELEGATE_OneParam(FOnClickStageIcon, int32);

UCLASS()
class SAMPLECODE_API UStageIconWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	int32 curStageIndex_ = 0;
	bool isSelected_ = false;

protected:
	UPROPERTY(BlueprintReadOnly) class UTextBlock* stageNameText_;
	UPROPERTY(BlueprintReadOnly) class UImage* lockImg_;
	UPROPERTY(BlueprintReadOnly) class UImage* clearImg_;
	UPROPERTY(BlueprintReadOnly) class UImage* selectImg_;
	UPROPERTY() TArray<class UImage*> missionStars_;

public:
	FOnClickStageIcon onClickStageIconDelegate;

protected:
	virtual bool Initialize() override;

	void SetName(FText& name);
	void SetMission();
	void SetStageOpen();
	void SetStageClear();

	UFUNCTION() void OnClickStageIcon();

public:
	void SetStageIcon(int32 stageIndex);
	void SetSelectIcon(bool isSelect);
	bool GetSelected() { return isSelected_; }
	int32 GetStageIndex() { return curStageIndex_; }

};
