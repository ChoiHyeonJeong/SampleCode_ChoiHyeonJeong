// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TB_StageBase.h"
#include "TB_Stage.generated.h"

/**
 * - TB_StageBase 테이블을 상속받아 사용.
   - 다른 전투 테이블과 다른 부분들만 따로 선언해서 사용
   - 미션 테이블이 있다고 가정.
 */
USTRUCT(BlueprintType)
struct SAMPLECODE_API FTB_Stage : public FTB_StageBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 chapterIndex;				//TB_Chapter Index 참조
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 wealthIndex;				//소모할 재화 아이템 Index, 아이템 Table Index 참조 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 mission01;				//미션 Table Index 참조
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 mission02;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage") int32 mission03;

};
