/* ListLib-Template */

#include "ListLib.h"
/* add return type */ AddDrawCommandToList(/* Add parameters */)
{
    NODE *TempPtr, *NewNode;
	/* declare pointers of type NODE named TempPtr and NewNode */
    
	/* malloc a new node and assign the Letter and the DrawCommand (after mallocing memory for it) */

	/* If the LinkedListHead is NULL, then give it the address of the new node */
	/* Else traverse to the end of the linked list and add the new node */
}

/* add return type */ FindLetter(/* Add parameters */)
{
	/* while traversing the linked list AND the Letter in the node is not the Letter passed in */
	{
		/* move TempPtr */
	}

	if (/* TempPtr is not NULL */)
	{
		/* copy the DrawCommand from the node into the passed in parameter */
		/* return the next pointer stored in TempPtr */
	}
	else
	{
		memset(DC, '\0', sizeof(*DC));  //Set DC to NULLs to signal that we found all of the nodes for this letter
		/* return TempPtr */
	}
}
