#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackNode{
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push( StackNodePtr *topPtr, int info );
void printStack( StackNodePtr currentPtr );
int pop( StackNodePtr topPtr );
int isEmpty( StackNodePtr topPtr );

void push( StackNodePtr *topPtr, int info )
{
	StackNodePtr newPtr;
	
	newPtr = malloc( sizeof( StackNode ) );
	if( newPtr != NULL )
	{
		//newPtr->data = ( char* )malloc( sizeof( char ) * strlen( info ) );		
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}// end if
	else 
	{
		printf("%d is not inserted. no memory available.\n", info);
	}
}// end of push
void printStack( StackNodePtr currentPtr )
{ 
   /* if stack is empty */
   if ( currentPtr == NULL ) {
      printf( "The stack is empty.\n\n" );
   } /* end if */
   else { 
      printf( "The stack is:\n" );

      /* while not the end of the stack */
      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } /* end while */

      printf( "NULL\n\n" );
   } /* end else */

} /* end function printList */
char pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr;
	int popValue;
	
	tempPtr = *topPtr;
	popValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr);
	
	return popValue;
}// end of function

char isEmpty( StackNodePtr topPtr )
{
		return topPtr == NULL;
}// end of function isEmpty




