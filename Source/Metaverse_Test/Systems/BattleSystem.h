// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Entity/PaperZDCharacter_Sample.h"
#include "BattleSystem.generated.h"

UCLASS()
class METAVERSE_TEST_API ABattleSystem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABattleSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsBattleOver;

	void RunSystem();
	void IsEndGame(bool isDead);

	void BattleTurnPlayer();
	void BattleTurnEnemy();

	void AttackSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity);
	void DepenseSkill(APaperZDCharacter_Sample* SelfEntity);
	void HealSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity);
	void SupportSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity);
	void PracticalSkill(APaperZDCharacter_Sample* SelfEntity, APaperZDCharacter_Sample* OtherEntity);
};