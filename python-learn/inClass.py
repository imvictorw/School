f1 = open('data.txt', 'r')
f2 = open('newScore.txt', 'a')
counter = 1
sentence = ""
someuselesslist = []
average = 0

for word in f1.read().split():
    if(counter == 4):
        average = average / 3
        sentence = sentence + " " + str(int(average))
        f2.write(sentence + " ")

        average = 0
        sentence = ""
        counter = 1
    elif(counter == 1):
        sentence = sentence + word
        counter += 1
    else:
        average += average + int(word)
        counter+=1

    print(word);

f1.close()
f2.close()
