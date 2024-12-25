# Import the 'connectAndFetch' function from the custom 'sqlite3API' module
from sqlite3API import connectAndFetch

# Prompt the user to input the ID of the surfer to look up
lookupId = input("Enter the ID of the surfer: ")

# Define the database file name
dbName = "surfersDB.sdb"

# Define the SQL query to fetch surfer details by ID
query = "SELECT * FROM surfers WHERE id = ?"

# Call the 'connectAndFetch' function to retrieve details of the surfer with the specified ID
surferDetails = connectAndFetch(dbName, query, lookupId)

# Check if the surfer's details were retrieved successfully
if surferDetails:
    # Print the surfer's details in a formatted way
    print("\nSurfer Details:")
    print("---------------")
    print(f"ID           : {surferDetails['id']}")
    print(f"Name         : {surferDetails['name']}")
    print(f"Country      : {surferDetails['country']}")
    print(f"Average      : {surferDetails['average']}")
    print(f"Board Type   : {surferDetails['board']}")
    print(f"Age          : {surferDetails['age']}")
else:
    print(f"No surfer found with ID {lookupId}. Please check the ID and try again.")
