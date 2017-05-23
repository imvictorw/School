#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 21/11/2016
#   Assignment: PP12
import sys

def checkEmpty(file):
    pos = file.tell()
    if len(file.readline()) == 0: #Checks if file is empty and is in correct format
        print("Please provide a correctly format question file")
        sys.exit()

    file.seek(pos)
    return

def question(file1):
    noQuestion = 0;
    correct = 0;

    for word in file1.read().split('\n'):
        if(len(word)<= 0):
            break;

        noQuestion += 1;
        sentence = word.split(";");
        for i in range(0, 3):
            question = input(sentence[1] + " ");
            if(question.lower() == sentence[0].lower()):
                print("Correct");
                correct += 1;
                break;


    stat = (correct/noQuestion)*100;
    return stat;


try:
    f1 = open('questions.txt', 'r')
except FileNotFoundError:
    print("Please provide a correct question file")
    sys.exit()

checkEmpty(f1);
f2 = open('score.txt', 'w')

name = input("Enter your name ");
result = int(question(f1));
newsentence = name + " " + str(result) + "%";
f2.write(newsentence);


f1.close();
f2.close();
