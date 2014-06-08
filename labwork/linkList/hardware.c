#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hardware{
	int recordNo;
	char toolsName[20];
	int quantity;
	struct hardware *nextPtr;
};

typedef struct hardware Hardware;
typedef Hardware *HardwarePtr;

void insert( HardwarePtr *sPtr, int x, char *y, int z);
void printList( HardwarePtr currentPtr );

int main()
{
	HardwarePtr startPtr = NULL;
	int recordNo2;
	char toolsName2[20];
	int quantity2;
	int choice;
	
	printf("Enter 1 to add 0 to exit: ");
	scanf("%d", &choice );
	while( choice == 1 )
	{
		scanf("%d %s %d",&recordNo2, toolsName2, &quantity2 );
		insert( &startPtr, recordNo2, toolsName2, quantity2 );
		printList( startPtr );
		
		printf("Enter 1 to add 0 to exit: ");
		scanf("%d", &choice );
	}
return 0;
}
void insert( HardwarePtr *sPtr, int x, char *y, int z )
{
	HardwarePtr newPtr;
	HardwarePtr currentPtr;
	HardwarePtr previousPtr;
	
	newPtr = malloc( sizeof( Hardware ) );
	if( newPtr != NULL )
	{
		newPtr->recordNo = x;
		strcpy(newPtr->toolsName, y);
		newPtr->quantity = z;
		newPtr->nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		while( currentPtr != NULL && x > currentPtr->recordNo )
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
}
void printList( HardwarePtr currentPtr )
{
	/* if list is empty */
	if( currentPtr == NULL ){
		printf( "List is empty.\n\n" );
	}/* end if */
	else{
		printf( "RecordNo.\tToolsName\tQuantity\n" );
		
		/* while not the end of the list */
		while( currentPtr != NULL){
			printf( "%d\t\t%s\t\t%d\n",currentPtr->recordNo,currentPtr->toolsName,currentPtr->quantity);
			currentPtr = currentPtr->nextPtr;
		}/* end while */
		
	}/* end else */
}/* end of function printList */



