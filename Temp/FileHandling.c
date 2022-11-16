#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char readFileName[100] = {};
    char writeFileName[100] = {};
    char rwFileName[100] = {};
    char buffer[100] = {};

    FILE *ReadFH, *WriteFH, *ReadWriteFH;

    if (argc > 3)
    {
        strcpy(readFileName, argv[1]);
        strcpy(writeFileName, argv[2]);
        strcpy(rwFileName, argv[3]);

    }

    ReadFH = fopen(readFileName, "r");
    WriteFH = fopen(writeFileName, "w");
    ReadWriteFH = fopen(rwFileName, "w+");

    if (ReadFH == NULL || WriteFH == NULL || ReadWriteFH == NULL)
    {
        printf("A file did not opening properly...exiting\n");
        exit(0);
    }
    else
    {
        printf("All files opened\n");
    }

    return 0;

}