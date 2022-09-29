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

    // print the title
    printf("    B       I       N       G       O    \n");
    printf("-----------------------------------------\n");

    // print bingo card
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLLUMN; col++)
        {
            if (bingo_array[row][col] == 0) {
                printf("%c%4c%3c",'|', 'X', ' ');
            }
            else 
            {
                printf("%c%4d%3c",'|', bingo_array[row][col], ' ');
            }
        }
        printf("|\n");
        printf("-----------------------------------------\n");
    }
}

int pick_random_number()
{
    return (rand() % 75 + 1);
}

char get_precedence(int number)
{

    char precedence;

    if (number <=  15)
    {
        precedence = 'B';
    }
    else if (number <= 30)
    {
        precedence = 'I';
    } 
    else if (number <= 45)
    {
        precedence = 'N';
    } 
    else if (number <= 60)
    {
        precedence = 'G';
    }
    else if (number <= 75)
    {
        precedence = 'O';
    }
    return precedence;

}

int is_from_bingo(int bingo[ROW][COLLUMN], int test_number) 
{
    int from_bingo = 0;
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLLUMN; col++)
        {
            if (bingo[row][col] == test_number)
            {
                from_bingo = 1;
            }
        }
    }
    return (from_bingo);
}



int main()
{
    srand(time(0));
    
    // empty bingo card
    int bingo_array[5][5] = {};
    
    // fill bingo card
    fill_bingo_card(bingo_array);
    
    // screen bingo card to screen
    print_bingo_card(bingo_array);

    int is_win = 0;
    int drawn_remains = 75;
    int chosed_number[75] = {};
    int current_pick;
    char choice;

    while (!is_win && drawn_remains > 0)
    {
        current_pick = pick_random_number();

        while (!(is_unique(chosed_number, 75 - drawn_remains, current_pick)))
        {
            current_pick = pick_random_number();
        }

        chosed_number[75 - drawn_remains] = current_pick;
        drawn_remains--;
        //printf("Pick number is: %d\n", current_pick);
        //printf("%d. the next number is %c%d\n",75 - drawn_remains, get_precedence(current_pick), current_pick);
        printf("\nThe next number is %c%d\n\n", get_precedence(current_pick), current_pick);
        printf("Do you have it ? (Y/N)");
        getchar();
        scanf("%c", &choice);
        if (choice == 'Y')
        {
            if (is_from_bingo(bingo_array, 25, current_pick))
            {

            }
        }
    }

    return 0;
}
