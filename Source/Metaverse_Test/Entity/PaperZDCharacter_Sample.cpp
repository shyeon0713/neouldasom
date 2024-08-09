// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/PaperZDCharacter_Sample.h"

APaperZDCharacter_Sample::APaperZDCharacter_Sample(){

}

void APaperZDCharacter_Sample::InitializeInfo(int H, int D, int C, int W, int F){
	Humanity = H;
	Desire = D;
	Courtesy = C;
	Wisdom = W;
	Fortune = F;

	Hp = Desire + Fortune + 18;
	Mp = Humanity + Courtesy + Wisdom + 6;
}

int APaperZDCharacter_Sample::GetHP(){return Hp;}

int APaperZDCharacter_Sample::GetMP(){return Mp;}

void APaperZDCharacter_Sample::SetHP(int HpMount){
}

void APaperZDCharacter_Sample::SetMP(int MpCost){
}

void APaperZDCharacter_Sample::BeginPlay()
{
	Super::BeginPlay();


}
