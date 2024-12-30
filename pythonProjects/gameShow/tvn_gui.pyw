from tkinter import *
from playSound import playSoundFile

def correctClick():
    correct_count.set(correct_count.get() + 1)
    playSoundFile("hfprog_sounds/correct.wav")

def wrongClick():
    wrong_count.set(wrong_count.get() + 1)
    playSoundFile("hfprog_sounds/wrong.wav")

# Initialize the main application window
app = Tk()
app.title("TVN Game Show")
app.geometry("300x100+200+100")

# Variables to track correct and wrong answers
correct_count = IntVar()
correct_count.set(0)
wrong_count = IntVar()
wrong_count.set(0)

# Labels to display counts
correct_display = Label(app, textvariable=correct_count, font=("Arial", 10))
correct_display.pack(side="left", padx=5, pady=10)

wrong_display = Label(app, textvariable=wrong_count, font=("Arial", 10))
wrong_display.pack(side="right", padx=5, pady=10)

# Buttons to increment counts
correct_button = Button(app, text="Correct!", width=10, command=correctClick)
correct_button.pack(side="left", padx=10, pady=10)

wrong_button = Button(app, text="Wrong!", width=10, command=wrongClick)
wrong_button.pack(side="right", padx=10, pady=10)

# Start the application loop
app.mainloop()
