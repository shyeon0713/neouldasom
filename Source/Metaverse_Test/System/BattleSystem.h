// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Character/CharacterBase.h"
#include "../Character/PlayerCharacter.h"
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

	void RunSystem();
	void IsEndGame(bool isDead);

	UFUNCTION(BlueprintCallable, Category = "SystemSet")
	void SetBattleEntities(APlayerCharacter* Entity1, ACharacterBase* Entity2);
	SkillSystem LoadSkillSystem;

	//Set Battle turn
	void BattleTurnPlayer();
	void BattleTurnEnemy();
	bool IsPlayerTurn;
	bool IsPlayerSelectSkill;

	APlayerCharacter* PlayerEntity;
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

public:
	//Save CurSkillData
	SubjectClass SkillClass;
	FSkillInfo* CurSkill;

	//System
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void SkillSystem(SubjectClass Subject, int RowNum);

	void AttackSkill();
	void DepenseSkill();
	void HealSkill();
	void SupportSkill();
	void PracticalSkill();

	//
};
