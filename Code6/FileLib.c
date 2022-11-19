// FileLib Template

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
		printf("Enter a file name at the prompt ");
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
	
	/* while fgets() reads the file */
	{
		/* if line from file ends with \n, then replace \n with \0 */
		
		/* tokenize to get the Letter and the DrawCommand */
	
		/* Call AddDrawCommandToList with correct parameters */
	}
}
