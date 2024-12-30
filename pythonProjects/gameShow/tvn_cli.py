from playSound import playSoundFile

def main():
    """
    Main function to track quiz responses and play corresponding sounds for correct and incorrect answers.
    """
    # Initialize counters for questions, correct answers, and wrong answers
    no_of_questions = 0
    no_of_correct = 0
    no_of_wrong = 0

    # File paths for the sound effects
    correct_answer_sound_file = "hfprog_sounds/correct.wav"
    wrong_answer_sound_file = "hfprog_sounds/wrong.wav"

    # Prompt displayed to the user
    prompt = "Press 1 for Correct, 2 for Wrong, or 0 to Quit: "

    # Loop to process user input until the user decides to quit
    while True:
        choice = input(prompt).strip()
        
        if choice == "0":
            # Exit the loop when the user chooses to quit
            break
        elif choice == "1":
            # Increment question and correct answer counters
            no_of_questions += 1
            no_of_correct += 1
            # Play the correct answer sound
            playSoundFile(correct_answer_sound_file)
        elif choice == "2":
            # Increment question and wrong answer counters
            no_of_questions += 1
            no_of_wrong += 1
            # Play the wrong answer sound
            playSoundFile(wrong_answer_sound_file)
        else:
            # Handle invalid input
            print("Invalid choice. Please enter 1, 2, or 0.")

    # Display the summary of results
    print(f"You asked a total of {no_of_questions} questions.")
    print(f"Of those, {no_of_correct} were answered correctly.")
    print(f"{no_of_wrong} were answered incorrectly.")

if __name__ == "__main__":
    main()
