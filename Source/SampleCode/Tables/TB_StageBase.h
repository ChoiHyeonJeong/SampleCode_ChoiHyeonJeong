// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TB_StageBase.generated.h"

/**
 * - 전투 스테이지가 사용될 컨텐츠의 공용으로 사용할 수 있는 Base 테이블
   - 전투 컨텐츠 테이블에 TB_StageBase 테이블을 상속받아 사용
   - 몬스터Index 의 경우 몬스터 전용 테이블을 만들어 관리 가능, 현재는 character테이블의 Index를 참조하는 것을 가정하여 구성
   - 보상아이템 Index의 경우 보상 전용 테이블을 만들어 관리 가능, 현재는 Item 테이블의 Index를 참조하는 것을 가정하여 구성
   - 보상, 몬스터의 경우 0의 값이 들어가 있다면 사용하지 않는것으로 가정.
   - 캐릭터 테이블, 아이템 테이블이 있다고 가정.
 */

USTRUCT(BlueprintType)
struct SAMPLECODE_API FTB_StageBase : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") FText name;						
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 recommendPower;			//권장전투력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 monsterIndex;				//캐릭터 Table의 Index 참조
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 rewardIndex01;			//아이템 Table의 Index 참조
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 rewardIndex02;			
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StageBase") int32 rewardIndex03;			
};
