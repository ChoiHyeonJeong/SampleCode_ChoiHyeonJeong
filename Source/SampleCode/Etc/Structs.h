// Fill out your copyright notice in the Description page of Project Settings.

#pragma once 

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs.generated.h" 

USTRUCT()
struct FStage
{
	/*
	- 서버에서 내려주는 Stage 패킷의 정보를 저장할 구조체
	- 클리어 유무에 상관 없이 한번이라도 전투를 시작했을 때 서버에 저장하며 정보가 내려옴
	*/
	GENERATED_USTRUCT_BODY()

	UPROPERTY() int32 id;						
	UPROPERTY() int32 index;					//TB_Stage의 Index
	UPROPERTY() int32 clear;					//클리어유무( 0 : 클리어X, 1 : 클리어O)
	UPROPERTY() int32 missions;					//각 스테이지의 미션 클리어 여부를 내려줌 (비트플래그 사용)
	UPROPERTY() int64 createTime;				
};

USTRUCT()
struct FUpdates
{
	/*
	- 서버에서 내려주는 Updates 패킷들의 구조체
	- 갱신이 되는 패킷 정보들을 서버에서 내려줌
	- TArray<>로만 구성되어 내려오며 Num() > 0 경우에만 정보 갱신을 해줌.
	*/

	GENERATED_USTRUCT_BODY()

	UPROPERTY() TArray<struct FStage> stages;	
};
