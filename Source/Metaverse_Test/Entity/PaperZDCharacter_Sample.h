// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "InfoStruct.h"
#include "PaperZDCharacter_Sample.generated.h"

/**
 * 
 */
UCLASS()
class METAVERSE_TEST_API APaperZDCharacter_Sample : public APaperZDCharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	FEntityInfo EntityInfo;

public:
	APaperZDCharacter_Sample();

	//GetInfo: Function for get entities fluctuating information
	UFUNCTION(BlueprintCallable, Category = "GetInfo")
	int GetHP();
	UFUNCTION(BlueprintCallable, Category = "GetInfo")
	int GetMP();

	//SetInfo: Function for Set entities fluctuating information
	UFUNCTION(BlueprintCallable, Category = "SetInfo")
	void SetHP(int HpMount);
	UFUNCTION(BlueprintCallable, Category = "SetInfo")
	void SetMP(int MpCost);

	virtual void BeginPlay() override;
};
