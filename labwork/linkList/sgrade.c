#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sgrade{
	int idno;
	char grade[20];
	struct sgrade *nextPtr;
};
typedef struct sgrade Sgrade;
typedef Sgrade *SgradePtr;

void insert( SgradePtr *sPtr, int x, char *y );
void printList( SgradePtr currentPtr );

int main()
{
	SgradePtr startPtr = NULL;
	int IDNO;
	char GRADE[20];
	int choice;
	
	printf("Enter 1 to add 0 to exit: ");
	scanf("%d",&choice );
	while( choice == 1 )
	{
		scanf( "%d%s",&IDNO, GRADE );
		insert( &startPtr, IDNO, GRADE );
		printList( startPtr );
		
		printf("Enter 1 to add 0 to exit: ");
		scanf("%d", &choice );
	}
return 0;	
}
void insert( SgradePtr *sPtr, int x, char *y)
{
	SgradePtr newPtr;
	SgradePtr previousPtr;
	SgradePtr currentPtr; 
	
	newPtr = malloc( sizeof( Sgrade ) );
	if( newPtr != NULL )
	{
		newPtr->idno = x;
		strcpy(newPtr->grade, y);
		newPtr->nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		
		while( currentPtr != NULL && x > currentPtr->idno )
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
} /* end of function */
void printList( SgradePtr currentPtr )
{
	/* if list is empty */
	if( currentPtr == NULL ){
		printf( "List is empty.\n\n" );
	}/* end if */
	else{
		printf( "IdNumber\tGrade \n" );
		
		/* while not the end of the list */
		while( currentPtr != NULL){
			printf( "%d\t\t%s\n",currentPtr->idno,currentPtr->grade);
			currentPtr = currentPtr->nextPtr;
		}/* end while */
		
	}/* end else */
}/* end of function printList */

