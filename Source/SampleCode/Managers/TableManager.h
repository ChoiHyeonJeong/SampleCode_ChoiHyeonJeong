// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Tables/TB_StageBase.h"
#include "Tables/TB_Stage.h"
#include "Tables/TB_Chapter.h"
#include "TableManager.generated.h"


#define MAKE_TABLE_VAR(tableType, functionName, varName)\
private:\
	TMap<int32, tableType> varName;\
public:\
	tableType TB_##functionName(int32 index) { if (varName.Contains(index)) { return varName[index]; } return nullptr; }\
	TMap<int32, tableType>& get_tb##functionName() { return varName; }

/**
 *
 */

UCLASS(Abstract)
class SAMPLECODE_API UTableManager : public UObject
{
	GENERATED_BODY()

	UTableManager();
	MAKE_TABLE_VAR(FTB_StageBase*, StageBase, tbStageBase_)
	MAKE_TABLE_VAR(FTB_Stage*, Stage, tbStage_)
	MAKE_TABLE_VAR(FTB_Chapter*, Chapter, tbChapter_)
	

private:	
	template<typename T>
	void MakeTableMap(FString path, TMap<int32, T*>& tableMap);
	template<typename T>
	void MakeTableMap(FString path, TMap<FName, T*>& tableMap);

public:
	void InitTableManager();
};