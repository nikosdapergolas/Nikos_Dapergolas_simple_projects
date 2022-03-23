import datetime

def find_days_of_year(days,month,year,leapYears):
    totalDays = year * 365 + leapYears
    totalDays += days
    if month == 1:
        totalDays += 0
    elif month == 2:
        totalDays += 31
    elif month == 3:
        totalDays += 59
    elif month == 4:
        totalDays += 90
    elif month == 5:
        totalDays += 120
    elif month == 6:
        totalDays += 151
    elif month == 7:
        totalDays += 181
    elif month == 8:
        totalDays += 212
    elif month == 9:
        totalDays += 243
    elif month == 10:
        totalDays += 273
    elif month == 11:
        totalDays += 304
    elif month == 12:
        totalDays += 334
    return totalDays

now = datetime.datetime.now()
today = str(now.day)
if now.month <=9:
    today += str(0) +str(now.month)
else:
    today += str(now.month)
today += str(now.year)
print("todays date is: " + today)
print("write the date without using spaces or the \"/\" symbol or the \"-\" symbol. for example if you want 10/8/2011 then write 10082011")
chosenDate = int(input("Enter a random date only by using numbers: "))
correctDate = True
while correctDate:
    dateLen = 0
    copyOfChosenDay = chosenDate
    if (chosenDate // 1000000) >=1 and (chosenDate // 1000000) <=9:
        dateLen+=1
    while copyOfChosenDay > 0:
        copyOfChosenDay = copyOfChosenDay // 10
        dateLen += 1

    if dateLen != 8:
        print("invalid date type, try again!")
        chosenDate = int(input("Enter a random date only by using numbers: "))
    elif (chosenDate // 10000 % 100) <= 0 or (chosenDate // 10000 % 100) >= 13:
        print("invalid month type, try again!")
        chosenDate = int(input("Enter a random date only by using numbers: "))
    elif (chosenDate // 1000000) <=0 or (chosenDate // 1000000) >=32:
        print("invalid day type, try again!")
        chosenDate = int(input("Enter a random date only by using numbers: "))
    else:
        correctDate = False


year = chosenDate % 10000
print("year of the random date: " + str(year))
leapYears = year//4
daysOfRandomDate = (chosenDate // 1000000)
print("this year that you have chosen had " + str(daysOfRandomDate) + " days")
month = chosenDate // 10000 % 100
print("and it also had " + str(month) + " months")
RandomDateInDays = find_days_of_year(daysOfRandomDate, month, year, leapYears)
# from now on we are talking about the current date
leapYears = now.year//4
currentDateInDays = find_days_of_year(now.day, now.month, now.year, leapYears)
difInDays = abs(int(RandomDateInDays) - int(currentDateInDays))
print("the current day and the random date are only " + str(difInDays) + " days appart")
difInMinutes=difInDays*24
print("the current day and the random date are only " + str(difInMinutes) + " hours appart")
difInSeconds=difInMinutes*60
print("the current day and the random date are only " + str(difInSeconds) + " seconds appart")
if month == 1:
    daysOfTheMonth = 31
elif month == 2:
    if year % 4 == 0:
        daysOfTheMonth = 28
    else:
        daysOfTheMonth = 29
elif month == 3:
    daysOfTheMonth = 31
elif month == 4:
    daysOfTheMonth = 30
elif month == 5:
    daysOfTheMonth = 31
elif month == 6:
    daysOfTheMonth = 30
elif month == 7:
    daysOfTheMonth = 31
elif month == 8:
    daysOfTheMonth = 31
elif month == 9:
    daysOfTheMonth = 30
elif month == 10:
    daysOfTheMonth = 31
elif month == 11:
    daysOfTheMonth = 30
elif month == 12:
    daysOfTheMonth = 31

print("also the month of the random date that you have chosen,has: " + str(daysOfTheMonth) + " days")





# -----------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------
# Γράψτε ένα πρόγραμμα σε Python το οποίο
# παίρνει μια ημερομηνία σε μορφή ΗΗ/ΜΜ/ΕΕΕΕ και εμφανίζει:
# πόσες μέρες/ώρες/δευτερόλεπτα απέχει αυτή από την τρέχουσα ημερομηνία του υπολογιστή,
# καθώς και πόσες ημέρες έχει ο μήνας εκείνης της ημερομηνίας.
# -----------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------
