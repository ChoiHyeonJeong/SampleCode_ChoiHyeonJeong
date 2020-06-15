// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StageMainWidget.generated.h"

/**
 * - UMG를 이용한 Stage Main Widget
 */
UCLASS()
class SAMPLECODE_API UStageMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly) class UImage* chapterBG_;
	UPROPERTY(BlueprintReadOnly) class UTextBlock* chapterNameText_;
	UPROPERTY(BlueprintReadOnly) class UStageInfoWidget* stageInfo_;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)	TSoftClassPtr<class UStageIconWidget> stageIconWidget;
	UPROPERTY() TArray<class UStageIconWidget*> stageIcons_;
	UPROPERTY() class UStageIconWidget* selectedStageIcon_;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void SetBackground(FText& bgPath);
	void SetChpaterName(FText& name);
	void SetStage(int32 chapterIndex);
	void CreateStageIcons(int32 createCount);
	void SetStageInfo(int32 stageIndex);

	UFUNCTION() void OnClickStageIcon(int32 stageIndex);
	UFUNCTION() void OnClickBattleReady(int32 stageIndex);

public:
	void Init(int32 chapterIndex = 0);
};
