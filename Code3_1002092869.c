/*
Author: Mai Tran
UTA ID: 1002092849
Course: CSE 1320
Last modified: 09/28/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COLUMN 5


// supplement function, use 1D array to keep track of used random number
// take array, size, and test_number as parameter
int is_unique(int[], int, int);

// fill card with unique random number in proper range
void fill_bingo_card(int[ROW][COLUMN]);

// print bingo card to the screen
void print_bingo_card(int[ROW][COLUMN]);

// pick a random number that has not been chosed
int pick_random_number(int[75]);

// complement function for pick_random_number function
// return 'B', 'I',... base on number passed to function
char get_precedence(int);

// check if number existed in player's bingo card
int is_from_bingo(int[ROW][COLUMN], int);

// check for complete row
int is_complete_row(int[ROW][COLUMN]);

//check for complete collumn
int is_complete_column(int bingo[ROW][COLUMN]);

// check for compelte diagnose
int is_complete_diagnal(int bingo[ROW][COLUMN]);


int main()
{
    srand(time(0));
    
    // empty bingo card
    int bingo_array[ROW][COLUMN] = {};
    
    // fill bingo card function
    fill_bingo_card(bingo_array);
    
    // screen bingo card to screen
    print_bingo_card(bingo_array);

    int is_win = 0;
    int number_count = 0;

    // keep track of random number that has not been picked
    int chosed_number[75] = {};

    // current random number
    int current_pick;

    // user choice
    char choice = 'Y';

    int sum = 0;
    
    // game loop
    while (!is_win && number_count < 75)
    {
        // pick unique random number
        current_pick = pick_random_number(chosed_number);

        // update dupplicate array
        chosed_number[number_count] = current_pick;
        sum+= current_pick;

        // temp
        number_count++;

        /*
        // prompt for user choice
        printf("Do you have it ? (Y/N) ");
        scanf("%c", &choice);

        // flush buffer for the next interation
        getchar();


        if (choice == 'Y')
        {   
            // if number drawn is a number from bingo card
            if (is_from_bingo(bingo_array, current_pick))
            {   
                // reprint bingo card
                print_bingo_card(bingo_array);

                // increase draw count by one
                number_count++;

                if (is_complete_row(bingo_array) && is_complete_column(bingo_array) && is_complete_diagnal(bingo_array))
                {
                    printf("\nYou filled out a row and a collumn and a diagnal -- BINGO!!!\n");
                    is_win = 1;
                }
                else if (is_complete_row(bingo_array) && is_complete_column(bingo_array))
                {
                    printf("\nYou filled out a row and a column -- BINGO!!!\n");
                    is_win = 1;
                }
                else if (is_complete_column(bingo_array) && is_complete_diagnal(bingo_array))
                {
                    printf("\nYou filled out a column and a diagnal -- BINGO!!!\n");
                    is_win = 1;
                }
                else if (is_complete_row(bingo_array) && is_complete_diagnal(bingo_array))
                {
                    printf("\nYou filled out a row and a diagnal -- BINGO!!!\n");
                    is_win = 1;
                }
                else if (is_complete_row(bingo_array))
                {
                    printf("\nYou filled out a row -- BINGO!!!\n");
                    is_win = 1;
                }
                else if (is_complete_column(bingo_array))
                {
                    printf("\nYou filled out a column -- BINGO!!!\n");
                    is_win = 1;
                }
                else if (is_complete_diagnal(bingo_array))
                {
                    printf("\nYou filled out a diagnal -- BINGO!!!\n");
                    is_win = 1;
                }

            }
            else 
            {
                printf("\nThat value is not on your BINGO card - are you trying to cheat??\n");
                print_bingo_card(bingo_array);
            }
        } 
        else 
        {
            print_bingo_card(bingo_array);
        }
    */
    }
    
    printf("Sum is %d", sum);

    return 0;
}

