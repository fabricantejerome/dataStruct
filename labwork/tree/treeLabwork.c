/* Fig. 12.19: fig12_19.c
   Create a binary tree and traverse it 
   preorder, inorder, and postorder */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* self-referential structure */
struct treeNode { 
   struct treeNode *leftPtr;  /* pointer to left subtree */
   char *data; /* node value */
   struct treeNode *rightPtr; /* pointer to right subtree */
}; /* end structure treeNode */

typedef struct treeNode TreeNode; /* synonym for struct treeNode */
typedef TreeNode *TreeNodePtr; /* synonym for TreeNode* */

/* prototypes */
void insertNode( TreeNodePtr *treePtr, char *sPtr );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );

/* function main begins program execution */
int main()
{ 
   char *sentence = NULL;   
   char *tokenPtr;
   int size = 255;
   int last = 0;
   TreeNodePtr rootPtr = NULL; /* tree initially empty */

	last = getline( &sentence, &size, stdin );
	sentence[ last - 1 ] = '\0'; 	
	tokenPtr = strtok( sentence, " " );
	while( tokenPtr != NULL )
	{
		insertNode( &rootPtr, tokenPtr );
		tokenPtr = strtok( NULL, " " );
	}
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
   return 0; /* indicates successful termination */

} /* end main */

/* insert node into tree */
void insertNode( TreeNodePtr *treePtr, char *sPtr )
{ 
   
   /* if tree is empty */
   if ( *treePtr == NULL ) {   
      *treePtr = malloc( sizeof( TreeNode ) );

      /* if memory was allocated then assign data */
      if ( *treePtr != NULL ) { 
		 ( *treePtr )->data = malloc( sizeof( strlen( sPtr ) ) );
         strcpy( ( *treePtr )->data, sPtr );
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      } /* end if */
      else {
         printf( "%s not inserted. No memory available.\n", sPtr );
      } /* end else */
      
   } /* end if */
   else { /* tree is not empty */
      /* data to insert is less than data in current node */
      if ( sPtr < ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->leftPtr ), sPtr );
      } /* end if */

      /* data to insert is greater than data in current node */
      else if ( sPtr >= ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->rightPtr ), sPtr );
      } /* end else if */
   } /* end else */

} /* end function insertNode */

/* begin inorder traversal of tree */
void inOrder( TreeNodePtr treePtr )
{ 

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) { 
      inOrder( treePtr->leftPtr );
      printf( "%s", treePtr->data );
      inOrder( treePtr->rightPtr );
   } /* end if */

} /* end function inOrder */

/* begin preorder traversal of tree */
void preOrder( TreeNodePtr treePtr )
{ 

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) { 
      printf( "%s", treePtr->data );
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
      printf( "%s", treePtr->data );
   } /* end if */

} /* end function postOrder */

