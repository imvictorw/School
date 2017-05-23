#   Course: IT102 Section C
#   Authors: chessTile Woo
#   Date: 4/10/2016
#   Assignment: PP6

import turtle

chessTile = turtle.Turtle();

def createSquare(): #Creates square
    chessTile.forward(45)
    chessTile.right(90)
    chessTile.forward(45)
    chessTile.right(90)
    chessTile.forward(45)
    chessTile.right(90)
    chessTile.forward(45)
    chessTile.right(90)

def createEvenRow():

    xCoord = chessTile.xcor() #Gets the initial position of x coordinate
    yCoord = chessTile.ycor() #Gets the initial position of y coordinate

    for noTile in range(0,8):

        if(noTile % 2 != 0): #All odd tiles are made black
            chessTile.begin_fill() #Fills in tile
            chessTile.color("black")
            createSquare()
            chessTile.end_fill()
            moveRight = chessTile.xcor() #Moves the pointer x amount to the right
            moveRight += 45
            chessTile.setposition(moveRight,yCoord)
        else:
            createSquare()
            moveRight = chessTile.xcor()
            moveRight += 45
            chessTile.setposition(moveRight,yCoord)

    chessTile.penup()
    yCoord -= 45 #Moves down the position of the y position
    chessTile.setposition(xCoord,yCoord)
    chessTile.pendown()



def createOddRow():

        xCoord = chessTile.xcor() #Gets the initial position of x coordinate
        yCoord = chessTile.ycor() #Gets the initial position of y coordinate

        for noTile in range(0,8):

            if(noTile % 2 == 0): #All even tiles are made black
                chessTile.begin_fill()
                chessTile.color("black")
                createSquare()
                chessTile.end_fill()
                moveRight = chessTile.xcor()
                moveRight += 45
                chessTile.setposition(moveRight,yCoord)
            else:
                createSquare()
                moveRight = chessTile.xcor()
                moveRight += 45
                chessTile.setposition(moveRight,yCoord)

        chessTile.penup()
        yCoord -= 45 #Moves down the position of the y position
        chessTile.setposition(xCoord,yCoord)
        chessTile.pendown()


for i in range(0,4): #Keeps looping even and odd rows until you have 8 rows
    createEvenRow()
    createOddRow()
