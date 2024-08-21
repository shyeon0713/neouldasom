// Fill out your copyright notice in the Description page of Project Settings.


#include "System/BattleSystem.h"

// Sets default values
ABattleSystem::ABattleSystem(){

	TotalDamage = 0;
	IsBattleOver = false;
	BattleRound = 1;

}

void ABattleSystem::BeginPlay()
{
	Super::BeginPlay();

}

void ABattleSystem::RunSystem()
{

	BattleTurnPlayer();
	BattleTurnEnemy();
}

void ABattleSystem::IsEndGame(bool isDead)
{
}

void ABattleSystem::BattleTurnPlayer()
{
}

void ABattleSystem::BattleTurnEnemy()
{
}

void ABattleSystem::AttackSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill){
	int cost = Skill.MpCost;
	int damage = Skill.Amount;

	SelfEntity->SetMP(-cost);
	OtherEntity->SetHP(-damage);
}

void ABattleSystem::DepenseSkill(ACharacterBase* SelfEntity, FSkillInfo Skill)
{
}

void ABattleSystem::HealSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill){
	int cost = Skill.MpCost;
	int healAmount = Skill.Amount;

	SelfEntity->SetMP(-cost);
	OtherEntity->SetHP(healAmount);
}

void ABattleSystem::SupportSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill)
{
}

void ABattleSystem::PracticalSkill(ACharacterBase* SelfEntity, ACharacterBase* OtherEntity, FSkillInfo Skill)
{
}


