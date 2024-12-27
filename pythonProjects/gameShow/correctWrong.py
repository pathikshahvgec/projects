from playSound import playSoundFile

noOfQues = 0
noOfCorrect = 0
noOfWrong = 0

correctAnswerSoundFile = "hfprog_sounds/correct.wav"
wrongAnswerSoundFile = "hfprog_sounds/wrong.wav"

prompt = "Press 1 for Correct, 2 for Wrong, or 0 to Quit:"
choice = input(prompt)

while(choice != "0"):
    if(choice == "1"):
        noOfQues += 1
        noOfCorrect += 1
        playSoundFile(correctAnswerSoundFile)
    if(choice == "2"):
        noOfQues += 1
        noOfWrong += 1
        playSoundFile(wrongAnswerSoundFile)
    choice = input(prompt)

print("You asked in total ", noOfQues, " no. of questions.")
print("From which ", noOfCorrect, " were correctly answered.")
print(noOfWrong, " were answered incorrectly.")
