print("##############################")
print(" CHATBOT")
print("##############################")
while True:
    question = input("Enter your question= ")
    question = question.lower()
    if question in ["hi", "hello"]:
        print("Hello")
    elif question in ["where do you stay?"]:
        print("I stay inside the computer")
    elif question in ["who are you?", "what are you?"]:
        print("I am a bot")
    elif question in ["how are you?"]:
        print("I am doing fine today")
    elif question in ['what are you doing?']:
        print("I am watching a movie")
    elif question in ["are you busy?"]:
        print("Yes, I am working right now")
    elif question in ['quit']:
        break
    else:
        print("I cannot answer that")
print("\n\tLab By Utshav Paudel")