#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 14/11/2016
#   Assignment: PP11

import os
import sys

counter = 1;

try:
    f1 = open('payrollData.txt', 'r')
except FileNotFoundError:
    print("Please provide a correct payrollData file")
    sys.exit()

f2 = open('newPayrollData.txt', 'w')

pos = f1.tell()
if not len(f1.readline().split()) == 3: #Checks if file is empty and is in correct format
    print("Please provide a correctly format payrollData")

f1.seek(pos)

for word in f1.read().split():
    if(counter % 3 == 0):
        try:
            word = int(word) + 20000
        except ValueError:
            print("Please provide an integer for salary")
            sys.exit()

        word = str(word);
        counter = 1;
        f2.write(word + "\n")
    else:
        counter += 1
        f2.write(word.upper() + " ")




f1.close()
f2.close()
