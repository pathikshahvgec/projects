from random import randint

print("Welcome")
secret = randint(1, 100)
number = 0

while(number != secret):

    number = int(input("Please guess a number :"))
    
    if(number > secret):
        print("Too high, Go lower.")
    elif(number < secret):
        print("Too low, Go higher.")
    else:
        print("You Win!")
        break

