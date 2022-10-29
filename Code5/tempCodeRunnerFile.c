/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void DashIt(char *Phrase, char DashPhrase[])
{
	char *ReplaceIt;
	char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;

	/* Put the uppercase version of Phrase into DashPhrase */
	char *s = Phrase;
    while (*s) {
        DashPhrase[i] = toupper((unsigned char) *s);
        s++;
    }
    printf("%s", DashPhrase);
	/* Call strpbrk() with DashPhrase and Alphabet and save the result in ReplaceIt */
	ReplaceIt = strpbrk(DashPhrase, Alphabet);

	/* while ReplaceIt is not NULL */
	while (ReplaceIt != NULL)
	{
		/* Dereference ReplaceIt and set it to a dash */
		*ReplaceIt = '_';
		/* Call strpbrk() again */
		ReplaceIt = strpbrk(Phrase, Alphabet);
	}
}


int main()
{
    
    char phrase[] = "Hello World";
    
    char DashPhrase[10] ={}; 

    DashIt(phrase, DashPhrase);
    
    printf("%s", DashPhrase);

    return 0;
}
