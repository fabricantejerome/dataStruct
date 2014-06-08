#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no{
	int number;
	struct no *nextPtr;
};
typedef struct no No;
typedef No *NoPtr;

void insert( NoPtr *sPtr, int x );
void printList( NoPtr currentPtr );

int main()
{
	NoPtr startPtr = NULL;
	int number1;
	int counter = 0;
	int total = 0;
	
	srand( time ( NULL ) );
	while( counter < 25 )
	{
		number1 = 1 + rand() % 100;
		insert( &startPtr, number1 );
		printList( startPtr );
		total = total + number1;
		counter++;
	}
	printf("The sum of all number is: %d \n", total);
	printf("The average of all number is: %f\n", (float)total/(float)counter );

return 0;	
}//end of main function
void insert( NoPtr *sPtr, int x )
{
	NoPtr newPtr;
	NoPtr previousPtr;
	NoPtr currentPtr;
	
	newPtr = malloc( sizeof( No ) );
	if( newPtr != NULL )
	{
		newPtr->number = x;
		newPtr->nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		while( currentPtr != NULL && x > currentPtr->number )
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		} 
		if( previousPtr == NULL )
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else
	{
		printf("not inserted no memory available\n");
	}
}// end of insert function
void printList( NoPtr currentPtr )
{
	/* if list is empty */
	if( currentPtr == NULL ){
		printf( "List is empty.\n\n" );
	}/* end if */
	else{
		printf( "The list is: \n" );

		/* while not the end of the list */
		while( currentPtr != NULL){
			printf( "%d\n",currentPtr->number );
			currentPtr = currentPtr->nextPtr;
		}/* end while */
	}/* end else */
}// end of printList function


