# IT102
# P.Turylo
# encryption.py

def getOption( ):
    print("Which do you want to do?")
    print("1 -Encrypt")
    print("2 -Decrypt")
    while True:
       option = input("Please enter option: ")
       if option == "1" or option == "2":
           return option

def getMessage( ):
    message = input("Please enter message: ")
    return message

def mixMeUp(message, option):
    new_message = ""
    if option == "1":
        for i in message:
            new_character = ord(i) + 5
            new_character = chr(new_character)
            new_message = new_message + new_character
    elif option == "2":
        for i in message:
            new_character = ord(i) - 5
            new_character = chr(new_character)
            new_message = new_message + new_character
    return new_message
            

# main program
while True:
    option = getOption()
    message = getMessage()
    new_message = mixMeUp(message,option)
    print("Your new string is " + new_message)
    again = input("Do you want to play again. Write yes if you do ")
    if again != "yes":
        break;


    
