/*
Author: Mai Tran
UTA ID: 1002092849
CSE-1320-Coding asignment 6 
*/

#include <string.h>
#include "ListLib.h"
void AddDrawCommandToList(char letter, char DrawCommand[], NODE** LinkListHead)
{

	/* declare pointers of type NODE named TempPtr and NewNode */
	NODE *TempPtr, *NewNode;
    
	/* malloc a new node and assign the Letter and the DrawCommand (after mallocing memory for it) */
	NewNode = malloc(sizeof(NODE));
	NewNode->Letter = letter;
	NewNode->DrawCommand = malloc((strlen(DrawCommand)+1)*sizeof(char));
	strcpy(NewNode->DrawCommand, DrawCommand);
	NewNode->next_ptr = NULL;


	/* If the LinkedListHead is NULL, then give it the address of the new node */
	if (*LinkListHead == NULL)
	{
		*LinkListHead = NewNode;
	}/* Else traverse to the end of the linked list and add the new node */
	else 
	{
		TempPtr = *LinkListHead;
		while (TempPtr->next_ptr != NULL)
		{
			TempPtr = TempPtr->next_ptr;
		}
		TempPtr->next_ptr = NewNode;
	}
}

NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{
	NODE *tempPtr;
	tempPtr = LinkedListHead;

	/* while traversing the linked list AND the Letter in the node is not the Letter passed in */
	while (tempPtr != NULL && tempPtr->Letter != Letter)
	{
		/* move TempPtr */
		tempPtr = tempPtr->next_ptr;
	}

	/* if TempPtr is not NULL */
	if (tempPtr != NULL)
	{
		/* copy the DrawCommand from the node into the passed in parameter */
		strcpy(DC, tempPtr->DrawCommand);

		/* return the next pointer stored in TempPtr */
		return (tempPtr->next_ptr);
	}
	else
	{
		//Set DC to NULLs to signal that we found all of the nodes for this letter
		memset(DC, '\0', sizeof(*DC)); 

		/* return TempPtr */
		return tempPtr;
	}
}