void fill_bingo_card(int bingo_array[ROW][COLUMN])
{   
    // keep track of unique random number for each collumn, initialize to -1 
    int dup_array[COLUMN] = {-1, -1, -1, -1, -1};

    // most recent random numebr
    int current_number = -1;
    
    // loop through empty array
    for (int col = 0; col < COLUMN; col++)
    {
        for (int row = 0; row < ROW; row++)
        {
            
            // get random number in a rangle related to collumn
            current_number = (rand() % 15) + 15*col + 1;
            
            // re-create random number if the number has been previously used
            while (!(is_unique(dup_array, COLUMN, current_number)))
            {
                current_number = (rand() % 15) + 15*col + 1;
            }
            
            // add the new digit to track array
            dup_array[row] = current_number;

            // all previous condition meet, set this random number to array
            bingo_array[row][col] = current_number;
        }
    }

    // set center of board to 0
    bingo_array[2][2] = 0;
}

void print_bingo_card(int bingo_array[ROW][COLUMN])
{

    // print the title
    printf("\n    B       I       N       G       O    \n");
    printf("-----------------------------------------\n");

    // print bingo card
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLUMN; col++)
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

int is_unique(int dup_array[], int size, int test_number)
{
    int is_unique = 1;
    
    for (int i = 0; i < size && is_unique; i++)
    {
        if (dup_array[i] == test_number)
        {
            is_unique = 0;
        }
    }
    
    return is_unique;
}

int pick_random_number(int chosed_number[75])
{

    int ran_number = (rand() % 75 + 1);

    // if number alreay been pick, pick another number
    while (!(is_unique(chosed_number, 75, ran_number)))
        {
            ran_number = rand() % 75 + 1;
        }
    printf("\nThe next number is %c%d\n\n", get_precedence(ran_number), ran_number);
    return (ran_number);
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

int is_from_bingo(int bingo[ROW][COLUMN], int test_number) 
{
    int from_bingo = 0;
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLUMN; col++)
        {
            if (bingo[row][col] == test_number)
            {   
                bingo[row][col] = 0;
                from_bingo = 1;
            }
        }
    }
    return (from_bingo);
}

int is_complete_row(int bingo[ROW][COLUMN])
{   
    // set is_completed to false
    int is_completed = 0;

    // condition: if row < max_row and one we haven't had any complete row yet
    for (int row = 0; row < ROW && !(is_completed); row++)
    {   
        // assume at the beginning of each row that it is a completed on
        is_completed = 1;
        for (int col = 0; col < COLUMN; col++)
        {   
            // mark incomplete if one elemnt is not complete
            if (bingo[row][col] != 0)
            {   
                is_completed = 0;
            }
        }
    }
    return (is_completed);
}

int is_complete_column(int bingo[ROW][COLUMN])
{
    // set is_completed to false
    int is_completed = 0;

    // condition: if col < max_col and one we haven't had any complete collumn yet
    for (int col = 0; col < COLUMN && !(is_completed); col++)
    {   
        // assume at the beginning of each row that it is a completed on
        is_completed = 1;
        for (int row = 0; row < ROW; row++)
        {
            // mark incomplete if one elemnt is not complete
            if (bingo[row][col] != 0)
            {
                is_completed = 0;
            }
        }
    }
    return (is_completed);
}

int is_complete_diagnal(int bingo[ROW][COLUMN]) 
{
    // initialized to true
    int is_complete = 1;

    // check for main diagnal
    for (int i = 0; i < ROW; i++)
    {   
        if (bingo[i][i] != 0)
        {
            is_complete = 0;
        }
    }

    // check for anti diagnal if the main diagnal test failed
    if (is_complete == 0)
    {
        // assume anti diagnal exist
        is_complete = 1;

        // if condiiton is not meet, set is_complete to falase
        for (int i = 0; i < ROW; i++)
        {      
            if (bingo[i][ROW -i-1] != 0)
            {
                is_complete = 0;
            }
        }
    }
return (is_complete);
}