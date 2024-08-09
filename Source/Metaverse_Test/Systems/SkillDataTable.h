// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SkillDataTable.generated.h"

/**
 * 
 */
UENUM()
enum SkillType
{
	Attack,
	Depense,
	Heal,
	Support
};

USTRUCT(BlueprintType)
struct FSkillInfoStruct :public FTableRowBase {
	GENERATED_BODY()

public:
	FSkillInfoStruct() : SkillName("name") {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString SkillName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int MpCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString Detail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TEnumAsByte<SkillType> SkillType;
};