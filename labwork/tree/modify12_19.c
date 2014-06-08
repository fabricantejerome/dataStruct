/* Fig. 12.19: fig12_19.c
   Create a binary tree and traverse it
   preorder, inorder, and postorder */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* self-referential structure */
struct treeNode {
   struct treeNode *leftPtr;  /* pointer to left subtree */
   int data; /* node value */
   struct treeNode *rightPtr; /* pointer to right subtree */
}; /* end structure treeNode */

typedef struct treeNode TreeNode; /* synonym for struct treeNode */
typedef TreeNode *TreeNodePtr; /* synonym for TreeNode* */

#include "queue.h"

/* prototypes */
void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );
void deleteNode( TreeNodePtr *rootPtr, int value );
TreeNodePtr search( TreeNodePtr *rootPtr, int value );
void traverse( TreeNodePtr *rootPtr );
void outputTree( TreeNodePtr rootPtr, int totalSpace );

/* function main begins program execution */
int main()
{
   int i; /* counter to loop from 1-10 */
   int item = 0; /* variable to hold random values */
   int choice;
   TreeNodePtr rootPtr = NULL; /* tree initially empty */

   srand( time( NULL ) );
   printf( "The numbers being placed in the tree are:\n" );

   /* insert random values between 1 and 15 in the tree */
   for ( i = 1; i <= 15; i++ ) {
      item = rand() % 15;
      printf( "%3d", item );
      insertNode( &rootPtr, item );
   } /* end for */
   printf( "\nPress 1 Delete\nPress 2 Search\nPress 3 Level order Traversal\nPress 4 PrintTrees\nPress 0 Exit\n" );
   printf("\nEnter your choice: ");
   scanf( "%d", &choice );
   while( choice != 0 )
   {
		switch( choice )
		{
		  case 1:
				printf("\nEnter the number you want to delete: \n");
				scanf( "%d", &item );
				deleteNode( &rootPtr, item );
			   /* traverse the tree preOrder */
			   printf( "\n\nThe preOrder traversal is:\n" );
			   preOrder( rootPtr );

			   /* traverse the tree inOrder */
			   printf( "\n\nThe inOrder traversal is:\n" );
			   inOrder( rootPtr );

			   /* traverse the tree postOrder */
			   printf( "\n\nThe postOrder traversal is:\n" );
			   postOrder( rootPtr );
			   printf("\n");
			  break;
		case 2:
			printf("Enter a number would you like to find: ");
			scanf( "%d", &item );
			if( search( &rootPtr, item )  )
				printf( "Node pointer: %p\nNode value: %d\n", search( &rootPtr, item ), item );
			else
				printf("Node can't find!\n");
			break;
		case 3:
			traverse( &rootPtr );
			break;
		case 4:
			outputTree( rootPtr, 0 );
			break;
		default:
			printf( "Invalid choice!\n " );
			break;
		}
	   printf( "\nPress 1 Delete\nPress 2 Search\nPress 3 Level order Traversal\nPress 4 PrintTrees\nPress 0 Exit\n" );
	   printf("\nEnter your choice: ");
	   scanf( "%d", &choice );
   }
   return 0; /* indicates successful termination */

} /* end main */

/* insert node into tree */
void insertNode( TreeNodePtr *treePtr, int value )
{

   /* if tree is empty */
   if ( *treePtr == NULL ) {
      *treePtr = malloc( sizeof( TreeNode ) );

      /* if memory was allocated then assign data */
      if ( *treePtr != NULL ) {
         ( *treePtr )->data = value;
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      } /* end if */
      else {
         printf( "%d not inserted. No memory available.\n", value );
      } /* end else */

   } /* end if */
   else { /* tree is not empty */

      /* data to insert is less than data in current node */
      if ( value < ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->leftPtr ), value );
      } /* end if */

      /* data to insert is greater than data in current node */
      else if ( value >= ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->rightPtr ), value );
      } /* end else if */
   } /* end else */

} /* end function insertNode */

/* begin inorder traversal of tree */
void inOrder( TreeNodePtr treePtr )
{

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) {
      inOrder( treePtr->leftPtr );
      printf( "%3d", treePtr->data );
      inOrder( treePtr->rightPtr );
   } /* end if */

} /* end function inOrder */

