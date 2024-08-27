// Fill out your copyright notice in the Description page of Project Settings.


#include "Control/BattlePlayerController.h"
#include "Blueprint/UserWidget.h"

ABattlePlayerController::ABattlePlayerController(){
    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(TEXT("/Game/BattleMap/SampleButton/MyBattleUI.MyBattleUI_C"));
    if (WidgetClassFinder.Succeeded())
    {
        HUDWidgetClass = WidgetClassFinder.Class;
    }
}

void ABattlePlayerController::BeginPlay(){
	Super::BeginPlay();

    // 마우스 커서를 항상 보이도록 설정
    bShowMouseCursor = true;

    // 입력 모드를 게임과 UI를 모두 사용할 수 있도록 설정
    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // 필요에 따라 마우스 락 모드 설정 가능
    SetInputMode(InputMode);
	CreateHUD();
} 

void ABattlePlayerController::CreateHUD(){
    HUDWidget = CreateWidget(GetWorld()->GetFirstPlayerController(), HUDWidgetClass);
    HUDWidget->AddToViewport();
}
