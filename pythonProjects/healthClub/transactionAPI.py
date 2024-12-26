def saveTransaction(price, creditCardNum, description):
    try:
        with open("transaction.txt", "a") as fd:
            line = "%s%07d%s\n" % (creditCardNum, price * 100, description)
            fd.write(line)
        print("Transaction saved successfully.")
    except FileNotFoundError:
        print("Error: The file 'transaction.txt' was not found.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
