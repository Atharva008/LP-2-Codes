import random
import re

bot_responces = {
    "greeting": ["Welcome to our hotel!", "Hello! How can I assist you?", "Greetings! How may I help you today?"],
    "check availability": ["Sure, let me check the availability for you.", "I can help you with that. Please wait a moment.", "Let me see if we have any rooms available."],
    "book room": ["Great! We have rooms available for your selected dates.", "Yes, we can book a room for you. Please provide me with your details.", "Certainly! I will assist you in booking a room."],
    "cancel booking": ["I'm sorry to hear that. Can you please provide your booking details?", "I understand. To cancel your booking, I will need your reservation information.", "Sure, I can assist you in canceling your booking. Please provide me with the necessary details."],
    "room service": ["Yes, we provide room service. What would you like to order?", "Certainly! Our room service menu is available in your room. How can I assist you?", "Of course! I can help you with room service. What do you need?"],
    "check out": ["Sure, I can assist you with the check-out process. Please provide me with your room number.", "To proceed with the check-out, I will need your room details. Can you please provide them?", "Certainly! I can help you with the check-out. Please give me your room number and any additional information."],
    "thank you": ["You're welcome! If you have any more questions, feel free to ask.", "You're welcome! It was my pleasure to assist you.", "You're welcome! Have a great day!"],
    "default": ["I apologize, but I'm not able to assist with that. Can you please ask a different question?", "I'm sorry, but I didn't quite understand. Could you rephrase your request?", "I'm still learning. Can you please provide more information?"]
}


def generate_responce(user_input) :

    user_input = user_input.lower()

    if(re.search("hi|hello|hey|greeting", user_input)):
        return random.choice(bot_responces["greeting"])
    
    if(re.search("check|availability|available|check availability", user_input)):
        return random.choice(bot_responces["check availability"])
    
    if(re.search("book|room|booking|book room", user_input)):
        return random.choice(bot_responces["book room"])
    
    if(re.search("out|checkout|check out", user_input)):
        return random.choice(bot_responces["check out"])
    
    if(re.search("cancel|cancel booking", user_input)):
        return random.choice(bot_responces["cancel booking"])
    
    if(re.search("service|help|assist|room service", user_input)):
        return random.choice(bot_responces["room service"])
    
    if(re.search("thanks|thank you", user_input)):
        return random.choice(bot_responces["thank you"])
    
    return random.choice(bot_responces["default"])
    
    

    


    # for key in bot_responces:
    #     if(user_input.find(key) != -1):
    #         return random.choice(bot_responces[key]) 
    
    # return random.choice(bot_responces["default"])


# user_input = "Hello"
while True:
    print("user :" )
    user_input = input()
    responce = generate_responce(user_input)
    if(user_input == "exit"):
        break
    print(responce)




