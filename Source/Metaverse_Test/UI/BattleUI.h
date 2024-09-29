// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../System/BattleSystem.h"
#include "Components/Image.h"
#include "BattleUI.generated.h"

/**
 * 
 */
UCLASS()
class METAVERSE_TEST_API UBattleUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UBattleUI(const FObjectInitializer &ObjectInitializer);

	class ABattleSystem* LoadedSystem;
	UFUNCTION(BlueprintCallable, Category = "UI")
	void CallSystem();

	UFUNCTION(BlueprintCallable, Category = "SkillSelect")
	void MappingSkills(SubjectClass Subject, int RowNum);

	TSubclassOf<UUserWidget> WidgetClass;
	UBattleUI* BattleWidgetInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(BindWidgetOptional))
	class UImage* Success;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Fail;

	void ShowPassFailCutIn(bool IsSucceed);
};
