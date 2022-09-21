BITS = 8

def ConvertDecimalToBinary(decimal, binary):
    
    counter = 1
    binary[BITS - counter] = decimal & 1

    while (counter < BITS):
        counter += 1
        decimal = decimal >> 1
        binary[BITS - counter] = decimal & 1

def DisplayAOX(op1,op2,decimalFinal):
    binary = [None for _ in range(BITS)]
    print(f"In base 10...\n\n{op1} {operand} {op2} = {decimalFinal}")
    print(f"\nIn {BITS}-bit base 2...\n")
    ConvertDecimalToBinary(op1, binary)
    for i in binary:
        print(i, end = "")
    print(f"\n{operand}")
    ConvertDecimalToBinary(op2, binary)
    for i in binary:
        print(i, end = "")
    print("\n========")
    ConvertDecimalToBinary(decimalFinal, binary)
    for i in binary:
        print(i, end = "")

op1, operand, op2 = input("Enter expression: ").split()
op1 = int(op1)
op2 = int(op2)

while (op1 < 0 or op1 > 255 or op2 < 0 or op2 > 255):
    print("\nPlease note that the spaces between numbers and operator is essential \n"
        "and the two entered values must be between 0 and 255\n")
    op1, operand, op2 = input("Enter expression: ").split()
    op1 = int(op1)
    op2 = int(op2)

if (operand == "&"):
    decimalFinal = op1 & op2
    DisplayAOX(op1,op2,decimalFinal)
elif (operand == "|"):
    decimalFinal = op1 | op2
    DisplayAOX(op1,op2,decimalFinal)
elif (operand == " ^"):
    decimalFinal = op1 ^ op2
    DisplayAOX(op1,op2,decimalFinal)
elif (operand == "<<"):
    decimalFinal = op1 << op2
elif (operand == ">>"):
    decimalFinal = op1 >> op2
else:
    print(f"Operator {operand} is not supported by this calculator\n");
