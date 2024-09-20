// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "../System/SkillDataTable.h"
#include "MonsterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class METAVERSE_TEST_API AMonsterCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
	AMonsterCharacter();
	

	//Load Skill
	UDataTable* MonsterSkillData;
	void LoadSkills();
		
	//Set Defficult
	int TotalDamage;
	int TotalCost;
public:
	//1. 플레이어와 몬스터 정보 비교
	void CompareStatus(const int PlayerHp, const int PlayerMp);
	//2. 몬스터 정보와 라운드 정보로 우선도 선택
	SkillType TypePriority;
	void SetPriority(const int BattleRound);

	//Select Skill
	UDataTable* CurSkill;
	void SetSkill();
};
