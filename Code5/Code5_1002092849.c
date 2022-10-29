
/* 
Author: Mai Tran
UTA ID: 1002092849
Coding Assignment 5
Last Modified: 10/28/2022 
*/
# include <stdio.h>
# include "GameLib.h"
# include <string.h>
# include <stdlib.h>

/* Add necessary includes */

int main(void)
{

	// 3 NULL arrays
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};

	// keep track of number of strikes
	int Strikes = 0;
	int i;
	
	/* Call StartGame and pass in Phrase */
	StartGame(Phrase);

	/* Call DashIt and pass in Phrase and DashedPhrase */
	DashIt(Phrase, DashedPhrase);

	/* uppercase Phrase */
	for (i = 0; i < strlen(Phrase); i++)
	{
	    UpperPhrase[i] = toupper(Phrase[i]);
	}
	
	printf("\nHere's the phrase you need to guess\n");

	do
	{
		/* if !(call GuessALetter and pass Phrase, DashedPhrase and UpperPhrase) */
		if (!(GuessALetter(Phrase, DashedPhrase, UpperPhrase)))
		{
			Strikes++;
			printf("\nStrike %d", Strikes);
		}
	}
	/* while (call strchr() with DashedPhrase with -) AND strike counter is less than strikes define */
	while (strchr(DashedPhrase,'-') && Strikes < STRIKES);


	if (Strikes < STRIKES)
	{
		printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
		printf("\n\nYOU WIN!!!!\n");
	}
	else
	{
		printf("\n\n");
		printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
		printf("Game over\n\n");
	}
	return 0;
}
