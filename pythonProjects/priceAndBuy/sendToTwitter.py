import urllib.request
import time

url = "https://beans.itcarlow.ie/prices.html"
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36'}
req = urllib.request.Request(url, headers=headers)

def fetchAndDispalyPrice():
    response = urllib.request.urlopen(req)
    text = response.read().decode("utf8")

    #print(text)
    index = text.find("$")
    price = float(text[index+1:index+5])
    return price

threshold = 6
askPrice = input("Do you want to check price now?(Y/N)")

if(askPrice == "y" or askPrice == "Y"):
    price = fetchAndDispalyPrice()
    print(price)
else:
    price = 9
    while(price > threshold):
        time.sleep(900)
        price = fetchAndDispalyPrice()
    print("Buy Now, Price is less than", threshold)
    
