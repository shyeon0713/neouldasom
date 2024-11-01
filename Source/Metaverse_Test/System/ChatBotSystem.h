cpp
코드 복사
#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "Json.h"
#include "ChatBot.generated.h"

UCLASS()
class Metaverse_Test_API UChatBot : public UObject
{
    GENERATED_BODY()

public:
    UChatBot();

    // 메시지를 전송하고 응답을 처리하는 함수
    UFUNCTION(BlueprintCallable, Category = "ChatBot")
    void SendMessageToOpenAI(const FString& Message);

private:
    // HTTP 요청을 초기화하는 함수
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // HTTP 요청용 객체
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest;

    // API Key와 모델 설정
    FString ApiKey;
    FString Model;
};