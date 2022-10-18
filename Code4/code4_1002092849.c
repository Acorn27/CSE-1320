/*
Author: Mai Tran
UTA ID: 1002092849
CSE 1320 Coding Assignment 4
Last modified: 10/18/2020
*/

#include "DrawTool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{   
    // declare 2D array of max size defined
    char draw_board[MAXMAPSIZE][MAXMAPSIZE] = {};

    // user enter map size
    int map_size = 0;

    // call function InitializeMap from DrawTool
    InitializeMap(draw_board, &map_size);

    // discard '\n' left over in buffer
    getchar();

    // call PrintInstructions() from DrawTool
    PrintInstructions();

    // call function PrintMap() from DrawTool
    PrintMap(draw_board, map_size);

    // prompt for user command
    char userInput[20];
    printf("Enter draw command (enter Q to quit) ");
    fgets(userInput, 19, stdin);

    char delim[] = "(),";
    char letter_command;
    int x_coordinate, y_coordinate, length;
    char mark;

    char* token = strtok(userInput, delim);
    letter_command = *token;

    token = strtok(NULL, delim);
    x_coordinate = *token;

    token = strtok(NULL, delim);
    y_coordinate = *token;

    token = strtok(NULL, delim);
    length = *token;

    token = strtok(NULL, delim);
    mark = *token;




}