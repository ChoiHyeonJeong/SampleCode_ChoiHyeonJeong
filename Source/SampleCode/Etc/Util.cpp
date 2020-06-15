// Fill out your copyright notice in the Description page of Project Settings.

#include "Util.h"
#include "Classes/Engine/Texture2D.h"
#include "Styling/SlateBrush.h"
#include "Image.h"

bool UUtil::SetImage(class UImage* TargetImage, const FText& ImagePath)
{
	if (TargetImage != nullptr && !ImagePath.IsEmpty())
	{
		FSlateBrush brush = GetSlateBrush(ImagePath);
		if (brush.GetResourceObject() != nullptr)
		{
			TargetImage->SetBrush(brush);
			return true;
		}
	}
	return false;
}

FSlateBrush UUtil::GetSlateBrush(const FText& path)
{
	if (path.IsEmpty())
		return FSlateBrush();
	UObject* imageResource = LoadObject<UObject>(NULL, *path.ToString());
	if (imageResource == nullptr)
		return FSlateBrush();

	FSlateBrush brush;
	brush.SetResourceObject(imageResource);
	if (imageResource->IsA(UTexture2D::StaticClass()))
	{
		UTexture2D* texture = Cast<UTexture2D>(imageResource);
		if (texture == nullptr)
			return brush;
		brush.ImageSize = texture->GetImportedSize();
	}
	return brush;
}


