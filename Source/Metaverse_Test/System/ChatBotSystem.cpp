cpp
코드 복사
#include "ChatBotSystem.h"
#include "Interfaces/IHttpResponse.h"

// 생성자: API 키와 모델을 초기화합니다.
UChatBot::UChatBot()
{
    ApiKey = "";// OpenAI API 키를 입력
    Model = "gpt-4o";// 사용할 모델 이름 설정
}

// 사용자의 메시지를 OpenAI로 전송하는 함수void UChatBot::SendMessageToOpenAI(const FString& Message)
{
    // HTTP 요청 객체 생성 및 설정
    HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UChatBot::OnResponseReceived);

    HttpRequest->SetURL("https://api.openai.com/v1/chat/completions");
    HttpRequest->SetVerb("POST");
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->SetHeader("Authorization", FString::Printf(TEXT("Bearer %s"), *ApiKey));

    // JSON 바디 생성
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField("model", Model);

    TArray<TSharedPtr<FJsonValue>> Messages;
    TSharedPtr<FJsonObject> UserMessage = MakeShareable(new FJsonObject);
    UserMessage->SetStringField("role", "user");
    UserMessage->SetStringField("content", Message);
    Messages.Add(MakeShareable(new FJsonValueObject(UserMessage)));

    JsonObject->SetArrayField("messages", Messages);

    // JSON을 문자열로 변환하여 바디에 설정
    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
    HttpRequest->SetContentAsString(RequestBody);

    // 요청 실행
    HttpRequest->ProcessRequest();
}


// OpenAI의 응답을 처리하는 함수
void UChatBot::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response->GetResponseCode() == 200)
    {
        // JSON 응답 파싱
        TSharedPtr<FJsonObject> JsonResponse;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

        if (FJsonSerializer::Deserialize(Reader, JsonResponse))
        {
            FString AssistantResponse = JsonResponse->GetArrayField("choices")[0]
                ->AsObject()->GetObjectField("message")->GetStringField("content");

            // 응답 출력 (예: 콘솔에 출력하거나 UI에 연결)
            UE_LOG(LogTemp, Log, TEXT("ChatBot Response: %s"), *AssistantResponse);
        }
    }
    else
    {
        // 오류 처리
        UE_LOG(LogTemp, Error, TEXT("Request failed: %s"), *Response->GetContentAsString());
    }
}

