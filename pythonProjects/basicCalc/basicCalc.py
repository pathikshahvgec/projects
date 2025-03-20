while(True):
    
    print("===Welcome to basic Calculator!===")
    print("Select any one operation from given below list:")
    print("1. For Addition, Select '+' ")
    print("2. For Subtraction, Select '-' ")
    print("3. For Multiplication, Select '*' ")
    print("4. For Division, Select '/' ")
    print("5. For Exit, Enter 5 ")
    choice = input("Please enter your choice:")

    if(choice == "5"):
        print("Exiting... Thank you!")
        break

    try:
        num1 = float(input("Enter first number : "))
        num2 = float(input("Enter second number : "))

    
        match(choice):
            case "+":
                print("Result for %f + %f is %f." %(num1, num2, num1 + num2))

            case "-":
                print("Result for %f - %f is %f." %(num1, num2, num1 - num2))

            case "*":
                print("Result for %f * %f is %f." %(num1, num2, num1 * num2))

            case "/":
                if(num2 == 0):
                    print("Division by zero is not possible!, Please try with different number.")
                else:
                    print("Result for %f / %f is %f." %(num1, num2, num1 / num2))

            case _:
                print("Invalid choice! Please enter valid choice.")

    except ValueError:
        print("Invalid input! Please enter numeric values.")
