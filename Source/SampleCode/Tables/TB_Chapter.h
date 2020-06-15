// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TB_Chapter.generated.h"

/**
 *  TB_Chapter�� Index�� 100 �ڸ����� �̷���� ������ 1é�ʹ� 100, 2é�ʹ� 200 , 300, 400..... n ���� �����Ǿ��ִ�.
 */
USTRUCT(BlueprintType)
struct SAMPLECODE_API FTB_Chapter : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chpater") int32 index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chpater") FText name;							//UI�� ��Ÿ�� é���� �̸� ex) 1é��, 2é��, 3é��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chpater") FText chapterBGPath;					//�� é���� BG�� �������		
};
