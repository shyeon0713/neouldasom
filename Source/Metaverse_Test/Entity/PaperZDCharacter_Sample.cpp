// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/PaperZDCharacter_Sample.h"

APaperZDCharacter_Sample::APaperZDCharacter_Sample(){

}

int APaperZDCharacter_Sample::GetHP(){return EntityInfo.Hp;}

int APaperZDCharacter_Sample::GetMP(){return EntityInfo.Mp;}

void APaperZDCharacter_Sample::SetHP(int HpMount){
}

void APaperZDCharacter_Sample::SetMP(int MpCost){
}

void APaperZDCharacter_Sample::BeginPlay()
{
	Super::BeginPlay();


}
