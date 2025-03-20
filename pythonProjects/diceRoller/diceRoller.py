from random import randint

def diceRoller():
    while(True):
        input("Press Enter to roll the dice...")
        diceNum = randint(1, 6)
        print(f"You rolled the dice with value {diceNum}!")

        playAgain = input("Do you want to roll again? (yes/no) : ").strip().lower()
        if(playAgain != "yes"):
            print("Exiting... Thank you!")
            break

if(__name__ == "__main__"):
    diceRoller()
