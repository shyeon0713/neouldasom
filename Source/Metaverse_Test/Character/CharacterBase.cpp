// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"

ACharacterBase::ACharacterBase()
{
}

void ACharacterBase::InitializeInfo(int H, int D, int C, int W, int F){
	Humanity = H;
	Desire = D;
	Courtesy = C;
	Wisdom = W;
	Fortune = F;

	Hp = Desire + Fortune + 18;
	Mp = Humanity + Courtesy + Wisdom + 6;
}

int ACharacterBase::GetHP(){return Hp;}

int ACharacterBase::GetMP(){return Mp;}

void ACharacterBase::SetHP(int HpMount){
	Hp += HpMount;
}

void ACharacterBase::SetMP(int MpCost){
	Mp += MpCost;
}

void ACharacterBase::BeginPlay(){
	Super::BeginPlay();
}
