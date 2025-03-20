from datetime import datetime

def findAge():
    while(True):
        print("=== Welcome to Find Your Age App! ===")
        try:
            birthYear = int(input("Please enter your birth year and if you want to exit enter 5 : "))
            if(birthYear == 5):
                break
            else:
                currentYear = datetime.now().year
                #print(datetime.datetime.now())
                age = currentYear - birthYear
                print(age)
        except ValueError:
            print("Invalid input! Please enter only positive integer number.")


if(__name__ == "__main__"):
    findAge()
