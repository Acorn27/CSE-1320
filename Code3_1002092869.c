/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COLLUMN 5

int is_unique(int dup_array[], int size, int test_number)
{
    int is_unique = 1;
    
    for (int i = 0; i < size; i++)
    {
        if (dup_array[i] == test_number)
        {
            is_unique = 0;
        }
    }
    
    return is_unique;
}


void fill_bingo_card(int bingo_array[ROW][COLLUMN])
{
    int dup_array[COLLUMN] = {-1, -1, -1, -1, -1};
    int current_element = -1;
    int size;
    
    for (int col = 0; col < COLLUMN; col++)
    {
        for (int row = 0; row < ROW; row++)
        {
            current_element = (rand() % 15) + 15*col + 1;
            size = sizeof(dup_array) / sizeof(int);
            
            while (!(is_unique(dup_array, size, current_element)))
            {
                current_element = (rand() % 15) + 15*col + 1;
            }
            
            dup_array[row] = current_element;
            bingo_array[row][col] = current_element;
        }
    }
}

void print_bingo_card(int bingo_array[ROW][COLLUMN])
{
    
    printf("%5c%3c%5c%3c%5c%3c%5c%3c%5c%3c\n", 'B', ' ','I', ' ','N', ' ','G', ' ','O', ' ');
    printf("-----------------------------------------\n");
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLLUMN; col++)
        {
            printf("%c%4d%3c",'|', bingo_array[row][col], ' ');
        }
        printf("|\n");
        printf("-----------------------------------------\n");
    }
}


int main()
{
    srand(time(0));
    
    //printf("Hello World");
    
    int bingo_array[5][5] = {};
    
    fill_bingo_card(bingo_array);
    
    print_bingo_card(bingo_array);

    return 0;
}
