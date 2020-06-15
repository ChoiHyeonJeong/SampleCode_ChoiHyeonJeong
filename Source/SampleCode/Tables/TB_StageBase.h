// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TB_StageBase.generated.h"

/**
 * - ���� ���������� ���� �������� �������� ����� �� �ִ� Base ���̺�
   - ���� ������ ���̺� TB_StageBase ���̺��� ��ӹ޾� ���
   - ����Index �� ��� ���� ���� ���̺��� ����� ���� ����, ����� character���̺��� Index�� �����ϴ� ���� �����Ͽ� ����
   - ��������� Index�� ��� ���� ���� ���̺��� ����� ���� ����, ����� Item ���̺��� Index�� �����ϴ� ���� �����Ͽ� ����
   - ����, ������ ��� 0�� ���� �� �ִٸ� ������� �ʴ°����� ����.
   - ĳ���� ���̺�, ������ ���̺��� �ִٰ� ����.
 */

USTRUCT(BlueprintType)
struct SAMPLECODE_API FTB_StageBase : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") FText name;						
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 recommendPower;			//����������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 monsterIndex;				//ĳ���� Table�� Index ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 rewardIndex01;			//������ Table�� Index ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 rewardIndex02;			
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 rewardIndex03;			
};
