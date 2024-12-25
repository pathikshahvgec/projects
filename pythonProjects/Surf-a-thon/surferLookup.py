def findDetails(lookupId):
    """
    Find the details of a surfer by their ID from a CSV file.
    Args:
        lookupId (str): The ID of the surfer to look up.
    Returns:
        list or None: A list of details if found, otherwise None.
    """
    try:
        # Open the file using 'with' to ensure proper resource management
        with open("surfing_data.csv") as fd:
            for line in fd:
                # Split the line into fields using ';' as the delimiter
                fields = line.strip().split(";")
                # Check if the ID matches the first field
                if fields[0] == lookupId:
                    return fields
        # Return None if no match is found
        return None
    except FileNotFoundError:
        print("Error: The file 'surfing_data.csv' was not found.")
        return None
    except Exception as e:
        print(f"Unexpected error: {e}")
        return None

# Prompt the user to enter a surfer ID
lookupId = input("Enter the ID of Surfer:")

# Retrieve surfer details
surferDetails = findDetails(lookupId)

# Display surfer details if found
if surferDetails:
    print("ID           :", surferDetails[0])
    print("Name         :", surferDetails[1])
    print("Country      :", surferDetails[2])
    print("Average      :", surferDetails[3])
    print("Board Type   :", surferDetails[4])
    print("Age          :", surferDetails[5])
else:
    print("No surfer found with the given ID.")
