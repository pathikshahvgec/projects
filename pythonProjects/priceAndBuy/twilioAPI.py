from twilio.rest import Client
from credentials import twilioCredentials

msg = "My First Message via Twilio API"

# Create Twilio client
client = Client(twilioCredentials["accountSID"], twilioCredentials["authToken"])

# Send SMS
# in body part you have to write your message
def sendSMS(msg, recipientPhoneNum):
    message = client.messages.create(
    body=msg,
    from_=twilioCredentials["twilioPhoneNum"],
    to=recipientPhoneNum
    )
    print(f"Message sent with SID: {message.sid}")
