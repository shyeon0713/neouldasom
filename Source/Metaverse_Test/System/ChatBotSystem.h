cpp
�ڵ� ����
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

    // �޽����� �����ϰ� ������ ó���ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "ChatBot")
    void SendMessageToOpenAI(const FString& Message);

private:
    // HTTP ��û�� �ʱ�ȭ�ϴ� �Լ�
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // HTTP ��û�� ��ü
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> HttpRequest;

    // API Key�� �� ����
    FString ApiKey;
    FString Model;
};