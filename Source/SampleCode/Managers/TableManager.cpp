// Fill out your copyright notice in the Description page of Project Settings.

#include "TableManager.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"

UTableManager::UTableManager()
{
	InitTableManager();
}

void UTableManager::InitTableManager()
{
	MakeTableMap<FTB_StageBase>("DataTable'/Game/UI/StageBase.StageBase'", tbStageBase_);
	MakeTableMap<FTB_Stage>("DataTable'/Game/UI/Stage.Stage'", tbStage_);
	MakeTableMap<FTB_Chapter>("DataTable'/Game/UI/Chapter.Chapter'", tbChapter_);
}
template<typename T>
void UTableManager::MakeTableMap(FString path, TMap<int32, T*>& tableMap)
{
	if (tableMap.Num() > 0)
	{
		tableMap.Empty();
	}
	FSoftObjectPath objPath(path);
	UObject* obj = objPath.TryLoad();
	if (obj)
	{
		UDataTable* tb = Cast<UDataTable>(obj);

		FString Context;
		TArray<T*> arr;
		tb->GetAllRows<T>(Context, arr);
		TArray<FName> names = tb->GetRowNames();
		FString stringKey;
		for (int32 i = 0; i < arr.Num(); i++)
		{
			if (i < names.Num())
			{
				stringKey = names[i].ToString();
				int32 key = FCString::Atoi(*stringKey);
				tableMap.Add(key, arr[i]);
			}
		}
	}
}

template<typename T>
void UTableManager::MakeTableMap(FString path, TMap<FName, T*>& tableMap)
{
	if (tableMap.Num() > 0)
	{
		tableMap.Empty();
	}
	tableMap.Empty();
	FSoftObjectPath objPath(path);
	UObject* obj = objPath.TryLoad();
	if (obj)
	{
		UDataTable* tb = Cast<UDataTable>(obj);

		FString Context;
		TArray<T*> arr;
		tb->GetAllRows<T>(Context, arr);
		TArray<FName> names = tb->GetRowNames();
		for (int32 i = 0; i < arr.Num(); i++)
		{
			if (i < names.Num())
			{
				tableMap.Add(names[i], arr[i]);
			}
		}
	}
}