// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TB_StageBase.h"
#include "TB_Stage.generated.h"

/**
 * - TB_StageBase ���̺��� ��ӹ޾� ���.
   - �ٸ� ���� ���̺�� �ٸ� �κе鸸 ���� �����ؼ� ���
   - �̼� ���̺��� �ִٰ� ����.
 */
USTRUCT(BlueprintType)
struct SAMPLECODE_API FTB_Stage : public FTB_StageBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 chapterIndex;				//TB_Chapter Index ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 wealthIndex;				//�Ҹ��� ��ȭ ������ Index, ������ Table Index ���� 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 mission01;				//�̼� Table Index ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 mission02;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 mission03;

};
