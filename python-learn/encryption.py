#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 7/11/2016
#   Assignment: PP11

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
        while True:
            crypt = input("Please enter a 3 letter word use to encrypt ")
            if isinstance(crypt, str) and len(crypt) == 3:
                break;


        cryptCounter = 0;
        for i in message:

            print(i)
            print(ord(i))
            new_character = ord(i) + 5
            print(new_character)
            new_character = chr(new_character)
            print(new_character)
            try:
                new_message = new_message + new_character + crypt[cryptCounter]
            except IndexError:
                new_message = new_message + new_character + crypt[0]
                cryptCounter = 0;

            cryptCounter+=1;
    elif option == "2":
        for i in range(0, len(message), 2):
            print(message[i])
            new_character = ord(message[i]) - 5
            new_character = chr(new_character)
            new_message = new_message + new_character
    return new_message


# main program
option = getOption()
message = getMessage()
new_message = mixMeUp(message,option)
print("Your new string is " + new_message)
