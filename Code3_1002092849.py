# import random
from copyreg import pickle
from ctypes import sizeof
import random

#import numpy for 2d array
import numpy as np

ROW = 5
COLUMN = 5

def printArray(bingo_array):

    print("    B       I       N       G       O")
    print("-----------------------------------------")
    for row in range(0,ROW):
        for col in range(0, COLUMN):

            # ternary operator 
            print(f"|{bingo_array[row][col] if bingo_array[row][col] != 0 else 'X':>4}   ", end = '')
        print("|")
        print("-----------------------------------------")

# get 'B', 'I', 'N', 'G', 'O'
def getPrecedence(number):

    if (number <=  15):
        precedence = 'B'
    elif (number <= 30):
        precedence = 'I'
    elif (number <= 45):
        precedence = 'N'
    elif (number <= 60):
        precedence = 'G'
    elif (number <= 75):
        precedence = 'O'
    
    return precedence; 

#check if number is from array
def is_from_array(bingoArray, number):
    
    is_from_array = False
    for row in range(ROW):
        for col in range(COLUMN):
            if (number == bingoArray[row][col]):
                is_from_array = True
                bingo_array[row][col] = 0
    
    return is_from_array

#check if array have the row with same value
#shape return shape of array
def row_win(bingo_array):
    for i in range(bingo_array.shape[0]):
        if np.all(bingo_array[i] == 0):
            return True
    return False

# check column win
def col_win(bingo_array):
    tranpose = np.transpose(bingo_array)
    if row_win(tranpose):
        return True
    else:
        return False

def main_diagno_win(bingo_array):

    is_win = True
    for i in range(5):
        if (bingo_array[i][i] != 0):
            is_win = False

def second_diagno_win(bingo_array):
    is_win = True
    for i in range(bingo_array.shape[0]):
        if bingo_array[i,bingo_array.shape[0] -i] != 0:
            is_win = False

    return is_win
    




# main function
bingo_array = []

# create an 2d bingo array
for i in range (COLUMN):
    
    # create a list of random number in approriate range
    temp_array = list(range(1 + 15*i, 15*(i+1) + 1))

    #shuffle to create a random list
    random.shuffle(temp_array)

    # only get 5 elemt in list and add to final list
    # slide [0:5] mean getting element from 0 to 5-4, or 0 to 4 (5 element)
    bingo_array += temp_array[0: 5]

# convert 1D array to 2D array
bingo_array = np.reshape(bingo_array, (5,5))

# tranpose or diagonal flip the array
bingo_array = np.transpose(bingo_array)

# set middle value to 0
bingo_array[2][2] = 0

printArray(bingo_array)

#create a list of number to pick in range 1 to 75
pickNumber = list(range(1, 76))

random.shuffle(pickNumber)


counter = 0
is_win = 0

while (counter < 75 and not(is_win)):

    print(f"\nThe next number is {getPrecedence(pickNumber[counter])}{pickNumber[counter]}\n")
    choice = input("Do you have it ? (Y/N)")

    if (is_from_array(bingo_array, pickNumber[counter])):
        printArray(bingo_array)
        

    else:
        print(f"\nThat value is not on your BINGO card - are you trying to cheat??\n");
        printArray(bingo_array)
    
    counter += 1
 
