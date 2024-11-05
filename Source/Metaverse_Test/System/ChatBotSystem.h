<<<<<<< Updated upstream
// Fill out your copyright notice in the Description page of Project Settings.

=======
>>>>>>> Stashed changes
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
<<<<<<< Updated upstream
#include "Http.h"
#include "Json.h"
#include "ChatBotSystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class METAVERSE_TEST_API UChatBotSystem : public UObject
=======
#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"
#include "Json.h"
#include "ChatBotSystem.generated.h"


// 블루프린트에서 사용할 델리게이트 선언
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChatBotResponseReceived, const FString&, Response);

/**
 * ChatBot 시스템 클래스
 */
UCLASS(Blueprintable)
class UChatBotSystem : public UObject
>>>>>>> Stashed changes
{
	GENERATED_BODY()
	
public:
<<<<<<< Updated upstream
	UChatBotSystem();

	//메시지를 전송하고 응답을 처리함
	UFUNCTION(BlueprintCallable, Category = "ChatBotSystem")
	void SendMessageToOpenAI(const FString& Message);
=======
    // 생성자
    UChatBotSystem();

    // API 키와 모델
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChatBot")
    FString ApiKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChatBot")
    FString Model;
    // 프롬프트를 FText로 설정하고 멀티라인 입력을 가능하게 설정
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChatBot")
    FString Prompt;

    // 프롬프트를 설정하는 함수
    UFUNCTION(BlueprintCallable, Category = "ChatBot")
    void SetPrompt(const FString& NewPrompt);

    // 사용자 메시지 전송 함수
    UFUNCTION(BlueprintCallable, Category = "ChatBot")
    void SendMessageToOpenAI(const FString& Message);
>>>>>>> Stashed changes

    // OpenAI의 응답을 블루프린트로 전달하는 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "ChatBot")
    FOnChatBotResponseReceived OnChatBotResponseReceived;

private:
<<<<<<< Updated upstream
	//HTTP 요청 초기화
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSucceed);

	//HTTP 요청용 객체
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest;

	//API와 Key 모델 설정
	FString ApiKey;
	FString Model;
};
=======
    // 응답 처리 함수
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // HTTP 요청 객체
    TSharedPtr<IHttpRequest> HttpRequest;
};
>>>>>>> Stashed changes
