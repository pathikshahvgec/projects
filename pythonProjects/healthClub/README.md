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
- **main.py**: The main script for running the application.
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
   python main.py
