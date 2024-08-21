// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Character/CharacterBase.h"
#include "SkillDataTable.h"
#include "SkillSystem.h"
#include "BattleSystem.generated.h"


UENUM()
enum SkillSubject{
	BasicMagic,
	DepenseMagic,
	ExplorationMagic,
	NatureMagic,
	OrientalMedecine,
	SomaticMagic
};

UCLASS()
class METAVERSE_TEST_API ABattleSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleSystem();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalDamage; //Total Monster's Damage

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsBattleOver;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BattleRound;

	void RunSystem();
	void IsEndGame(bool isDead);

	UFUNCTION(BlueprintCallable, Category = "SystemSet")
	void SetBattleEntities(ACharacterBase* Entity1, ACharacterBase* Entity2);
	SkillSystem LoadSkillSystem;

	//Set Battle turn
	void BattleTurnPlayer();
	void BattleTurnEnemy();

	ACharacterBase* SkillSendEntity;
	ACharacterBase* SkillReceiveEntity;

	//Skill DataTable loader
	void SkillDataLoader();

	//Save SkillDataTable
	UDataTable* BasicSkillData;
	UDataTable* DepenseSkillData;
	UDataTable* ExplorationSkillData;
	UDataTable* NatureSkillData;
	UDataTable* MedecineSkillData;
	UDataTable* SomaticSkillData;

	//Save CurSkillData
	FSkillInfo* CurSkill;

	//System
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void SkillSystem(SkillSubject Subject, int RowNum);

	void AttackSkill();
	void DepenseSkill();
	void HealSkill();
	void SupportSkill();
	void PracticalSkill();

	//
};
