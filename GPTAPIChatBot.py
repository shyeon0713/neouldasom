import openai
import os

# API키 입력하는 곳
openai.api_key = ''



class ChatBot:
    def __init__(self, engine: str = "gpt-4o") -> None:
        self.model = engine
        self.conversation_history = [{"role": "system", "content": "넌 이것저것 도와줘야해."}] #역할 설정

    def send_message(self, message: str) -> str:
        assistant_response = ""
        self.conversation_history.append({"role": "user", "content": message})
        try:
            response = openai.ChatCompletion.create(
                model=self.model,
                messages=self.conversation_history,
            )
            # 대답 받기
            assistant_response = response.choices[0].message['content']
            self.conversation_history.append({"role": "assistant", "content": assistant_response})
        except openai.error.AuthenticationError as error:
            print("error: {0}".format(error.args))
        except openai.error.RateLimitError as error:
            print("error: {0}".format(error.args))
        except openai.error.InvalidRequestError as error:
            print("error: {0}".format(error.args))
        except openai.error.PermissionError as error:  
            print("error: {0}".format(error.args))
        return assistant_response


def main():
    print("Welcome to ChatBot! Type 'quit' to exit.")
    chatbot = ChatBot()

    while True:
        user_input = input("화자: ")
        if user_input.lower() == 'quit':
            break
        response = chatbot.send_message(user_input)
        print("ChatBot:", response)


if __name__ == "__main__":
    main()        