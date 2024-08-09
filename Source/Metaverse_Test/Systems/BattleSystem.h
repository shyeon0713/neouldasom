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

	void IsEndGame(bool isDead);

	void AttackSkill(APaperZDCharacter_Sample* Player, APaperZDCharacter_Sample*Monster);
};