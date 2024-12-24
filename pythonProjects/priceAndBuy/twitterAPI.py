# Import necessary modules
import tweepy  # Library for interacting with the Twitter API
from credentials import twitterCredentials  # Import Twitter API credentials from an external file

# Function to send a tweet
# Parameter:
# - msg: The message to be tweeted as a string
def sendTweet(msg):
    # Create a Tweepy Client instance using Twitter API credentials
    api = tweepy.Client(
        bearer_token=twitterCredentials["bearerToken"],  # Bearer token for read-only access
        access_token=twitterCredentials["ACCESS_TOKEN"],  # Access token for authentication
        access_token_secret=twitterCredentials["ACCESS_TOKEN_SECRET"],  # Access token secret
        consumer_key=twitterCredentials["CONSUMER_KEY"],  # API key (consumer key)
        consumer_secret=twitterCredentials["CONSUMER_SECRET"]  # API secret (consumer secret)
    )

    # Use the Tweepy Client to create and send a tweet
    result = api.create_tweet(text=msg)  # Send the tweet with the given message

    # Print the result returned by the API for debugging or confirmation
    print(result)
    print("Tweeted Successfully!")
