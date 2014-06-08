#include <stdio.h>
#include <stdlib.h>
/* self-referential structure */
struct queueNode {
   int data;                 /* define data as a char */
   struct queueNode *nextPtr; /* queueNode pointer */
}; /* end structure queueNode */

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;	

/* function prototypes */
void printQueue( QueueNodePtr currentPtr );
int isEmpty( QueueNodePtr headPtr );
int dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr );
void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr,
              int value );
void instructions( void );

/* display program instructions to user */
void instructions( void )
{
   printf ( "Enter your choice:\n"
           "   1 to add an item to the queue\n"
           "   2 to remove an item from the queue\n"
           "   3 to end\n" );
} /* end function instructions */

/* insert a node a queue tail */
void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr,
              int value )
{
   QueueNodePtr newPtr; /* pointer to new node */

   newPtr = (QueueNodePtr)malloc( sizeof( QueueNode ) );

   if ( newPtr != NULL ) { /* is space available */
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      /* if empty, insert node at head */
      if ( isEmpty( *headPtr ) ) {
         *headPtr = newPtr;
      } /* end if */
      else {
         ( *tailPtr )->nextPtr = newPtr;
      } /* end else */

      *tailPtr = newPtr;
   } /* end if */
   else {
      printf( "%d not inserted. No memory available.\n", value );
   } /* end else */

} /* end function enqueue */

/* remove node from queue head */
int dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr )
{
   int value;           /* node value */
   QueueNodePtr tempPtr; /* temporary node pointer */

   value = ( *headPtr )->data;
   tempPtr = *headPtr;
   *headPtr = ( *headPtr )->nextPtr;

   /* if queue is empty */
   if ( *headPtr == NULL ) {
      *tailPtr = NULL;
   } /* end if */

   free( tempPtr );

   return value;

} /* end function dequeue */

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( QueueNodePtr headPtr )
{
   return headPtr == NULL;

} /* end function isEmpty */

/* Print the queue */
void printQueue( QueueNodePtr currentPtr )
{

   /* if queue is empty */
   if ( currentPtr == NULL ) {
      printf( "Queue is empty.\n\n" );
   } /* end if */
   else {
      printf( "The queue is:\n" );

      /* while not end of queue */
      while ( currentPtr != NULL ) {
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } /* end while */

      printf( "NULL\n\n" );
   } /* end else */

} /* end function printQueue */
