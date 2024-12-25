import sqlite3  # Import the sqlite3 module for database operations

def connectAndFetch(dbName, query, lookupId):
    try:
        # Connect to the SQLite database specified by 'dbName'
        db = sqlite3.connect(dbName)
        db.row_factory = sqlite3.Row  # Set the row factory to sqlite3.Row to access columns by name
        
        # Create a cursor object to execute SQL queries
        cursor = db.cursor()
        
        # Optimize query to fetch only the required row using a parameterized query
        optimized_query = "SELECT * FROM surfers WHERE id = ?"
        cursor.execute(optimized_query, (lookupId,))
        
        # Fetch the row if it exists
        row = cursor.fetchone()
        
        # If a matching row is found, construct a dictionary with its details
        if row:
            s = {
                "id": str(row["id"]),
                "name": row["name"],
                "country": row["country"],
                "average": str(row["average"]),
                "board": row["board"],
                "age": str(row["age"])
            }
            return s
        
        # Return an empty dictionary if no matching row is found
        return {}
    
    except sqlite3.Error as e:
        # Handle SQLite errors and print an error message
        print(f"Database error: {e}")
        return {}
    
    except Exception as e:
        # Handle other unexpected errors
        print(f"Unexpected error: {e}")
        return {}
    
    finally:
        # Ensure the database connection is closed
        if 'db' in locals():
            db.close()
