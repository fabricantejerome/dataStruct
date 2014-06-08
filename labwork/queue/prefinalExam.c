#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int valRand(){
	int val;
	val = 1 + rand() % 4;
	return val;
}
int valRand2(){
	int val2;
	val2 = 1 + rand() % 6;
	return val2;
}

/* function main begins program execution */
int main()
{
	int customerCounter = 1;
	int time1 = 0;
	int random = valRand();
	int serviceTime = 0;
	int serviceTime2 = 0;
	int counter1 = 0;
	int counter2 = 0;

	srand( (unsigned)time(NULL) );
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;


	while( time1 <= 720 )
	{
		system( "sleep 0.5" );
		system( "clear" );
		printf( "CustomerCounter: %d\n", customerCounter );
		printf( "Time: %d\n", time1 );
		printQueue( headPtr );
		if(  time1 > random )
		{
			enqueue( &headPtr, &tailPtr, customerCounter );
			customerCounter++;
			random = random + valRand();
		}
		else if( time1 > serviceTime )
		{
			if( !isEmpty( headPtr ) )
			{
				counter1 = dequeue( &headPtr, &tailPtr );
			}
			serviceTime = time1 + valRand2();
		}
		else if( time1 > serviceTime2 )
		{
			if( !isEmpty( headPtr ) )
			{
				counter2 = dequeue( &headPtr, &tailPtr );
			}
			serviceTime2 = time1 + valRand2();
		}
		printf( "Counter 1 is servicing: %d\n", counter1 );
		printf( "Counter 2 is servicing: %d\n", counter2 );
		time1++;
	}
    return 0;
}
