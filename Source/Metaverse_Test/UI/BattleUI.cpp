// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BattleUI.h"
#include "Kismet/GameplayStatics.h"

void UBattleUI::CallSystem(){
	if (!LoadedSystem) {
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABattleSystem::StaticClass(), FoundActors);
		if (FoundActors.Num() > 0) {
			LoadedSystem = Cast<ABattleSystem>(FoundActors[0]);
		}
	}
}

void UBattleUI::MappingSkills(SubjectClass Subject, int RowNum){
	if (!LoadedSystem) {
		CallSystem();
	}

	LoadedSystem->SkillSystem(Subject, RowNum);
}