// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/BattleSystem.h"

// Sets default values
ABattleSystem::ABattleSystem(){
	TotalDamage = 0;
	IsBattleOver = false;
	BattleRound = 1;
}

// Called when the game starts or when spawned
void ABattleSystem::BeginPlay(){
	Super::BeginPlay();
	
	ReadSkillData();
	while (!IsBattleOver){
		RunSystem();
	}
}

void ABattleSystem::RunSystem()
{
	BattleRound += 1;
	BattleTurnPlayer();
	BattleTurnEnemy();
	DepensedDamage = 0;
}

void ABattleSystem::IsEndGame(bool isDead){
	if (isDead == true) {
		IsBattleOver = true;
	}
}

void ABattleSystem::BattleTurnPlayer(){

}

void ABattleSystem::BattleTurnEnemy()
{
}

void ABattleSystem::ReadSkillData(){

}


void ABattleSystem::AttackSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill){
	int cost = Skill.MpCost;
	int damage = Skill.Amount;

	SelfEntity->SetMP(-cost);
	OtherEntity->SetHP(-damage);
}

void ABattleSystem::DepenseSkill(APaperZDCharacter_Sample* SelfEntity, FSkillInfoStruct Skill){
	
}

void ABattleSystem::HealSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill){
	int cost = 0 - Skill.MpCost;
	int HealHp = Skill.Amount;

	SelfEntity->SetMP(-cost);
	SelfEntity->SetHP(HealHp);
}

void ABattleSystem::SupportSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill){
}

void ABattleSystem::PracticalSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity, FSkillInfoStruct Skill){
}
