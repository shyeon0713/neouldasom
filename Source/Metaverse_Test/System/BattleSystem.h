// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Character/CharacterBase.h"
#include "../Character/PlayerCharacter.h"
#include "../Character/MonsterCharacter.h"
#include "SkillDataTable.h"
#include "SkillSystem.h"
#include "BattleSystem.generated.h"

UCLASS()
class METAVERSE_TEST_API ABattleSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleSystem();

protected:
	virtual void BeginPlay() override;

	//Show Total Monster's Damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalDamage; 

	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UUserWidget> DamageWidgetClass;

	class Widget* DamageWidget;

	//Set BattleTurn
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsBattleOver; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BattleRound;

	UFUNCTION(BlueprintCallable, Category = "SystemRunning")
	void RunSystem();
	void IsEndGame();

	UFUNCTION(BlueprintCallable, Category = "SystemSet")
	void SetBattleEntities(APlayerCharacter* Entity1, AMonsterCharacter* Entity2);
	SkillSystem LoadSkillSystem;

	//Set Battle turn
	UFUNCTION(BlueprintCallable, Category = "BattleTurn")
	void BattleTurnPlayer(SubjectClass Subject, int RowNum);
	UFUNCTION(BlueprintCallable, Category = "BattleTurn")
	void BattleTurnEnemy();

public:
	bool IsPlayerTurn;
	bool IsPlayerSelectSkill;

protected:
	APlayerCharacter* PlayerEntity;
	AMonsterCharacter* SkillReceiveEntity;

	//Skill DataTable loader
	void SkillDataLoader();

	//Save SkillDataTable
	UDataTable* BasicSkillData;
	UDataTable* DepenseSkillData;
	UDataTable* ExplorationSkillData;
	UDataTable* NatureSkillData;
	UDataTable* MedecineSkillData;
	UDataTable* SomaticSkillData;
	UDataTable* MonsterSkillData;

public:
	//Save CurSkillData
	SubjectClass SkillClass;
	FSkillInfo* CurSkill;
	int CurSubjectPoint;

	//System
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void SkillSystem(SubjectClass Subject, int RowNum);

	void AttackSkill();
	void DepenseSkill();
	void HealSkill();
	void SupportSkill();
	void PracticalSkill();

	//DebugLog
	void ShowDebugLog();
};
