// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MonsterCharacter.h"

void AMonsterCharacter::BeginPlay(){
	Super::BeginPlay();

	LoadSkills();
}

void AMonsterCharacter::LoadSkills(){
	MonsterSkills = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_MonsterSkill.DT_MonsterSkill"));
}
