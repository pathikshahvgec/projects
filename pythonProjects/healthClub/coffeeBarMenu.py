from transactionAPI import saveTransaction
import promotion
import starbuzz

menuItems = ["DONUT", "LATTE", "FILTER", "MUFFIN"]
prices = [1.50, 2.0, 1.80, 1.20]

while True:
    # Display the menu
    for i, item in enumerate(menuItems, start=1):
        print(f"{i}. {item}")
    print(f"{len(menuItems) + 1}. Quit")

    # User input for menu choice
    try:
        choice = int(input("Please select a menu option number from the options above: "))
    except ValueError:
        print("Invalid input! Please enter a number.")
        continue

    # Exit condition
    if choice == len(menuItems) + 1:
        print("Exiting... Thank you!")
        break

    # Check for invalid menu selection
    if choice < 1 or choice > len(menuItems):
        print("Please enter a valid number from the menu.")
        continue

    # Process the order
    creditCardNumber = input("Enter your credit card number: ")
    price = promotion.discount(prices[choice - 1])
    
    # Check for Starbuzz card discount
    checkStarbuzzCard = input("Do you also have a Starbuzz Card? (Y/N): ").strip().lower()
    if checkStarbuzzCard == "y":
        price = starbuzz.discount(price)
    
    # Save the transaction
    saveTransaction(price, creditCardNumber, menuItems[choice - 1])
    print(f"Transaction saved for {menuItems[choice - 1]} at ${price:.2f}.")
    break
