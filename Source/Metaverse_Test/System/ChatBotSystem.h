#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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

{
	GENERATED_BODY()
	
public:
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

    // OpenAI의 응답을 블루프린트로 전달하는 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "ChatBot")
    FOnChatBotResponseReceived OnChatBotResponseReceived;

private:
    // 응답 처리 함수
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // HTTP 요청 객체
    TSharedPtr<IHttpRequest> HttpRequest;
};
