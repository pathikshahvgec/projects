# Import necessary modules
import urllib.request  # For making HTTP requests to fetch the bean price
import time  # For adding delays in the program
from twitterAPI import sendTweet  # Custom module to send tweets
from twilioAPI import sendSMS  # Custom module to send SMS

# Define the URL of the website that displays the price of beans
url = "https://beans.itcarlow.ie/prices.html"

# Define headers to simulate a real browser request (avoiding potential bot detection)
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36'}
req = urllib.request.Request(url, headers=headers)  # Create a request object with the headers

# Function to fetch the price of beans from the website
def fetchPrice():
    # Send a request to the URL and get the response
    response = urllib.request.urlopen(req)
    text = response.read().decode("utf8")  # Decode the response to get the HTML content
    
    # Find the price in the HTML content
    index = text.find("$")  # Locate the "$" symbol
    price = float(text[index + 1:index + 5])  # Extract and convert the price to a float
    return price

# Set a threshold price for beans
threshold = 7

# Ask the user if they want to check the price immediately
askPrice = input("Do you want to check price now? (Y/N): ")

if askPrice.lower() == "y":
    # Fetch and display the current price if the user chooses to check it now
    price = fetchPrice()
    print(price)
    # Create a message for Twitter indicating the current price
    msg = "Hi Twitter, Current Price for beans is " + str(price)

else:
    # If the user doesn't want to check now, monitor the price periodically
    price = 9  # Initialize price higher than the threshold
    while price > threshold:
        time.sleep(9)  # Wait for 9 seconds before fetching the price again
        price = fetchPrice()  # Fetch the price again
        
    # Notify the user when the price falls below the threshold
    print("Buy Now, Price is less than", threshold)
    # Create a message for Twitter indicating the emergency order
    msg = "Hi Twitter, You can put an emergency order at " + str(price) + ". The price for beans is less than the threshold value."

# Send the message as a tweet
sendTweet(msg)

# Send the message as an SMS (replace the phone number with a valid one)
sendSMS(msg, "+911234567890")
