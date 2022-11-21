/*
Author: Mai Tran
UTA ID: 1002092849
CSE-1320-Coding asignment 6 
*/

#include <stdio.h>
#include <string.h>
#include "ListLib.h"

FILE *OpenFile(int argc, char *argv[])
{	
	/* declare various variables needed */
	char FileName[20] = {};
	FILE* MyFile;

	/* if argc is 2, then use argv[1] as the input file name, else print the message seen in sample output */
	if (argc == 2)
	{
		strcpy(FileName, argv[1]);
	}
	else 
	{
		printf("Must run with an input file name.\n");
		/* read in new filename */
		printf("Enter a file name at the prompt ");
		scanf("%s", FileName);
	}

	do
	{
		/* open file with "r" mode */
		MyFile = fopen(FileName, "r");

		/* if file did not open */
		if (MyFile == NULL)
		{
			/* print message seen in sample output */
			printf("Could not open a file named %s", FileName);

			/* read in new filename */
			printf("Enter a file name at the prompt ");
			scanf("%s", FileName);

			/* open the file "r" mode */
			MyFile = fopen(FileName, "r");
		}
	}
	while (MyFile == NULL);

	/* return the file handle */
	return MyFile;
}

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
	/* declare various variables needed */
	char Buffer[200] = {};
	char *tok;
	char letter;
	char DrawCommand[200];
	
	/* while fgets() reads the file */
	while (fgets(Buffer, sizeof(Buffer) -1, DCFile))
	{
		/* if line from file ends with \n, then replace \n with \0 */
		if (Buffer[strlen(Buffer)-1] == '\n')
		{
			Buffer[strlen(Buffer)-1] = '\0';
		}
		
		/* tokenize to get the Letter and the DrawCommand */
		tok = strtok(Buffer, "|");
		strcpy(DrawCommand, tok);
		letter = DrawCommand[0];
		
		tok = strtok(NULL, "|");
		strcpy(DrawCommand, tok);

	
		/* Call AddDrawCommandToList with correct parameters */
		AddDrawCommandToList(letter, DrawCommand, LinkedListHead);
	}
}
