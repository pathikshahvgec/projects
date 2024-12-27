# Point-of-Sale (POS) Application

A Python application that simulates a Point-of-Sale (POS) system for processing orders, applying discounts, and saving transactions. This system includes features for promotional discounts, Starbuzz Card discounts, and robust transaction logging.

---

## Features
- **Menu Management**: Displays a menu of items with corresponding prices.
- **Discounts**:
  - General promotions (10% discount by default).
  - Additional 5% discount for Starbuzz Card holders.
- **Transaction Logging**: Saves transactions to a file in a structured format.
- **Error Handling**: Graceful handling of input errors and file-related issues.

---

## Prerequisites
- Python 3.6 or later
- A writable file named `transaction.txt` in the same directory for saving transaction logs.

---

## File Structure
- **coffeeBarMenu.py**: The main script for running the application.
- **promotion.py**: Contains discount logic for general promotions.
- **starbuzz.py**: Includes discount logic for Starbuzz Card holders.
- **transactionAPI.py**: Handles transaction saving and file operations.

---

## Setup
1. Clone or download this repository.
2. Ensure the `transaction.txt` file exists in the same directory as the scripts. If it doesn’t, the program will create it on the first transaction.

---

## Usage

1. Run the application:
   ```bash
   python coffeeBarMenu.py
   ```
2. Follow the on-screen prompts:
   - Select an item from the menu.
   - Enter your credit card number.
   - Indicate if you have a Starbuzz Card for additional discounts.
3. The application will calculate the total price, apply discounts, and save the transaction to the file.

### Example Interaction
```plaintext
1. DONUT
2. LATTE
3. FILTER
4. MUFFIN
5. Quit
Please select a menu option number from the options above: 2
Enter your credit card number: 1234567890123456
Do you also have a Starbuzz Card? (Y/N): Y
Transaction saved for LATTE at $1.80.
```

---

## Discount Logic

### Promotion Discounts
The `promotion.discount` function applies a default 10% discount unless specified otherwise.

### Starbuzz Card Discounts
The `starbuzz.discount` function applies an additional 5% discount for Starbuzz Card holders.

---

## Transaction Logging
Transactions are saved in the `transaction.txt` file with the following format:
```
<creditCardNum><priceInCents><description>
```

Example:
```
12345678901234560200LATTE
```

---

## Error Handling
- **Invalid Menu Selection**: Prompts the user to select a valid option.
- **File Not Found**: Alerts the user if the transaction file is missing.
- **Negative Prices or Invalid Discount Rates**: Raises exceptions to prevent invalid operations.

---

## Contributing
Contributions are welcome! Please open a pull request or file an issue to suggest improvements.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for more information.
```

Let me know if you'd like any adjustments!
