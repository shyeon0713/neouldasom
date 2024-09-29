// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BattleUI.h"
#include "Kismet/GameplayStatics.h"


UBattleUI::UBattleUI(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer){
	Success = Cast<UImage>(GetWidgetFromName(TEXT("Success")));
	Fail = Cast<UImage>(GetWidgetFromName(TEXT("Fail")));
}

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
	ShowPassFailCutIn(LoadedSystem->GetSkillIsSucceed());
	LoadedSystem->EndTurn();
}

void UBattleUI::ShowPassFailCutIn(bool IsSucceed){
	FTimerHandle CutInTimerHnadle;

	if (IsSucceed) {
 		Success->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	else if(!IsSucceed) {
		Fail->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}
