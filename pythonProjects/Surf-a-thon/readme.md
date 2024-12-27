# Surfer Lookup Application

This application provides functionality to look up surfer details from a database or a CSV file using a surfer's ID. It demonstrates Python's `sqlite3` module for database operations and file handling for CSV processing.

## Features
- Fetch surfer details by ID from an SQLite database.
- Retrieve surfer details from a CSV file as a fallback.
- Handles errors gracefully, including database and file-related exceptions.

---

## Prerequisites
- Python 3.6 or later
- SQLite installed on your system
- A CSV file (`surfing_data.csv`) and an SQLite database (`surfersDB.sdb`) with the required structure and data.

---

## File Structure
- **sqlite3API.py**: Contains the `connectAndFetch` function to interact with the SQLite database.
- **fetchFromDB.py**: The main script to execute the application and display surfer details.

---

## Setup

### Database Structure
Ensure the SQLite database (`surfersDB.sdb`) has the following table structure:
```sql
CREATE TABLE surfers (
    id INTEGER PRIMARY KEY,
    name TEXT,
    country TEXT,
    average REAL,
    board TEXT,
    age INTEGER
);
```

### CSV File Format
The `surfing_data.csv` should be structured as follows:
```
id;name;country;average;board;age
1;John Doe;USA;8.5;Shortboard;25
2;Jane Smith;Australia;9.2;Longboard;22
```

---

## Usage

### Running the Application
1. Clone or download this repository.
2. Place the `surfing_data.csv` and `surfersDB.sdb` files in the same directory as the scripts.
3. Run the application using:
   ```bash
   python fetchFromDB.py
   ```
4. Enter the surfer's ID when prompted to retrieve details.

### Example Output
#### Case: Surfer Found in Database
```plaintext
Enter the ID of the surfer: 1

Surfer Details:
---------------
ID           : 1
Name         : John Doe
Country      : USA
Average      : 8.5
Board Type   : Shortboard
Age          : 25
```

#### Case: Surfer Not Found
```plaintext
Enter the ID of the surfer: 99
No surfer found with ID 99. Please check the ID and try again.
```

---

## Error Handling
- **Database Errors**: Gracefully handled with detailed error messages.
- **File Not Found**: Displays a clear error message if the CSV file is missing.

---

## Contributing
Feel free to contribute by opening a pull request or filing an issue. Suggestions for improvement are always welcome!

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
```

This template includes all relevant sections and is easy to adapt if you make further changes to your code. Let me know if you'd like to tweak or expand any part!
