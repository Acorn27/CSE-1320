/*
Author: Mai Tran
Student ID: 1002092849 
Course: CSE 1320
Coding Asignment 2
*/

#include <stdio.h>
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

int main()
{

    int op1, op2;
    char operand[3];

    // display instruction
    printf("\nBitwise Calculator\n\n"
    "Enter two base 10 values with a bitwise operator to see the decimal result\n"
    "and the binary result. The format is\n\n"
    "FirstNumber BitwiseOperator SecondNumber\n\n"
    "For example, enter the expression\n\n"
    "2 & 3 \n\n"
    "This calculator can used with &, |, ^, << and >> \n\n"
    "Please note that the spaces between numbers and operator is essential\n"
    "and the two entered values must be between 0 and 255\n\n");
    printf("Enter expression ");
    scanf("%d %s%d", &op1, operand, &op2);

    // input validation
    while (op1 < 0 || op1 > 255 || op2 < 0 || op2 > 255)
    {
        printf("\nThe entered expression contains out of range values.\n" 
        "Please reenter the expression using values between 0 and 255.\n\n");
        scanf("%d %s%d", &op1, operand, &op2);
    }
   

    int base_10_result = -1;
    char binaryValue1[BITS+1];
    char binaryValue2[BITS+1];
    char binaryResult[BITS+1];
    char separator[] = "========";

    if (operand[0] == '&')
    {
        base_10_result = op1 & op2;

    }
    else if (operand[0] == '|')
    {
        base_10_result = op1 | op2;
    }
    else if (operand[0] == '^')
    {
        base_10_result = op1 ^ op2;
    }
    else if (operand[0] == '<' && operand[1] == '<')
    {
        base_10_result = op1 << op2;
        ConvertDecimalToBinary(op1, binaryValue1);
        ConvertDecimalToBinary(base_10_result, binaryResult);
        printf("\nIn base 10...\n\n%d %s %d = %d\n\n", op1, operand, op2, base_10_result );

        printf("\nIn %d-bit base 2...\n\n", BITS);
        printf("%s %s %d\n\n", binaryValue1, operand, op2);
        printf("%s", binaryResult);
        base_10_result = -1;

    }
    else if (operand[0] == '>' && operand[1] == '>')
    {
        base_10_result = op1 >> op2;
        ConvertDecimalToBinary(op1, binaryValue1);
        ConvertDecimalToBinary(base_10_result, binaryResult);
        printf("\nIn base 10...\n\n%d %s %d = %d\n\n", op1, operand, op2, base_10_result );

        printf("\nIn %d-bit base 2...\n\n", BITS);
        printf("%s %s %d\n\n", binaryValue1, operand, op2);
        printf("%s", binaryResult);
        base_10_result = -1;
    } 
    else
    {
        printf("\nOperator %s is not supported by this calculator\n\n", operand);
    }

    // result printing
    if (base_10_result != -1)
    {
        ConvertDecimalToBinary(op1, binaryValue1);
        ConvertDecimalToBinary(op2, binaryValue2);
        ConvertDecimalToBinary(base_10_result, binaryResult);
        printf("\nIn base 10...\n\n%d %s %d = %d\n\n", op1, operand, op2, base_10_result );
        printf("\nIn %d-bit base 2...\n\n", BITS);
        printf("%10s\n", binaryValue1);
        printf("%s\n", operand);
        printf("%10s\n", binaryValue2);
        printf("%10s\n", separator);
        printf("%10s\n", binaryResult);
    }

    return 0;
}