import string
from random import randrange

# ord("a") = 97
# ord("A") = 65
# ord("0") = 48
# ord("1") = 49
# ord("9") = 57
#randrange(2) = 0 or 1
#randrange(2,5) = 2 or 3 or 4


# plaintext = """abcd1234"""
plaintext = input("please enter a password: ")

print("the password you entered is: ", plaintext)

key = randrange(10000,60000)
suffixKey = 12345 #always the last 5 digits

# encoding the password with a random key
loopCounter = 1
for i in plaintext:
    if loopCounter == 1:
        x = ord(i)
        x += key
        cyphertext = chr(x)
        loopCounter += 1
    else:
        x = ord(i)
        x += key
        cyphertext = cyphertext + chr(x)
        loopCounter += 1

#adding the suffix to the cyphertext
key = str(key)
for i in key:
    x = ord(i)
    x += suffixKey
    cyphertext = cyphertext + chr(x)

print("encrypring your password...")
print(cyphertext)
