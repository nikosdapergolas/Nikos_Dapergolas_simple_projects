import string
from random import randrange

cyphertext = input("please enter the encrypted password: ")

cypherKey = cyphertext[-5]
cypherKey += cyphertext[-4]
cypherKey += cyphertext[-3]
cypherKey += cyphertext[-2]
cypherKey += cyphertext[-1]

suffixKey = 12345

loopCounter = 1
for i in cypherKey:
    if loopCounter == 1:
        x = ord(i)
        x -= suffixKey
        finalCypherKey = chr(x)
        loopCounter += 1
    else:
        x = ord(i)
        x -= suffixKey
        finalCypherKey += chr(x)
        loopCounter += 1

#removing the sufix from cyphertext
for i in cypherKey:
    cyphertext = cyphertext[:-1]

# remaking the suffix an int (cause it was a string by now)
key = int(finalCypherKey)

# decoding my password
loopCounter = 1
for i in cyphertext:
    if loopCounter == 1:
        x = ord(i)
        x -= key
        password = chr(x)
        print(i, " = ", chr(x))
        loopCounter += 1
    else:
        x = ord(i)
        x -= key
        password += chr(x)
        print(i, " = ", chr(x))
        loopCounter += 1

print("after decrypting it, your password was: ",password)
