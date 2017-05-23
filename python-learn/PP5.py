#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 3/10/2016
#   Assignment: PP5

def drawSquare(number): #Creates a square to the size of the input given by the user

    victor.forward(number)
    victor.right(90)
    victor.forward(number)
    victor.right(90)
    victor.forward(number)
    victor.right(90)
    victor.forward(number)
    victor.right(90)

#or I could make a for loop
#  for squareLoop in range(0, 4):
#       victor.forward(number)
#       victor.right(90)

import turtle

victor = turtle.Turtle() #Initializing the turtle package

inputNum = int(input("Enter the amount of squares you want")) #Ask for input to user




for noSquares in range(1, inputNum+1): #Uses the input and uses the drawSquare function to creates squares
    drawSquare(noSquares * 10)
