// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TB_Chapter.generated.h"

/**
 *  TB_Chapter의 Index는 100 자리수로 이루어져 있으며 1챕터는 100, 2챕터는 200 , 300, 400..... n 으로 구성되어있다.
 */
USTRUCT(BlueprintType)
struct SAMPLECODE_API FTB_Chapter : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chpater") int32 index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chpater") FText name;							//UI상에 나타낼 챕터의 이름 ex) 1챕터, 2챕터, 3챕터
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chpater") FText chapterBGPath;					//각 챕터의 BG의 경로정보		
};
