cardNumber = int(input("Enter a card number that you want to check its validity: "))
isValid = True
while isValid:
    if len(str(cardNumber)) != 16:
        print("invalid card number!! Try again and try not to use spaces between numbers")
        cardNumber = int(input("Enter a card number that you want to check its validity: "))
    else:
        isValid = False
x = 10
y = 1
sumOfCardDigits = 0
for i in range(16):
    if i % 2 == 0:
        sumOfCardDigits += cardNumber % x//y
    else:
        if (cardNumber % x//y) * 2 >= 10:
            z = cardNumber % x//y * 2
            sumOfCardDigits += z % 10 + z//10
        else:
            sumOfCardDigits += cardNumber % x // y * 2
    x *= 10
    y *= 10
if sumOfCardDigits % 10 == 0:
    print("valid card number")
else:
    print("invalid card number")

# -------------------------------------------------------------------------
# -------------------------------------------------------------------------
# Γράψτε ένα πρόγραμμα σε Python το οποίο
# παίρνει σαν είσοδο από το χρήστη έναν αριθμό πιστοτικής κάρτας (16 ψηφία)
# και χρησιμοποιεί τον αλγόριθμο του Luhn για να επιβεβαιώσει τον τύπο της.
# -------------------------------------------------------------------------
# -------------------------------------------------------------------------