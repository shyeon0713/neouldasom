// Fill out your copyright notice in the Description page of Project Settings.


#include "System/YutJudgmentSystem.h"


YutJudgmentSystem::YutJudgmentSystem() {
}

YutJudgmentSystem::~YutJudgmentSystem()
{
}

// T: 배면 40% F: 등면 60% 
bool YutJudgmentSystem::YutRolling() {
	int ramdomPercentage = FMath::RandRange(0, 9);

	if (ramdomPercentage < 6) {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString::Printf(TEXT("NOT Flip! %d"), ramdomPercentage));
		UE_LOG(LogTemp, Warning, TEXT("NOT Flip! %d"), ramdomPercentage)
		return false;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Cyan, FString::Printf(TEXT("Flip! %d"), ramdomPercentage));
		UE_LOG(LogTemp, Warning, TEXT("Flip! %d"), ramdomPercentage)
		SucceedCounter += 1;
		return true;
	}
}

bool YutJudgmentSystem::YutJudgingDefault(int JudgeValue) {
	UE_LOG(LogTemp, Warning, TEXT("Judge Start: value %d"), JudgeValue)
	SucceedCounter = 0;
	Yut_D1 = YutRolling();
	Yut_D2 = YutRolling();
	Yut_Cri = YutRolling();
	Yut_Fum = YutRolling();

	//모두다 등면이면 모: 5로 할당
	if (SucceedCounter == 0) {
		SucceedCounter = 5;
	}

	if (SucceedCounter == 1 && Yut_Fum) {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, TEXT("Judge Fail!"));
		return false;
	}
	else if (SucceedCounter > JudgeValue) {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, TEXT("Judge Fail!"));
		return false;
	}
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Cyan, TEXT("Judge Success!"));
	return true;
}

int YutJudgmentSystem::YutJudgingAmount(){
	SucceedCounter = 0;

	Yut_D1 = YutRolling();
	Yut_D2 = YutRolling();
	Yut_Cri = YutRolling();
	Yut_Fum = YutRolling();

	//모두다 등면이면 모: 4로 할당
	if (SucceedCounter == 0) {
		SucceedCounter = 4;
	}

	UE_LOG(LogTemp, Warning, TEXT("Judge Count: %d"), SucceedCounter)
	return SucceedCounter;
}