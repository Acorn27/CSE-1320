#include <stdio.h>

int main()
{
    int varA = 10;

    // need ampersand becuase this is a normal var
    int* varAPtr = &varA;
    int** varAPtrPtr = &varAPtr;

    printf("Adress of varAPtr is %p\n", varAPtr);
    printf("Adress of varAPtrPtr  is %p\n", varAPtrPtr);

    printf("VarA = %d\n", varA);
    printf("*VarAPtr = %d\n", *varAPtr);
    printf("**VarAPtrPtr = %d\n", **varAPtrPtr);

    // other demo
    char* arrayPtr[] = {"The", "quick", "fox", "jump", ""};
    char** PtrPtr = arrayPtr;

    printf("Adress of PtrPtr is %p\n", PtrPtr);
    printf("Adress of Array  is %p\n", arrayPtr);



    for (int i = 0; i < 5; i++)
    {
        // print by pointer
        printf("PtrPtr + %d = %s\n", i, *(PtrPtr+i));
        // other way to print
        // we have to print arrayPtr[i], instead of *array[i]
        // c automatically evaluate to value just by using array[i] subscript
        printf("PtrPtr + %d = %s\n", i, arrayPtr[i]);

        // ???
        printf("PtrPtr + %d = %c\n", i, *(arrayPtr[i]));

        // only variable name reture value inside that var
        // * return to deeper level
        printf("Address is %p\n", PtrPtr+i);

    }


} 