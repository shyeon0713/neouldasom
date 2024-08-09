// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/PaperZDCharacter_Sample.h"

APaperZDCharacter_Sample::APaperZDCharacter_Sample(){

}

void APaperZDCharacter_Sample::InitializeStatus(int H, int W, int C, int D, int F){
	Humanity = H;
	Wisdom = W;
	Courtesy = C;
	Desire = D;
	Fortune = F;

	Hp = D + F + 18;
	Mp = H + C + W + 6;
}

int APaperZDCharacter_Sample::GetHP(){return Hp;}

int APaperZDCharacter_Sample::GetMP(){return Mp;}

void APaperZDCharacter_Sample::SetHP(int HpMount){
	Hp += HpMount;
}

void APaperZDCharacter_Sample::SetMP(int MpCost){
	Mp += MpCost;
}

bool APaperZDCharacter_Sample::IsDead(){
	int CurHp = GetHP();

	if (CurHp <= 0) return true;

	return false;
}