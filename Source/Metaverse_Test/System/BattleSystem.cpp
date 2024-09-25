// Fill out your copyright notice in the Description page of Project Settings.


#include "System/BattleSystem.h"

// Sets default values
ABattleSystem::ABattleSystem(){
	TotalDamage = 0;
	IsBattleOver = false;
	//IsPlayerTurn = true;
	BattleRound = 1;
}

void ABattleSystem::BeginPlay()
{
	Super::BeginPlay();

	SkillDataLoader();
	//RunSystem();
}

void ABattleSystem::RunSystem(){
	if (!IsPlayerTurn) {
		BattleTurnEnemy();
	}
}

void ABattleSystem::IsEndGame(){
	if (PlayerEntity->Hp == 0 || SkillReceiveEntity->Hp == 0)
		IsBattleOver = true;

	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Yellow, FString::Printf(TEXT("Battle End!")));
	return;
}

void ABattleSystem::SetBattleEntities(APlayerCharacter* Entity1, AMonsterCharacter* Entity2){
	PlayerEntity = Entity1;
	SkillReceiveEntity = Entity2;

	if (PlayerEntity == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Initialize Failed!"))
	}
}

void ABattleSystem::BattleTurnPlayer(SubjectClass Subject, int RowNum){
	IsPlayerTurn = true;
	IsPlayerSelectSkill = false;

	IsEndGame();
	return;
}

void ABattleSystem::BattleTurnEnemy(){ 
	IsPlayerTurn = false;

	int SkillPersentageNumber = FMath::RandRange(0, 5);
	static const FString SkillDataContextString(TEXT("SkillTableContext"));
	if (SkillPersentageNumber == 0) {
		FName SkillNum = FName(*(FString::FromInt(1)));
		CurSkill = MonsterSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
	}
	else {
		FName SkillNum = FName(*(FString::FromInt(2)));
		CurSkill = MonsterSkillData->FindRow<FSkillInfo>(SkillNum, SkillDataContextString, true);
	}
	int PassFailPersentage = FMath::RandRange(0, 9);

	UE_LOG(LogTemp, Warning, TEXT("KeyValue %s, SkillName %s ,Amount %d ,MpCost %d ,Detail %s, SKillType %d"), *CurSkill->KeyValue, *CurSkill->SkillName, CurSkill->Amount, CurSkill->MpCost, *CurSkill->Detail, CurSkill->SkillType);
	IsPlayerTurn = true;
	IsEndGame();

	return;
}

void ABattleSystem::SkillDataLoader(){
	BasicSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_BasicMagic.DT_BasicMagic"));
	DepenseSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_DepenseMagic.DT_DepenseMagic"));
	ExplorationSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_ExplorationMagic.DT_ExplorationMagic"));
	NatureSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_NatureMagic.DT_NatureMagic"));
	MedecineSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_OrientalMedicine.DT_OrientalMedicine"));
	SomaticSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_SomaticMagic.DT_SomaticMagic"));
	MonsterSkillData = LoadObject<UDataTable>(nullptr, TEXT("/Game/BattleMap/DT_Skill/DT_MonsterSkill.DT_MonsterSkill"));
}

void ABattleSystem::SkillSystem(SubjectClass Subject, int RowNum){
	SkillClass = Subject;
	
	FName SkillNum = FName(*(FString::FromInt(RowNum)));
	static const FString SkillDataContextString(TEXT("SkillTableContext"));

	switch (Subject){
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

	switch (CurSkill->SkillType) {
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

	IsPlayerTurn = false;
}

void ABattleSystem::AttackSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);
	int damage = LoadSkillSystem.AmountExceptionHandling(CurSkill);
	
	if (PlayerEntity->JudgmentSubject(SkillClass)) {
		SkillReceiveEntity->SetHP(-damage);
		UE_LOG(LogTemp, Warning, TEXT("Attack Success!"));
	}
	PlayerEntity->SetMP(-cost);

	ShowDebugLog();
}

void ABattleSystem::DepenseSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);
	
	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetMP(-cost);

	ShowDebugLog();
}

void ABattleSystem::HealSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);
	int healAmount = LoadSkillSystem.AmountExceptionHandling(CurSkill);

	if (PlayerEntity->JudgmentSubject(SkillClass)) {
		PlayerEntity->SetHP(healAmount);
	}
	PlayerEntity->SetMP(-cost);

	ShowDebugLog();
}

void ABattleSystem::SupportSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);

	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetMP(-cost);

	ShowDebugLog();
}

void ABattleSystem::PracticalSkill(){
	int cost = LoadSkillSystem.MpExceptionHandling(CurSkill);

	PlayerEntity->JudgmentSubject(SkillClass);
	PlayerEntity->SetMP(-cost);

	ShowDebugLog();
}

void ABattleSystem::ShowDebugLog(){
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Yellow, FString::Printf(TEXT("Player HP: %d, MP: %d Monster HP: %d, MP: %d"), PlayerEntity->Hp, PlayerEntity->Mp, SkillReceiveEntity->Hp, SkillReceiveEntity->Mp));
}
