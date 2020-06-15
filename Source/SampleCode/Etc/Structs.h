// Fill out your copyright notice in the Description page of Project Settings.

#pragma once 

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs.generated.h" 

USTRUCT()
struct FStage
{
	/*
	- �������� �����ִ� Stage ��Ŷ�� ������ ������ ����ü
	- Ŭ���� ������ ��� ���� �ѹ��̶� ������ �������� �� ������ �����ϸ� ������ ������
	*/
	GENERATED_USTRUCT_BODY()

	UPROPERTY() int32 id;						
	UPROPERTY() int32 index;					//TB_Stage�� Index
	UPROPERTY() int32 clear;					//Ŭ��������( 0 : Ŭ����X, 1 : Ŭ����O)
	UPROPERTY() int32 missions;					//�� ���������� �̼� Ŭ���� ���θ� ������ (��Ʈ�÷��� ���)
	UPROPERTY() int64 createTime;				
};

USTRUCT()
struct FUpdates
{
	/*
	- �������� �����ִ� Updates ��Ŷ���� ����ü
	- ������ �Ǵ� ��Ŷ �������� �������� ������
	- TArray<>�θ� �����Ǿ� �������� Num() > 0 ��쿡�� ���� ������ ����.
	*/

	GENERATED_USTRUCT_BODY()

	UPROPERTY() TArray<struct FStage> stages;	
};
