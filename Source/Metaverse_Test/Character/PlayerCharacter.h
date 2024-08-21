// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class METAVERSE_TEST_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
protected:
	int BasicMagicPoint;
	int DepenseMagicPoint;
	int SomaticMagicPoint;
	int NatureMagicPoint;
	int OrieantalMedicinePoint;
	int ExplorationMagicPoint;
};
