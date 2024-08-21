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

	SkillDataLoader();
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

void ABattleSystem::SkillDataLoader(){
	BasicSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_BasicMagic.DT_BasicMagic"));
	DepenseSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_DepenseMagic.DT_DepenseMagic"));
	ExplorationSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_NatureMagic.DT_NatureMagic"));
	NatureSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_NatureMagic.DT_NatureMagic"));
	MedecineSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_NatureMagic.DT_NatureMagic"));
	SomaticSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_NatureMagic.DT_NatureMagic"));
}


void ABattleSystem::SkillDataTestPrint(int Subject, int RowNum)
{
	FName SkillNum = FName(*(FString::FromInt(RowNum)));
	switch (Subject)
	{
	case 1:
		if (BasicSkillData != nullptr) {
			static const FString BasicSkillContextString(TEXT("BasicSkillTableContext"));

			FSkillInfo* Row = BasicSkillData->FindRow<FSkillInfo>(SkillNum, BasicSkillContextString, true);

			if (Row) {
				UE_LOG(LogTemp, Warning, TEXT("KeyValue %s, SkillName %s ,Amount %d ,MpCost %d ,Detail %s"), *Row->KeyValue, *Row->SkillName, Row->Amount, Row->MpCost, *Row->Detail);
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Row not found!"));
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Failed to load DataTable!"));
		}
		break;
	case 4:
		if (NatureSkillData != nullptr) {
			static const FString NatureSkillContextString(TEXT("NatureSkillTableContext"));

			FSkillInfo* Row = NatureSkillData->FindRow<FSkillInfo>(SkillNum, NatureSkillContextString, true);

			if (Row) {
				UE_LOG(LogTemp, Warning, TEXT("KeyValue %s, SkillName %s ,Amount %d ,MpCost %d ,Detail %s"), *Row->KeyValue, *Row->SkillName, Row->Amount, Row->MpCost, *Row->Detail);
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Row not found!"));
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Failed to load DataTable!"));
		}
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Subject NorFound!"));
		break;
	}
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


