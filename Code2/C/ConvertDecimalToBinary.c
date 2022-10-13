// include the file name, not the defined header file name?
#include "ConvertDecimalToBinary.h"
#define BITS 8

void ConvertDecimalToBinary(int decimal, char binary[BITS + 1])
{
    // decimal array
    int decimalArray[BITS];

    // counter to manipulate array index
    int counter = 1;

    // get first index
    decimalArray[BITS - counter] = decimal & 1;

    // loop through the remaning bit
    while (counter < BITS) 
    {   
        counter++;
        decimal = decimal >> 1; 
        decimalArray[BITS -counter] = decimal & 1;
    }
    
    // convert decimal array into char array
    for (int i = 0; i < BITS; i++) 
    {
        binary[i] = decimalArray[i]+'0';
    }

    // mark the end of char array
    binary[BITS] = '\0';
}
