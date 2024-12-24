I’ve created a fun number-guessing game that you might recognize!

In this game, I've chosen a random number between 1 and 100, and your challenge is to guess it with the fewest tries possible.
If you follow a strategy like binary search, you could get it in about 7 guesses. But don’t worry if it takes you a little longer at first—practice makes perfect!

A huge shoutout to Anvil for letting me create and host this web app for everyone to enjoy. Come join the fun and give it a try by clicking the link below:  
https://fuzzy-squiggly-cavy.anvil.app/

# Number Guessing Game

## Description

This is a simple Python-based number guessing game. The program generates a random secret number between 1 and 100, and the user must guess the number. After each guess, the program provides hints to guide the user: whether the guess is too high, too low, or correct. The game ends when the user correctly guesses the secret number.

## How It Works

1. The program generates a random number between 1 and 100.
2. The user is prompted to guess the number.
3. After each guess, the program provides feedback:
   - "Too high, Go lower." if the guess is higher than the secret number.
   - "Too low, Go higher." if the guess is lower than the secret number.
   - "You Win!" when the guess is correct.
4. The loop continues until the correct number is guessed.

## Prerequisites

- Python 3.x must be installed on your system.

## How to Run

1. Clone or download this repository.
2. Open a terminal or command prompt in the directory containing the script.
3. Run the script using Python:
   ```bash
   python guessing_game.py
   ```
4. Follow the on-screen instructions to play the game.

## Example

```text
Welcome
Please guess a number: 50
Too high, Go lower.
Please guess a number: 25
Too low, Go higher.
Please guess a number: 30
You Win!
```

## Features

- Generates a random secret number every time the game is played.
- Provides real-time feedback to help the user guess the number.
- Simple and fun for users of all ages.

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute it.

## Acknowledgments

- Inspired by basic number guessing games to demonstrate Python programming.
```

Let me know if you’d like to make any changes or include additional details!
