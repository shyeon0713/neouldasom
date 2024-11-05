// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MonsterCharacter.h"

AMonsterCharacter::AMonsterCharacter(){

}

bool AMonsterCharacter::JudgmentSkill(int score){
	YutJudgmentSystem* System = new YutJudgmentSystem;

	return System->YutJudgingDefault(score);
}
