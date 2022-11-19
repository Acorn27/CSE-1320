#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "DrawTool.h"
#include "FileLib.h"
#include "ListLib.h"

int main(int argc, char *argv[])
{   

    // Linked list head
    NODE *LinkListHead;
    LinkListHead = NULL;

    char map[MAXMAPSIZE][MAXMAPSIZE] = {};
    char Buffer[5] = {};
    char DC[100] = {};
    NODE *TempPtr;
    char draw_command[5]= {};
    int x_coordinate, y_coordinate, length;
    char mark[5] = {};

    // call OpenFIle() in main()
    FILE *MyFile;
    MyFile = OpenFile(argc, argv);

    // call ReadFileIntoLinkedList()
    ReadFileIntoLinkedList(MyFile, &LinkListHead);

    // initialize map
    InitializeMap(map);

    printf("Please enter 1-3 letters ");
    scanf("%s", Buffer);

    //for loop over strlen of numbers of letters entered
    for (int i = 0; i < strlen(Buffer)-1; i++)
    {
        //uppercase the current letter
        Buffer[i] = toupper(Buffer[i]);

        // Find the first node containing your first letter and
        // get back a bookmark to the next node
        TempPtr = FindLetter(LinkListHead, Buffer[i], DC);
        // Either check the strlen() of draw command (0 means it was set to NULL)
        // or check if element [0] of draw command is '\0'
        // You want to continue to loop while your draw command has something in it
        while (DC[0] != '\0')
        {
            //tokenize and draw the command
            // parse command letter
            char* token;
            token = strtok(DC, "(),");
            strcpy(draw_command, token);
            draw_command[0] = toupper(draw_command[0]);

            // x starting coordinate
            token = strtok(NULL, "(),");
            x_coordinate = atoi(token);

            // y starting coordinate
            token = strtok(NULL, "(),");
            y_coordinate = atoi(token);

            // draw distance
            token = strtok(NULL, "(),");
            length = atoi(token);

            // fill character
            token = strtok(NULL, "(),");
            strcpy(mark, token);
            // strcmp \0 or \n ???
            if (strcmp(mark,"\0") == 0)
            {
                strcpy(mark,"X");
            }

            if (draw_command[0] == 'P')
            {
                map[x_coordinate][y_coordinate] = mark[0];
            }
            else if (draw_command[0] == 'H' || draw_command[0] == 'V')
            {
                DrawLine(map, x_coordinate, y_coordinate, draw_command[0], length, mark[0]);
            }
            else
            {
                printf("\nThat draw command is unknown\n");
            }

            // Look for the next node containing the letter
            // draw command will be NULL if not found
            TempPtr = FindLetter(TempPtr, Buffer[i], DC);
        }
    }

    return 0;    
}