import urllib.request
import time

url = "https://beans.itcarlow.ie/prices.html"
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36'}
req = urllib.request.Request(url, headers=headers)

price = 7
threshold = 5.5
while(price > threshold):
    time.sleep(900)
    response = urllib.request.urlopen(req)
    text = response.read().decode("utf8")

    #print(text)
    index = text.find("$")
    price = float(text[index+1:index+5])
    print(price)

print("Buy Now, Price is less than ", threshold)
