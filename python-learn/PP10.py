#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 24/10/2016
#   Assignment: PP10

import random

def getINPUTS(wordList, counter):
    while(True):

        if(counter+1 == 1):
            counterWORD = "1st"
        elif(counter+1 == 2):
            counterWORD = "2nd"
        elif(counter+1 == 3):
            counterWORD = "3rd"
        else:
            counterWORD = str(counter+1) + "nd"

        if(counter == 5):
            break;

        wordINPUT = input("Please enter 5 words. This is your " + counterWORD + " word ");
        if(wordINPUT.isalpha() == True):
            word.append(wordINPUT)
            counter+=1
        else:
            print("Please enter a real word");

def mixMeUp(mixWORD):
    return ''.join(random.sample(mixWORD,len(mixWORD)));

def GuessME(beforeList, afterList):
    guessINPUT = input("Guess what the anagram word is " + afterList + " ");

    if(beforeList == guessINPUT):
        print("Correct")
        return True
    else:
        print("Incorrect")
        return False

word = [];
wordBEFORE = []
counter = 0;
GMList = [];
GMCounter = 0;

getINPUTS(word, counter);
wordBEFORE = list(word);
for i in range(4):
    word[i] = mixMeUp(word[i])

while GMCounter < 5:
    randomINT = random.randint(0, 4)
    if (randomINT not in GMList):
        if(GuessME(wordBEFORE[randomINT], word[randomINT]) == True):
            GMList.append(randomINT);
            GMCounter+=1;

print("Nice work buddy. Thanks for playing");
