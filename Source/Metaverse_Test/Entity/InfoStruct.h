// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfoStruct.generated.h"

/**
 * 
 */

USTRUCT(Atomic, BlueprintType)
struct FEntityInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Humanity; //인심
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Willingness; //의지
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Courtesy; //예절
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Wisdom; //지혜
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Fortune; //천운


	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int Hp = Willingness + Fortune + 18; //체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Mp = Humanity + Courtesy + Wisdom + 6; //도력
};

class METAVERSE_TEST_API InfoStruct
{
public:
	InfoStruct();
	~InfoStruct();
};
