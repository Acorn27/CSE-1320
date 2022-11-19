#include <stdio.h>
#include "DrawTool.h"
#include "FileLib.h"
#include "ListLib.h"

int main(int argc, char *argv[])
{   

    NODE *LinkListHead;

    // call OpenFIle() in main()
    FILE *MyFile;
    MyFile = OpenFile(argc, argv);

    // call ReadFileIntoLinkedList()
    ReadFileIntoLinkedList(MyFile, &LinkListHead);




    return 0;    
}