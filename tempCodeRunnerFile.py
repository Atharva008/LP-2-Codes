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
