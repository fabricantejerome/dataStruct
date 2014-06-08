#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valRand(){
	int val;
	srand( (unsigned)time( NULL ) );
	val = 1 + rand() % 4;
	return val;
}

/* function main begins program execution */
int main() 
{
	int customerCounter = 0;
	int time = 0;
	int random = valRand();
	int serviceTime = time + valRand();
	
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	
	while( time <= 720 )
	{
		system( "sleep 1" );
		system( "clear" );
		printf( "CustomerCounter: %d\n", customerCounter );
		printf( "Time: %d\n", time );
		printQueue( headPtr );
		if(  time > random )
		{
			enqueue( &headPtr, &tailPtr, customerCounter );
			customerCounter++;
			random = random + valRand();
		}
		if( time > serviceTime )
		{
			if( !isEmpty( headPtr ) )
			{
				dequeue( &headPtr, &tailPtr );
			}
			serviceTime = time + valRand();
		}
		time++;
	}
    return 0;
}
