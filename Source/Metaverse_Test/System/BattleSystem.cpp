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

void ABattleSystem::RunSystem(){
	BattleTurnPlayer();
	BattleTurnEnemy();
}

void ABattleSystem::IsEndGame(bool isDead)
{
}

void ABattleSystem::SetBattleEntities(APlayerCharacter* Entity1, ACharacterBase* Entity2){
	PlayerEntity = Entity1;
	SkillReceiveEntity = Entity2;

	if (PlayerEntity == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Initialize Failed!"))
	}
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
	ExplorationSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_ExplorationMagic.DT_ExplorationMagic"));
	NatureSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_NatureMagic.DT_NatureMagic"));
	MedecineSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_OrientalMedicine.DT_OrientalMedicine"));
	SomaticSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_SomaticMagic.DT_SomaticMagic"));
}

void ABattleSystem::SkillSystem(SubjectClass Subject, int RowNum){
	SkillClass = Subject;
	
	FName SkillNum = FName(*(FString::FromInt(RowNum)));
	static const FString SkillDataContextString(TEXT("SkillTableContext"));

	switch (Subject)
	{
	case BasicMagic:
		CurSkill = BasicSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
		break;
	case DepenseMagic:
		CurSkill = DepenseSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
		break;
	case ExplorationMagic:
		CurSkill = ExplorationSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
		break;
	case NatureMagic:
		CurSkill = NatureSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
		break;
	case OrientalMedecine:
		CurSkill = MedecineSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
		break;
	case SomaticMagic:
		CurSkill = SomaticSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Subject Not Found!"))
		break;
	}
	UE_LOG(LogTemp, Warning, TEXT("KeyValue %s, SkillName %s ,Amount %d ,MpCost %d ,Detail %s, SKillType %d"), *CurSkill->KeyValue, *CurSkill->SkillName, CurSkill->Amount, CurSkill->MpCost, *CurSkill->Detail, CurSkill->SkillType);

	switch (CurSkill->SkillType)
	{
	case Attack:
		AttackSkill();
		break;
	case Depense:
		DepenseSkill();
		break;
	case Heal:
		HealSkill();
		break;
	case Support:
		SupportSkill();
		break;
	case Practical:
		PracticalSkill();
		break;
	default:
		break;
	}

}

void ABattleSystem::AttackSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);
	int damage = LoadSkillSystem.AmountExceptionHandling(CurSkill);
	
	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetHP(-cost);
	SkillReceiveEntity->SetHP(-damage);
}

void ABattleSystem::DepenseSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);
	
	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetMP(-cost);
}

void ABattleSystem::HealSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);
	int healAmount = LoadSkillSystem.AmountExceptionHandling(CurSkill);

	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetMP(-cost);
	SkillReceiveEntity->SetHP(healAmount);
}

void ABattleSystem::SupportSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);

	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetMP(-cost);
}

void ABattleSystem::PracticalSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);

	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetMP(-cost);
}