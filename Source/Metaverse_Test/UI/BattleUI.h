// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../System/BattleSystem.h"
#include "BattleUI.generated.h"

/**
 * 
 */
UCLASS()
class METAVERSE_TEST_API UBattleUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	void MappingSkills(SubjectClass Subject, int RowNum);
};
