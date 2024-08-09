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

	}
}

void ABattleSystem::IsEndGame(bool isDead)
{
	if (isDead == true) {
		IsBattleOver = true;
	}
}

void ABattleSystem::AttackSkill(APaperZDCharacter_Sample* Player, APaperZDCharacter_Sample* Monster)
{
}
