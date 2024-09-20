// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MonsterCharacter.h"
#include "../System/YutJudgmentSystem.h"

AMonsterCharacter::AMonsterCharacter(){
	LoadSkills();
}

void AMonsterCharacter::LoadSkills(){
	MonsterSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_BasicMagic.DT_BasicMagic"));
}

void AMonsterCharacter::CompareStatus(const int PlayerHp, const int PlayerMp){
}

void AMonsterCharacter::SetPriority(const int BattleRound){
}

void AMonsterCharacter::SetSkill(){
	// 플레이어 정보 참조
}
