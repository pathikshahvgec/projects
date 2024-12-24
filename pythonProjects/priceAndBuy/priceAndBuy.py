# Import necessary modules
import urllib.request  # For making HTTP requests to fetch the price of beans
import time  # For adding a delay between price checks

# Define the URL of the website that displays the price of beans
url = "https://beans.itcarlow.ie/prices.html"

# Define headers to simulate a real browser request (avoiding potential bot detection)
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36'}
req = urllib.request.Request(url, headers=headers)  # Create a request object with the headers

# Initialize the price to a value greater than the threshold
price = 7

# Set the threshold price
threshold = 5.5

# Start a loop that will continue until the price drops below the threshold
while price > threshold:
    # Wait for 15 minutes (900 seconds) before checking the price again
    time.sleep(900)
    
    # Fetch the webpage containing the price
    response = urllib.request.urlopen(req)
    text = response.read().decode("utf8")  # Decode the response to get the HTML content
    
    # Extract the price from the HTML content
    index = text.find("$")  # Locate the "$" symbol in the HTML
    price = float(text[index + 1:index + 5])  # Extract and convert the price to a float
    
    # Print the current price to the console
    print(price)

# Notify the user to buy beans once the price is below the threshold
print("Buy Now, Price is less than", threshold)
