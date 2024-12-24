# Import the randint function from the random module to generate random numbers
from random import randint

# Print a welcome message to the user
print("Welcome")

# Generate a random secret number between 1 and 100
secret = randint(1, 100)

# Initialize the variable 'number' to store the user's guess
number = 0

# Start a loop that will continue until the user guesses the correct number
while(number != secret):
    
    # Prompt the user to input their guess and convert it to an integer
    number = int(input("Please guess a number :"))
    
    # If the guessed number is greater than the secret number
    if(number > secret):
        print("Too high, Go lower.")  # Tell the user to guess a lower number
        
    # If the guessed number is less than the secret number
    elif(number < secret):
        print("Too low, Go higher.")  # Tell the user to guess a higher number
        
    # If the guessed number is equal to the secret number
    else:
        print("You Win!")  # Congratulate the user for guessing correctly
        break  # Exit the loop since the correct guess has been made
