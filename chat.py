import random

# Define a dictionary of possible bot responses
bot_responses = {
    "hello": ["Hello!", "Hi there!", "Greetings!"],
    "how are you?"
    : ["I'm good, thank you!", "I'm doing great!", "All is well."],
    "bye": ["Goodbye!", "See you later!", "Take care!"],
    "default": ["I'm sorry, I didn't understand.", "Could you please rephrase that?", "I'm still learning. Can you ask something else?"]
}

# Function to generate bot responses
def generate_response(user_input):
    user_input = user_input.lower()

    # Check if the user input matches any predefined keys
    for key in bot_responses:
        if user_input.find(key) != -1:
            return random.choice(bot_responses[key])

    # If no match is found, return a default response
    return random.choice(bot_responses["default"])

# Main conversation loop
while True:
    user_input = input("User: ")
    bot_response = generate_response(user_input)
    print("Bot: " + bot_response)
