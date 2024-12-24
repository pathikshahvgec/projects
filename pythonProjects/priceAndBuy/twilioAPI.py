# Import necessary modules
from twilio.rest import Client  # Import the Client class to interact with the Twilio API
from credentials import twilioCredentials  # Import Twilio credentials from an external file

# Define the message to be sent
msg = "My First Message via Twilio API"

# Create a Twilio client instance using account SID and authentication token
client = Client(twilioCredentials["accountSID"], twilioCredentials["authToken"])

# Function to send an SMS
# Parameters:
# - msg: The message to be sent as a string
# - recipientPhoneNum: The recipient's phone number as a string
def sendSMS(msg, recipientPhoneNum):
    # Use the Twilio client to send an SMS message
    message = client.messages.create(
        body=msg,  # The message content
        from_=twilioCredentials["twilioPhoneNum"],  # Twilio phone number
        to=recipientPhoneNum  # Recipient's phone number
    )
    # Print the SID of the sent message to confirm successful delivery
    print(f"Message sent with SID: {message.sid}")
