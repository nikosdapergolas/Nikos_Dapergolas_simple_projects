with open('words.txt') as f:
    for line in f:
        for word in line.split():
            if len(word) < 4:
                print(word)
            else:
                print(word[1:] + "ay")
