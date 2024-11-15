// Fill out your copyright notice in the Description page of Project Settings.


#include "System/SkillSystem.h"
#include "YutJudgmentSystem.h"

SkillSystem::SkillSystem(){

}

int SkillSystem::MpExceptionHandling(FSkillInfo* SkillRow){
	CostMp = SkillRow->MpCost;

	UEnum* EnumPtr = StaticEnum<EhList>();
	int32 EnumIndex = EnumPtr->GetValueByName(FName(SkillRow->KeyValue));
	
	if (EnumIndex != INDEX_NONE) {
		EhList EnumValue = static_cast<EhList>(EnumIndex);

		switch (EnumValue)
		{
		case BI_2:
			CostMp = 2 * SetByPlayerChoice();
			break;
		case BI_3:
			CostMp = SetByPlayerChoice();
			break;
		case BA_1:
			CostMp = SetByPlayerChoice();
			break;
		case BA_2:
			CostMp = 3 + SetByPlayerChoice();
			break;
		case DA_1:
			CostMp = SetByPlayerChoice();
			break;
		case NA_1A:
			CostMp = 5 * SetByPlayerChoice();
			break;
		case NA_1D:
			CostMp = 5 * SetByPlayerChoice();
			break;
		case NA_1H:
			CostMp = 5 * SetByPlayerChoice();
			break;
		case OA_1:
			CostMp = SetByMp();
			break;
		case OA_2:
			CostMp = SetByPlayerChoice();
			break;
		default:
			break;
		}
	}

	return CostMp;
}

int SkillSystem::AmountExceptionHandling(FSkillInfo* SkillRow){
	Amount = SkillRow->Amount;

	UEnum* EnumPtr = StaticEnum<EhList>();
	int32 EnumIndex = EnumPtr->GetValueByName(FName(SkillRow->KeyValue));

	if (EnumIndex != INDEX_NONE) {
		EhList EnumValue = static_cast<EhList>(EnumIndex);

		switch (EnumValue)
		{
		case DI_1:
			Amount = 2 + SetByJudgement();
			break;
		case DI_2:
			Amount = SetBySubjectClass() + SetByJudgement();
			break;
		case DA_1:
			Amount = 2 * CostMp;
			break;
		case DA_2:
			Amount = 100;
			break;
		case NI_1A:
			Amount = SetByJudgement();
			break;
		case NA_1A:
			Amount = SetByJudgement();
			break;
		case NA_1D:
			Amount = SetByJudgement();
			break;
		case NA_1H:
			Amount = 2;
			break;
		case OI_2:
			if (SetByJudgement()) {
				Amount = 4;
			}
			Amount = 3;
			break;
		case OA_1:
			//Ư��ó��
			break;
		case OA_2:
			if (SetByJudgement()) {
				Amount = CostMp + 2;
			}
			break;
		case SB_1A:
			break;
		case SB_1D:
			break;
		case SB_2:
			break;
		case SB_3:
			break;
		case SI_1:
			break;
		case SI_3:
			break;
		case SA_1:
			break;
		case SA_2:
			break;
		case SA_3:
			break;

		default:
			break;}
	}

	return Amount;
}

int SkillSystem::SetByPlayerChoice()
{
	return 0;
}

int SkillSystem::SetBySubjectClass()
{
	return 0;
}

int SkillSystem::SetByJudgement(){
	int totalAmount = LoadedSystem.YutJudgingAmount();
	return totalAmount;
}

int SkillSystem::SetByHp()
{
	return 0;
}

int SkillSystem::SetByMp()
{
	return 0;
}