import urllib.request
import time
from twitterAPI import sendTweet
from twilioAPI import sendSMS

url = "https://beans.itcarlow.ie/prices.html"
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36'}
req = urllib.request.Request(url, headers=headers)

def fetchPrice():
    response = urllib.request.urlopen(req)
    text = response.read().decode("utf8")
    
    index = text.find("$")
    price = float(text[index+1:index+5])
    return price

threshold = 7
askPrice = input("Do you want to check price now?(Y/N)")

if(askPrice == "y" or askPrice == "Y"):
    price = fetchPrice()
    print(price)
    msg = "Hi Twitter, Current Price for beans is " + str(price)

else:
    price = 9
    while(price > threshold):
        time.sleep(9)
        price = fetchPrice()
    print("Buy Now, Price is less than", threshold)
    msg = "Hi Twitter, You can put emergency order at " + str(price) + ". As price for beans is less than threshold value."


sendTweet(msg)
sendSMS(msg,"+911234567890")



    
    




