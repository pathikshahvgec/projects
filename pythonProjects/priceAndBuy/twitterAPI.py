import tweepy
from credentials import twitterCredentials

def sendTweet(msg):
    api = tweepy.Client(bearer_token=twitterCredentials["bearerToken"],
                    access_token=twitterCredentials["ACCESS_TOKEN"],
                    access_token_secret=twitterCredentials["ACCESS_TOKEN_SECRET"],
                    consumer_key=twitterCredentials["CONSUMER_KEY"],
                    consumer_secret=twitterCredentials["CONSUMER_SECRET"])

    result = api.create_tweet(text = msg)
    print(result)
    print("Twitted Successfully!")
