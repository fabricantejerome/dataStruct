#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackNode{
	char *data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push( StackNodePtr *topPtr, char *info );
void printStack( StackNodePtr currentPtr );
char pop( StackNodePtr *topPtr );
char isEmpty( StackNodePtr topPtr );

int main()
{
	StackNodePtr stackPtr = NULL;
	char *sentence = NULL;
	char *tokenPtr;
	int size = 255;
	int last = 0;
	
	last = getline( &sentence, &size, stdin );
	sentence[last-1] = '\0';
	tokenPtr = strtok( sentence, " " );
	while( tokenPtr != NULL )
	{
		push( &stackPtr, tokenPtr );
		tokenPtr = strtok( NULL, " " );
	}// end while
	printStack( stackPtr );
	while( !isEmpty( stackPtr ) )
	{
		pop( &stackPtr );
	}// end while
		
return 0;	
}/* end of function main */
void push( StackNodePtr *topPtr, char *info )
{
	StackNodePtr newPtr;
	
	newPtr = malloc( sizeof( StackNode ) );
	if( newPtr != NULL )
	{
		newPtr->data = ( char* )malloc( sizeof( char ) * strlen( info ) );		
		strcpy( newPtr->data, info );
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}// end if
	else 
	{
		printf("%s is not inserted. no memory available.\n", info);
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
         printf( "%s --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } /* end while */

      printf( "NULL\n\n" );
   } /* end else */

} /* end function printList */
char pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr;
	char *popValue;
	
	tempPtr = *topPtr;
	popValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr);
	
	return *popValue;
}// end of function

char isEmpty( StackNodePtr topPtr )
{
		return topPtr == NULL;
}// end of function isEmpty




