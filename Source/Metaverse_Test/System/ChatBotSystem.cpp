#include "ChatBotSystem.h"


//**생성자: API 키와 모델을 초기화합니다.
UChatBotSystem::UChatBotSystem()
{
    ApiKey = ""; // OpenAI API 키를 입력
    Model = "gpt-4o"; // 사용할 모델 이름 설정
    Prompt = ""; // 프롬프트 설정
}

//**프롬프트를 설정하는 함수
void UChatBotSystem::SetPrompt(const FString& NewPrompt)// 새로운 프롬프트(초기 메시지)를 설정하는 함수
{
    Prompt = NewPrompt;    // 프롬프트를 전달받은 새 프롬프트로 업데이트합니다.
}

//**사용자 메시지와 프롬프트를 OpenAI로 전송하는 함수
void UChatBotSystem::SendMessageToOpenAI(const FString& Message)// 사용자 메시지와 프롬프트를 OpenAI 서버로 전송하는 함수
{
    HttpRequest = FHttpModule::Get().CreateRequest(); // HTTP 요청을 생성합니다.
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UChatBotSystem::OnResponseReceived);// HTTP 요청 완료 시 응답을 처리하는 콜백을 설정합니다.

    HttpRequest->SetURL("https://api.openai.com/v1/chat/completions");// OpenAI API의 URL을 설정합니다.
    HttpRequest->SetVerb("POST");// 요청 방식(POST)을 설정합니다.
    HttpRequest->SetHeader("Content-Type", "application/json");// 요청의 Content-Type을 JSON 형식으로 설정합니다.
    HttpRequest->SetHeader("Authorization", FString::Printf(TEXT("Bearer %s"), *ApiKey));// API 키를 Authorization 헤더에 추가합니다.

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);// JSON 객체를 생성합니다.
    JsonObject->SetStringField("model", Model);// 사용하려는 모델 이름을 JSON에 추가합니다.

    TArray<TSharedPtr<FJsonValue>> Messages;// 메시지 배열을 생성하여 프롬프트와 사용자 메시지를 추가합니다.
    TSharedPtr<FJsonObject> PromptMessage = MakeShareable(new FJsonObject);// 시스템 역할의 메시지(프롬프트)를 JSON 객체로 생성합니다.
    PromptMessage->SetStringField("role", "system");
    PromptMessage->SetStringField("content", Prompt); // Prompt를 FString으로 변환
    Messages.Add(MakeShareable(new FJsonValueObject(PromptMessage))); // 생성한 프롬프트 메시지를 메시지 배열에 추가합니다.

    TSharedPtr<FJsonObject> UserMessage = MakeShareable(new FJsonObject);// 사용자 역할의 메시지를 JSON 객체로 생성합니다.
    UserMessage->SetStringField("role", "user");
    UserMessage->SetStringField("content", Message);
    Messages.Add(MakeShareable(new FJsonValueObject(UserMessage)));// 생성한 사용자 메시지를 메시지 배열에 추가합니다.

    JsonObject->SetArrayField("messages", Messages);// 메시지 배열을 JSON 객체에 설정합니다.

    FString RequestBody;// JSON 객체를 문자열로 직렬화하여 요청 본문에 설정합니다.
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
    HttpRequest->SetContentAsString(RequestBody);

    HttpRequest->ProcessRequest();// HTTP 요청을 전송합니다.

}

// OpenAI의 응답을 처리하는 함수
void UChatBotSystem::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response->GetResponseCode() == 200)// 요청이 성공하고 응답 코드가 200일 경우에만 처리합니다.
    {
        TSharedPtr<FJsonObject> JsonResponse;// JSON 응답을 파싱할 JsonResponse 객체를 생성합니다.
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

        if (FJsonSerializer::Deserialize(Reader, JsonResponse))// 응답을 JsonResponse에 파싱합니다.
        {
            FString AssistantResponse = JsonResponse->GetArrayField("choices")[0]// 응답 JSON에서 봇의 응답을 추출합니다.
                ->AsObject()->GetObjectField("message")->GetStringField("content");

            OnChatBotResponseReceived.Broadcast(AssistantResponse);// 응답 수신 시 브로드캐스트 이벤트를 통해 다른 시스템에 알립니다.

            UE_LOG(LogTemp, Log, TEXT("ChatBot Response: %s"), *AssistantResponse);// 봇 응답을 로그에 출력합니다.
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Request failed: %s"), *Response->GetContentAsString());// 요청 실패 시 오류 내용을 로그에 출력합니다.
    }
}
