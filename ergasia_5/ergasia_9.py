num = int(input("Enter a Number: "))
hold = num
while hold > 9:
    num = num * 3
    num += 1
    result = 0
    while num > 0:
        rem = num % 10
        result = result + rem
        num = int(num//10)
    print("Sum of all digits of", hold, "is: ", result)
    hold = result
    num = result