/* begin preorder traversal of tree */
void preOrder( TreeNodePtr treePtr )
{

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) {
      printf( "%3d", treePtr->data );
      preOrder( treePtr->leftPtr );
      preOrder( treePtr->rightPtr );
   } /* end if */

} /* end function preOrder */

/* begin postorder traversal of tree */
void postOrder( TreeNodePtr treePtr )
{

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) {
      postOrder( treePtr->leftPtr );
      postOrder( treePtr->rightPtr );
      printf( "%3d", treePtr->data );
   } /* end if */

} /* end function postOrder */
void deleteNode( TreeNodePtr *rootPtr, int value )
{
	TreeNodePtr *parentPtr = rootPtr;
	TreeNodePtr currentPtr = *rootPtr;
	TreeNodePtr delNode = NULL;

    while( currentPtr ) // while currentPtr is not NULL
	{
		if( value > currentPtr->data ) // if value is greater than currentData
		{
			parentPtr = &( currentPtr->rightPtr ); // assign the address of currentRightPtr to parentPtr
			currentPtr = currentPtr->rightPtr; // assign currentPtrRightPtr = currentPtr
		}
		else if( value < currentPtr-> data ) // if value is less than currentData
		{
			parentPtr = &( currentPtr->leftPtr ); //assign the address of currentRighPtr to parentPtr
			currentPtr = currentPtr->leftPtr; // assign currentPtrLeft to currentPtr
		}
		else
		{
			break; // if the value is found or not
		}
	}
	if( !currentPtr )
		return; // if the value is not found

	delNode = currentPtr; // assign currentPtr to delNode

    if( !( currentPtr->leftPtr && currentPtr->rightPtr ) ) // if the currentPtrLeft is not null; or currentPtrRight is not null either.
	{
		if( currentPtr->leftPtr ) // if currenPtrLeft is not null
			*parentPtr = currentPtr->leftPtr; // assign currenPtrLeft to *parentPtr
		else
			*parentPtr = currentPtr->rightPtr; // assign currentrPtrRight to *parentPtr
	}
	else
	{
		TreeNodePtr *parent2 = &( currentPtr->rightPtr ); // if it has two children
		currentPtr = currentPtr->rightPtr;
		while( currentPtr->leftPtr )
		{
			parent2 = &( currentPtr->leftPtr );
			currentPtr = currentPtr->leftPtr;
		}
		if( currentPtr->rightPtr )
			*parent2 = currentPtr->rightPtr;
		else
			*parent2 = NULL;

		*parentPtr = currentPtr;
		currentPtr->rightPtr = delNode->rightPtr;
		currentPtr->leftPtr = delNode->leftPtr;
	}
	free( delNode );
}// end of function deleteNode
TreeNodePtr search( TreeNodePtr *rootPtr, int value )
{
	if( !*rootPtr )
	{
		return NULL;
	}
	else
	{
		while( *rootPtr )
		{
			if( value > ( *rootPtr )->data )
				*rootPtr = ( *rootPtr )->rightPtr;
			else if( value < ( *rootPtr )->data )
				*rootPtr = ( *rootPtr )->leftPtr;
			else
				break;
		}
		if( !*rootPtr )
			return NULL;
		else if( value == ( *rootPtr )->data )
			return *rootPtr;
		else
			return NULL;
	}
}
void traverse( TreeNodePtr *rootPtr )
{

	TreeNodePtr traversePtr = *rootPtr;
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;

	enqueue( &headPtr, &tailPtr ,*rootPtr );
	while( headPtr )
	{
		printf( "%d ",( traversePtr = dequeue( &headPtr, &tailPtr ) )->data );
		if( traversePtr->leftPtr )
		{
			enqueue( &headPtr, &tailPtr, traversePtr->leftPtr );
			traversePtr->leftPtr = traversePtr->leftPtr;
		}
		if( traversePtr->rightPtr )
		{
			enqueue( &headPtr, &tailPtr, traversePtr->rightPtr );
			traversePtr->rightPtr = traversePtr->rightPtr;
		}
	}
	printf( "\n" );
}
void outputTree( TreeNodePtr rootPtr, int totalSpace )
{
	int count = 0;
	while( rootPtr )
	{
		outputTree( rootPtr->rightPtr, totalSpace + 5 );
		for( count = 0; count < totalSpace; count++ )
		{
			printf(" ");
		}
		printf( "%d\n", rootPtr->data );
		rootPtr = rootPtr->leftPtr;
		totalSpace += 5;
	}
}
