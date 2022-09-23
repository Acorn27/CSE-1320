
BITS = 8

def printArray(a):
    s = ""
    for i in a:
        s += str(i)
    return s
    

def ConvertDecimalToBinary(decimal, binary):
    
    counter = 1
    binary[BITS - counter] = decimal & 1

    while (counter < BITS):
        counter += 1
        decimal = decimal >> 1
        binary[BITS - counter] = decimal & 1

def DisplayAOX(op1,op2,decimalFinal):
    binary = [None for _ in range(BITS)]
    print(f"\nIn base 10...\n\n{op1} {operand} {op2} = {decimalFinal}")
    print(f"\nIn {BITS}-bit base 2...\n")
    ConvertDecimalToBinary(op1, binary)
    op1string = printArray(binary)
    ConvertDecimalToBinary(op2, binary)
    op2string = printArray(binary)
    Separator = "========"
    ConvertDecimalToBinary(decimalFinal, binary)
    finalstring = printArray(binary)
    print(f"{op1string: >10}\n{operand}\n{op2string: >10}\n{Separator: >10}\n{finalstring: >10}\n")


print("\nBitwise Calculator\n\n"
    "Enter two base 10 values with a bitwise operator to see the decimal result\n"
    "and the binary result. The format is\n\n"
    "FirstNumber BitwiseOperator SecondNumber\n\n"
    "For example, enter the expression\n\n"
    "2 & 3 \n\n"
    "This calculator can used with &, |, ^, << and >> \n\n"
    "Please note that the spaces between numbers and operator is essential\n"
    "and the two entered values must be between 0 and 255\n");
op1, operand, op2 = input("Enter expression: ").split()
op1 = int(op1)
op2 = int(op2)

while (op1 < 0 or op1 > 255 or op2 < 0 or op2 > 255):
    print("\nThe entered expression contains out of range values."
        "\nPlease reenter the expression using values between 0 and 255.\n")
    op1, operand, op2 = input("").split()
    op1 = int(op1)
    op2 = int(op2)

if (operand == "&"):
    decimalFinal = op1 & op2
    DisplayAOX(op1,op2,decimalFinal)
elif (operand == "|"):
    decimalFinal = op1 | op2
    DisplayAOX(op1,op2,decimalFinal)
elif (operand == "^"):
    decimalFinal = op1 ^ op2
    DisplayAOX(op1,op2,decimalFinal)
elif (operand == "<<"):
    decimalFinal = op1 << op2
    print(f"\nIn base 10...\n")
    print(f"{op1} {operand} {op2} = {decimalFinal}\n")
    print(f"\nIn {BITS}-bit base 2...\n")
    binary  = [None for _ in range(BITS)]
    ConvertDecimalToBinary(op1,binary)
    op1string = printArray(binary)
    ConvertDecimalToBinary(decimalFinal, binary)
    op2string = printArray(binary)
    print(f"{op1string} {operand} {op2}\n\n{op2string}")
elif (operand == ">>"):
    decimalFinal = op1 >> op2
    print(f"\nIn base 10...\n")
    print(f"{op1} {operand} {op2} = {decimalFinal}\n")
    print(f"\nIn {BITS}-bit base 2...\n")
    binary  = [None for _ in range(BITS)]
    ConvertDecimalToBinary(op1,binary)
    op1string = printArray(binary)
    ConvertDecimalToBinary(decimalFinal, binary)
    op2string = printArray(binary)
    print(f"{op1string} {operand} {op2}\n\n{op2string}")
else:
    print(f"\nOperator {operand} is not supported by this calculator\n");
