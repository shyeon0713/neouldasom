// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Entity/PaperZDCharacter_Sample.h"
#include "SkillDataTable.h"
#include "BattleSystem.generated.h"

UCLASS(Blueprintable)
class METAVERSE_TEST_API ABattleSystem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABattleSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Data for Battle System
	int BattleRound;
	int TotalDamage;
	int DepensedDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsBattleOver;

	void RunSystem();
	void IsEndGame(bool isDead);

	void BattleTurnPlayer();
	void BattleTurnEnemy();

	//ReadSkillData
	UFUNCTION(BlueprintCallable, Category = "Data")
	void ReadSkillData();
	UPROPERTY()
	TArray<FSkillInfoStruct> NatureSkillData;

public:
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void AttackSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void DepenseSkill(APaperZDCharacter_Sample* SelfEntity, FSkillInfoStruct Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void HealSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void SupportSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void PracticalSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill);
};