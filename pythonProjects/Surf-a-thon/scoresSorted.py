# Initialize an empty dictionary to store names and scores
scores = {}

# Try to open and read the file
try:
    with open("results.txt", "r") as fd:
        # Loop through each line in the file
        for line in fd:
            # Split the line into name and score, assuming space as the delimiter
            parts = line.split()
            if len(parts) == 2:
                name, score = parts
                try:
                    # Convert the score to a numeric value (float or int)
                    score = float(score)
                    # Store the name and score in the dictionary
                    scores[name] = score
                except ValueError:
                    print(f"Invalid score value for {name}: {score}. Skipping this entry.")
            else:
                print(f"Invalid line format: {line.strip()}. Skipping this line.")
    
    # Sort the dictionary by scores in descending order and print the results
    for name in sorted(scores, key=scores.get, reverse=True):
        print(f"{name}: {scores[name]}")
except FileNotFoundError:
    print("The file 'results.txt' was not found.")
except IOError:
    print("An error occurred while reading the file.")
