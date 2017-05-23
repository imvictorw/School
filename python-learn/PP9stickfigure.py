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

victor = turtle.Turtle()

drawStick()
