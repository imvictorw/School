#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 10/10/2016
#   Assignment: PP7

points = 0;
inputNAME = input("Please write down your name ");
print("Hello ", inputNAME, "Welcome to IT102");

print("Enter:\n 1- To Study IT102 \n 2- To Fall Asleep");
inputChoice = int(input("Please enter a selection "));

if(inputChoice == 1):
    print("10 points earned.\n Now to the next question.");
    points += 10;
    print("Next Lesson:\n 1- Read Lesson \n 2- To Fall Asleep \n 3- Do Lab First");
    inputChoice = int(input("Please enter a selection "));

    if(inputChoice == 1): #Read Lesson
        points += 20;
        print("20 points earned. You have obtained ", points, " points" "\n Now to the next question.");
        print("Next Lesson:\n 1- Do Lab First \n 2- To Fall Asleep");
        inputChoice = int(input("Please enter a selection "));

        if(inputChoice == 1): #Read Lesson
            points += 10;
            print("10 points earned. You have obtained ", points, " points");
        elif(inputChoice == 2): #Fall Asleep
            print("Game has ended.");
            print("You have obtained ", points, " points");
        else:
            print("Please enter a correct selection. EG. 1 or 2 ");
    elif(inputChoice == 2): #Fall Asleep
        print("Game has ended.");
        print("You have obtained ", points, " points");
    elif(inputChoice == 3): #Do Lab First
        points += 10;
        print("10 points earned. You have obtained ", points, " points" "\n Now to the next question.");
        print("You have obtained ", points, " points");
        print("Next Lesson:\n 1- Read Lesson \n 2- To Fall Asleep");
        inputChoice = int(input("Please enter a selection "));

        if(inputChoice == 1): #Read Lesson
            points += 10;
            print("10 points earned. You have obtained ", points, " points");
        elif(inputChoice == 2): #Fall Asleep
            print("Game has ended.");
            print("You have obtained", points, "points");

        else:
            print("Please enter a correct selection. EG. 1 or 2 ");
    else:
        print("Please enter a correct selection. EG. 1 or 2 or 3");

elif(inputChoice == 2):
    print("You have obtained ", points, " points");
else:
    print("Please enter a correct selection. EG. 1 or 2 ");

print("Game has ended, Thank you for playing this game", inputNAME);
print("You have scored a total of", points,"points");
