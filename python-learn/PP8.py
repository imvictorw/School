#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 10/10/2016
#   Assignment: PP8

#The program is intended to recommend a pet based on the user's age and gender.

#       Age         Gender          Output
#       < 10           M              Dog
#       11-20          M              Monkey
#       > 21           M              Platypus
#       < 10           F              Octopus
#       11-20          F              Cat
#       > 21           F              Eagles

age = 0;
gender = None;
animal = None;
name = None;

while(True):
    inputGENDER = input("Please type in your Gender. Write in M or F for Male or Female respectively ");
    gender = inputGENDER;
    if(inputGENDER.lower() == "m" or inputGENDER.lower() == "f"):
        break;
    else:
        print("Please enter a correct Gender input");

while(True):
    try:
        inputAGE = int(input("Please type in your Age. Write in a number and not through words EG. 1 instead of one "));
        age = inputAGE;
        break;
    except ValueError:
        print("Please enter a correct Age input");

if(age < 10):
    if(gender == "m"):
        print("We recommend a Dog");
        animal = "Dog";
    elif(gender == "f"):
        print("We recommend a Monkey");
        animal = "Monkey";

if(age > 11 and age < 21):
    if(gender == "m"):
        print("We recommend a Platypus");
        animal = "Platypus";
    elif(gender == "f"):
        print("We recommend a Octopus");
        animal = "Octopus";

if(age > 21):
    if(gender == "m"):
        print("We recommend a Cat");
        animal = "Cat";
    elif(gender == "f"):
        print("We recommend a Eagle");
        animal = "Eagle";

while(True):
    animalName = input("Would you like to name your " + animal + "? Please write in yes or no as an input ");
    if(animalName.lower() == "yes"):
        name = input("What would you name the animal? ");
        print(name, "is a great name for your", animal);
        break;
    elif(animalName.lower() == "no"):
        print("Thank you for using our services ");
        break;
    else:
        print("Please enter a correct input");
