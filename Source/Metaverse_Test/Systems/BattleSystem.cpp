// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/BattleSystem.h"

// Sets default values
ABattleSystem::ABattleSystem(){
	TotalDamage = 0;
	IsBattleOver = false;

}

// Called when the game starts or when spawned
void ABattleSystem::BeginPlay(){
	Super::BeginPlay();

	while (!IsBattleOver){
		RunSystem();
	}
}

void ABattleSystem::RunSystem()
{
}

void ABattleSystem::IsEndGame(bool isDead){
	if (isDead == true) {
		IsBattleOver = true;
	}
}

void ABattleSystem::BattleTurnPlayer()
{
}

void ABattleSystem::BattleTurnEnemy()
{
}

void ABattleSystem::AttackSkill(APaperZDCharacter_Sample* Player, APaperZDCharacter_Sample* Monster){
}

void ABattleSystem::DepenseSkill(APaperZDCharacter_Sample* SelfEntity){
}

void ABattleSystem::HealSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity){
}

void ABattleSystem::SupportSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity){
}

void ABattleSystem::PracticalSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity){
}
