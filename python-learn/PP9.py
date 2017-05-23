#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 10/10/2016
#   Assignment: PP9

def checkInput(input, question):
    if(question == 1):
        if(input == 1 or input == 2):
            return True;
        else:
            return False;
    elif(question == 2 or question == 3):
        if(input == 1 or input == 2 or input == 3):
            return True;
        else:
            return False;

def updateVariable(points, question, selection, prev):


    if(question == 1):
        if(selection == 1):
            points += 10;
            return points;

    elif(question == 2):
        if(selection == 1):
            points += 20;
            return points;

        elif(selection == 3):
            points += 10;
            return points;

    elif(question == 3):
        if(prev == 1):
            if(selection == 1):
                points += 10;
                return points;

        elif(prev == 3):
            if(selection == 1):
                points += 10;
                return points;
    else:
        return points;

def drawStick():
    victor.circle(50) #head

    xCoord = victor.xcor() #Gets the initial position of x coordinate
    yCoord = victor.ycor() #Gets the initial position of y coordinate
    xCoord = xCoord + 50

    victor.right(90) #Body
    victor.forward(50)

    victor.right(90) #Arm
    victor.forward(50)

    victor.forward(30) #book
    victor.right(90)
    victor.forward(30)
    victor.right(90)
    victor.forward(30)
    victor.right(90)
    victor.forward(30)
    victor.right(90)
    victor.forward(15)
    victor.right(90)
    victor.forward(30)
    victor.right(90)
    victor.forward(15)
    victor.right(90)
    victor.forward(30)

    victor.left(90) #going back to body
    victor.forward(50)

    victor.right(90) #legs
    victor.forward(40)
    victor.right(90)
    victor.forward(35)
    victor.left(90)
    victor.forward(50)
    victor.right(90)
    victor.forward(20)

    victor.penup()
    victor.setposition(xCoord ,yCoord)
    victor.pendown()

    victor.left(90)
    victor.forward(120)
    victor.right(90)
    victor.forward(60)
    victor.left(90)
    victor.forward(30) #chair leg
    victor.left(180)
    victor.forward(30)
    victor.right(90)
    victor.forward(10)
    victor.right(90)
    victor.forward(30)
    victor.right(180)
    victor.forward(30)
    victor.right(90)
    victor.forward(50)
    victor.right(90)
    victor.forward(30)

import turtle

question = 1;
points = 0;
previnputChoice = 0;
inputNAME = input("Please write down your name ");
print("Hello ", inputNAME, "Welcome to IT102");

print("Enter:\n 1- To Study IT102 \n 2- To Fall Asleep");

while(True):
    try:
        inputChoice = int(input("Please enter a selection "));
        print()
        if(checkInput(inputChoice, question) == True):
            break;
        else:
            print("Please enter a correct selection. ");
    except ValueError:
        print("Please enter a correct selection. ");


if(inputChoice == 1 and checkInput(inputChoice, question)):
    print("10 points earned.\n Now to the next question.");
    points = updateVariable(points, question, inputChoice, previnputChoice);
    print("Next Lesson:\n 1- Read Lesson \n 2- To Fall Asleep \n 3- Do Lab First");

    question += 1;

    while(True):
        try:
            inputChoice = int(input("Please enter a selection "));
            print()
            if(checkInput(inputChoice, question) == True):
                break;
            else:
                print("Please enter a correct selection. ");
        except ValueError:
            print("Please enter a correct selection. ");

    if(inputChoice == 1 and checkInput(inputChoice, question)): #Read Lesson
        points = updateVariable(points, question, inputChoice, previnputChoice);
        print("20 points earned. You have obtained ", points, " points" "\n Now to the next question.");
        print("Next Lesson:\n 1- Do Lab First \n 2- To Fall Asleep");
        previnputChoice = inputChoice;
        question += 1;

        while(True):
            try:
                inputChoice = int(input("Please enter a selection "));
                print()
                if(checkInput(inputChoice, question) == True):
                    break;
                else:
                    print("Please enter a correct selection. ");
            except ValueError:
                print("Please enter a correct selection. ");


        if(inputChoice == 1 and checkInput(inputChoice, question)): #Read Lesson
            points = updateVariable(points, question, inputChoice, previnputChoice);
            print("10 points earned. You have obtained ", points, " points");
        elif(inputChoice == 2 and checkInput(inputChoice, question)): #Fall Asleep
            print("Game has ended.");
        else:
            print("Please enter a correct selection. EG. 1 or 2 ");
    elif(inputChoice == 2 and checkInput(inputChoice, question)): #Fall Asleep
        print("Game has ended.");
        print("You have obtained ", points, " points");
    elif(inputChoice == 3 and checkInput(inputChoice, question)): #Do Lab First
        points = updateVariable(points, question, inputChoice, previnputChoice);
        print("10 points earned. You have obtained ", points, " points" "\n Now to the next question.");
        print("Next Lesson:\n 1- Read Lesson \n 2- To Fall Asleep");
        previnputChoice = inputChoice;
        question += 1;

        while(True):
            try:
                inputChoice = int(input("Please enter a selection "));
                print()
                if(checkInput(inputChoice, question) == True):
                    break;
                else:
                    print("Please enter a correct selection. ");
            except ValueError:
                print("Please enter a correct selection. ");

        if(inputChoice == 1 and checkInput(inputChoice, question)): #Read Lesson
            points = updateVariable(points, question, inputChoice, previnputChoice);
            print("10 points earned. You have obtained ", points, " points");
        elif(inputChoice == 2 and checkInput(inputChoice, question)): #Fall Asleep
            print("Game has ended.");
            print("You have obtained", points, "points");

        else:
            print("Please enter a correct selection. EG. 1 or 2 ");
    else:
        print("Please enter a correct selection. EG. 1 or 2 or 3");

elif(inputChoice == 2 and checkInput(inputChoice, question)):
    print("You have obtained ", points, " points");
else:
    print("Please enter a correct selection. EG. 1 or 2 ");

print("Game has ended, Thank you for playing this game", inputNAME);
print("You have scored a total of", points,"points");

victor = turtle.Turtle()
drawStick() #reading book on chair
