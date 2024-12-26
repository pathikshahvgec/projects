def discount(price, rate=0.10):
    if(price < 0):
        raise ValueError("Price cannot be negative.")
    if not (0 <= rate <= 1):
        raise ValueError("Rate must be between 0 and 1.")
    return (1 - rate) * price
