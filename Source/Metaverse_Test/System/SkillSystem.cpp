// Fill out your copyright notice in the Description page of Project Settings.


#include "System/SkillSystem.h"

int SkillSystem::MpExceptionHandling(FSkillInfo* SkillRow){
	int CostMp = 0;

	UEnum* EnumPtr = StaticEnum<EMpEhList>();
	int32 EnumIndex = EnumPtr->GetValueByName(FName(SkillRow->KeyValue));
	
	if (EnumIndex != INDEX_NONE) {
		EMpEhList EnumValue = static_cast<EMpEhList>(EnumIndex);

		switch (EnumValue)
		{
		case BI_2:
			break;
		case BI_3:
			break;
		case BA_1:
			break;
		case BA_2:
			break;
		case DA_1:
			break;
		case NA_1A:
			break;
		case NA_1D:
			break;
		case NA_1H:
			break;
		case OA_1:
			break;
		case OA_2:
			break;
		default:
			break;
		}
	}

	return CostMp;
}

int SkillSystem::SetMpByPlayerChoice(){
	return -1;
}

int SkillSystem::HpExceptionHandling(FSkillInfo* SkillRow)
{
	return 0;
}
