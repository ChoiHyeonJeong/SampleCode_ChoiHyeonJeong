// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Util.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECODE_API UUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Util") static bool SetImage(class UImage* TargetImage, const FText& ImagePath);
	UFUNCTION(BlueprintCallable, Category = "Util") static struct FSlateBrush GetSlateBrush(const FText& path);

};
