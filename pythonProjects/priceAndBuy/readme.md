Do you often find yourself anxiously watching stock prices on listing websites, trying to make that tough decision to buy or sell? Do you relate to the excitement of checking prices on wishlist items from e-commerce sites, only to rush to purchase when they finally drop?

These situations can feel overwhelming, but there's good news! You can simplify and automate these processes with a Python script.

Take, for example, the situation described in the "Head First" book, where the CEO of Starbuzz wants to ensure they buy coffee beans at the right moment for the best price. They have two thoughtful options for placing orders:

1. When time is of the essence, they can make a purchase at the current market price.
2. If there's a bit of breathing room, they can monitor prices regularly and place an order when it dips below a certain threshold.

To make things even easier, I can send price updates directly to my phone using an SMS service, thanks to the Twilio API. It’s all about staying informed without the stress!

Furthermore, the CEO also wants to create a sense of community by sharing price updates through their Twitter account, allowing everyone to stay in the loop. With the Twitter API, this can become a reality.

By embracing this automated approach, you can take the pressure off and navigate these decisions with greater ease and confidence. You’re not alone in this journey!


# Bean Price Tracker

The **Bean Price Tracker** is a Python application designed to monitor the price of beans from an online source. It sends notifications via Twitter and SMS when the price falls below a predefined threshold.

---

## Features

- **Real-Time Price Monitoring**: Fetches the current price of beans from a specified website.
- **Threshold Alert System**: Notifies the user when the price drops below a defined threshold.
- **Twitter Integration**: Automatically sends tweets about bean prices using the Twitter API.
- **SMS Alerts**: Sends SMS alerts to a specified phone number using the Twilio API.

---

## Prerequisites

1. **Python 3.7 or later**
2. Required Python Libraries:
   - `urllib`
   - `time`
   - `tweepy` (for Twitter API)
   - `twilio` (for SMS)
3. **API Credentials**:
   - Twitter API keys and tokens
   - Twilio account SID, auth token, and phone number
4. A valid phone number to receive SMS alerts.

---

## File Structure

- **main.py**: The main script to monitor prices and send notifications.
- **twitterAPI.py**: Contains functionality for sending tweets.
- **twilioAPI.py**: Handles SMS notifications using the Twilio API.
- **credentials.py**: Stores sensitive API credentials (not included for security reasons).

---

## Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/bean-price-tracker.git
   cd bean-price-tracker
   ```

2. Install required Python libraries:
   ```bash
   pip install tweepy twilio
   ```

3. Create a `credentials.py` file and populate it with your API credentials:
   ```python
   # credentials.py
   twitterCredentials = {
       "bearerToken": "YOUR_TWITTER_BEARER_TOKEN",
       "ACCESS_TOKEN": "YOUR_TWITTER_ACCESS_TOKEN",
       "ACCESS_TOKEN_SECRET": "YOUR_TWITTER_ACCESS_TOKEN_SECRET",
       "CONSUMER_KEY": "YOUR_TWITTER_CONSUMER_KEY",
       "CONSUMER_SECRET": "YOUR_TWITTER_CONSUMER_SECRET"
   }

   twilioCredentials = {
       "accountSID": "YOUR_TWILIO_ACCOUNT_SID",
       "authToken": "YOUR_TWILIO_AUTH_TOKEN",
       "twilioPhoneNum": "YOUR_TWILIO_PHONE_NUMBER"
   }
   ```

---

## Usage

1. Run the application:
   ```bash
   python main.py
   ```

2. Follow the prompts:
   - **Immediate Check**: Choose `Y` to fetch and display the current price of beans.
   - **Threshold Monitoring**: Choose `N` to monitor the price periodically. The app checks every 15 minutes until the price drops below the threshold.

---

## Example Interaction

### Case 1: Immediate Price Check
```plaintext
Do you want to check price now? (Y/N): Y
6.75
Hi Twitter, Current Price for beans is 6.75
Tweeted Successfully!
Message sent with SID: SMXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
```

### Case 2: Threshold Monitoring
```plaintext
Do you want to check price now? (Y/N): N
6.95
6.85
6.50
Buy Now, Price is less than 7
Hi Twitter, You can put an emergency order at 6.50. The price for beans is less than the threshold value.
Tweeted Successfully!
Message sent with SID: SMXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
```

---

## API Details

### Twitter Integration
Uses the `tweepy` library to interact with the Twitter API. The `sendTweet` function sends updates about bean prices to Twitter.

### SMS Notifications
Leverages the Twilio API via the `twilio` library. The `sendSMS` function sends alerts to the specified phone number when the price drops below the threshold.

---

## Error Handling

- **Invalid Input**: Prompts the user for valid input if an error occurs.
- **HTTP Errors**: Handles failed attempts to fetch the price.
- **File Missing**: Ensures `credentials.py` is correctly set up.

---

## Contributing

Feel free to contribute by submitting issues or pull requests. Improvements and bug fixes are welcome!

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
```

This `README.md` provides a clear overview of the project, setup instructions, and usage details. Let me know if you’d like further customization!
