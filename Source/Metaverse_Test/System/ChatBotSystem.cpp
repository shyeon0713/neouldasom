<<<<<<< Updated upstream
// Fill out your copyright notice in the Description page of Project Settings.


#include "System/ChatBotSystem.h"
#include "Interfaces/IHttpResponse.h"

//Api랑 Key 모델 초기화
UChatBotSystem::UChatBotSystem(){
	ApiKey = "Key";// OpenAI API 키를 입력
	Model = "Model";// 사용할 모델 이름 설정
}

void UChatBotSystem::SendMessageToOpenAI(const FString& Message){
    // HTTP 요청 객체 생성 및 설정
=======
#include "ChatBotSystem.h"


// 생성자: API 키와 모델을 초기화합니다.
UChatBotSystem::UChatBotSystem()
{
    ApiKey = ""; // OpenAI API 키를 입력
    Model = "gpt-4o"; // 사용할 모델 이름 설정
    Prompt = "넌 도사들의 학교 설화학당에서 기본도술을 가르치는 강사 전훈이야. 어떤 질문을 받던 도서관으로 가도록 자연스럽게 유도해줘."; // 프롬프트 설정
}

// 프롬프트를 설정하는 함수
void UChatBotSystem::SetPrompt(const FString& NewPrompt)
{
    Prompt = NewPrompt;
}

// 사용자 메시지와 프롬프트를 OpenAI로 전송하는 함수
void UChatBotSystem::SendMessageToOpenAI(const FString& Message)
{
>>>>>>> Stashed changes
    HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UChatBotSystem::OnResponseReceived);

    HttpRequest->SetURL("https://api.openai.com/v1/chat/completions");
    HttpRequest->SetVerb("POST");
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->SetHeader("Authorization", FString::Printf(TEXT("Bearer %s"), *ApiKey));

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField("model", Model);

    TArray<TSharedPtr<FJsonValue>> Messages;
    TSharedPtr<FJsonObject> PromptMessage = MakeShareable(new FJsonObject);
    PromptMessage->SetStringField("role", "system");
    PromptMessage->SetStringField("content", Prompt); // Prompt를 FString으로 변환
    Messages.Add(MakeShareable(new FJsonValueObject(PromptMessage)));

    TSharedPtr<FJsonObject> UserMessage = MakeShareable(new FJsonObject);
    UserMessage->SetStringField("role", "user");
    UserMessage->SetStringField("content", Message);
    Messages.Add(MakeShareable(new FJsonValueObject(UserMessage)));

    JsonObject->SetArrayField("messages", Messages);

    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
    HttpRequest->SetContentAsString(RequestBody);

    HttpRequest->ProcessRequest();
}

<<<<<<< Updated upstream
void UChatBotSystem::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSucceed){
    if (bWasSucceed && Response->GetResponseCode() == 200)
=======
// OpenAI의 응답을 처리하는 함수
void UChatBotSystem::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response->GetResponseCode() == 200)
>>>>>>> Stashed changes
    {
        TSharedPtr<FJsonObject> JsonResponse;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

        if (FJsonSerializer::Deserialize(Reader, JsonResponse))
        {
            FString AssistantResponse = JsonResponse->GetArrayField("choices")[0]
                ->AsObject()->GetObjectField("message")->GetStringField("content");

            OnChatBotResponseReceived.Broadcast(AssistantResponse);

            UE_LOG(LogTemp, Log, TEXT("ChatBot Response: %s"), *AssistantResponse);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Request failed: %s"), *Response->GetContentAsString());
    }
}
