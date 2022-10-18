/*
Author: Mai Tran
UTA ID: 1002092849
CSE 1320 Coding Assignment 4
Last modified: 10/18/2020 4pm
*/

#include "DrawTool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int valid_range(int x, int y, int length, int max, char type);


int main()
{   
    // declare 2D array of max size defined
    char draw_board[MAXMAPSIZE][MAXMAPSIZE] = {};

    // delimiter 
    char delim[] = "(),";
    // draw command 'H', 'V', or 'P'
    char draw_command[2]= {};
    int x_coordinate, y_coordinate, length;
    char mark[2] = {};

    // user enter map size
    int map_size = 0;

    // call function InitializeMap from DrawTool
    InitializeMap(draw_board, &map_size);

    // discard '\n' left over in buffer
    //getchar();

    // call PrintInstructions() from DrawTool
    PrintInstructions();

    // call function PrintMap() from DrawTool
    PrintMap(draw_board, map_size);

    // prompt for user command
    char userInput[20];
    printf("\nEnter draw command (enter Q to quit) ");
    fgets(userInput, 19, stdin);

    // parse command letter
    char* token;
    token = strtok(userInput, delim);
    strcpy(draw_command, token);
    draw_command[0] = toupper(draw_command[0]);


    while (draw_command[0] != 'Q')
    {
        token = strtok(NULL, delim);
        x_coordinate = atoi(token);

        token = strtok(NULL, delim);
        y_coordinate = atoi(token);

        token = strtok(NULL, delim);
        length = atoi(token);

        token = strtok(NULL, delim);
        strcpy(mark, token);

        if (valid_range(x_coordinate, y_coordinate, length, map_size, draw_command[0]))
        {  
            if (draw_command[0] == 'P')
            {
                draw_board[x_coordinate][y_coordinate] = mark[0];
            }
            else if (draw_command[0] == 'H' || draw_command[0] == 'V')
            {
                DrawLine(draw_board, x_coordinate, y_coordinate, draw_command[0], length, mark[0]);
            }
            else
            {
                printf("\nThat draw command is unknown\n");
            }

        } else
        {
            printf("\nThat draw command is out of range\n");
        }
                                
        PrintMap(draw_board, map_size);
        printf("\nEnter draw command (enter Q to quit) ");
        fgets(userInput, 19, stdin);
        token = strtok(userInput, delim);
        strcpy(draw_command, token);
        draw_command[0] = toupper(draw_command[0]);

    }

    printf('\n');
    return 0;

}


int valid_range(int x, int y, int length, int max, char type)
{

    int general_test = 1,
        case_H_test = 1,
        case_V_test = 1;

    // general test
    if (x < 0 || x >= max || y < 0 || y >= max)
    {
        general_test = 0;
    }

    // case_test
    if (general_test != 0)
    {
        if (type == 'H')
        {
            if (y + length > max)
            {
                case_H_test = 0;
            }
        }
        else if (type == 'V')
        {
            if (x + length > max)
            {
                case_V_test = 0;
            }
        }

    }
    return (general_test && case_H_test && case_V_test);
}

