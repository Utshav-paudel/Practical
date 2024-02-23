#@ Lab1 : WAP to build simple chatbot  
# Date : 2080/10/04

response = {
    "hello" : "hello ! what can I do for you ?",
    "how are you" : "I am fine , how about you ?",
    "i am good" : "thats great to hear",
    "what do you do" : "I am unemployed, just like you ",
    "can you code for me": "no do it yourself",
    "default" : "I didn't understand sry"

}

print("Hello I am you chatbot how can I help you ? \n")
while True :
    print("user:")
    user_input = input().lower()
    if user_input == "exit":
        break
    print("chatbot:")
    reply = response.get(user_input, response["default"])
    print(reply)