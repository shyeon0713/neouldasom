// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillDataTable.h"

/**
 * 
 */
 
UENUM()
enum EMpEhList {
	BI_2,
	BI_3,
	BA_1,
	BA_2,
	DA_1,
	NA_1A,
	NA_1D,
	NA_1H,
	OA_1,
	OA_2
};

class METAVERSE_TEST_API SkillSystem
{
public:
	//MpExceptionHandling -> 도력 예외처리
	int MpExceptionHandling(FSkillInfo* SkillRow);
	int SetMpByPlayerChoice();

	//
	int HpExceptionHandling(FSkillInfo* SkillRow);
};


