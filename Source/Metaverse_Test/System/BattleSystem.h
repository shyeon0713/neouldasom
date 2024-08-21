// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Character/CharacterBase.h"
#include "SkillDataTable.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsBattleOver;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BattleRound;

	void RunSystem();
	void IsEndGame(bool isDead);

	void BattleTurnPlayer();
	void BattleTurnEnemy();

	UFUNCTION(BlueprintCallable, Category = "Battle")
	void AttackSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void DepenseSkill(ACharacterBase* SelfEntity, FSkillInfo Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void HealSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void SupportSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill);
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void PracticalSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill);
};
