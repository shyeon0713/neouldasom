// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */


class METAVERSE_TEST_API YutJudgmentSystem
{
public:
	YutJudgmentSystem();
	~YutJudgmentSystem();

public:
	//Setting Yut // T: 배면 40% F: 등면 60%
	bool Yut_D1;
	bool Yut_D2;
	bool Yut_Cri; //크리티컬 -> 행
	bool Yut_Fum; //펌블 -> 액
	int SucceedCounter;


	//Rolling Yut
	bool YutRolling();

	UFUNCTION(BlueprintCallable, Category = "Judge")
	bool YutJudgingDefault(const int JudgeValue);
	UFUNCTION(BlueprintCallable, Category = "Judge")
	int YutJudgingAmount();
};
