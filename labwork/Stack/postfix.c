#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct stackNode{
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void convertToPostFix( char infix[], char postfix[] );
int isOperator( char c );
int precedence( char operator1, char operator2 );
void push( StackNodePtr *topPtr, char value );
char pop( StackNodePtr *topPtr );
StackNodePtr stackTop( StackNodePtr *topPtr );
int isEmpty( StackNodePtr currentPtr );
void printStack( StackNodePtr topPtr );

int main(){
	char infix[ 255 ];
	char postfix[ 255 ];
	char c;
	int i  = 0;
	
	while( ( c = getchar() ) != '\n' )
	{
		infix[ i ] = c;
		i++;
	}
	convertToPostFix( infix, postfix );
	postfix[ strlen(postfix) +1] = '\0';
	printf("%s\n", postfix );
return 0;
}// end main function

void push( StackNodePtr *topPtr, char value )
{
   StackNodePtr newPtr; /* pointer to new node */

   newPtr = malloc( sizeof( StackNode ) );

   /* insert the node at stack top */
   if ( newPtr != NULL ) {
      newPtr->data = value;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
   } /* end if */
   else { /* no space available */
      printf( "%c not inserted. No memory available.\n", value );
   } /* end else */

} /* end function push */
char pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr;
	char popValue;

	tempPtr = *topPtr;
	popValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr);

	return popValue;
}// end of function
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
         printf( "%c --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } /* end while */

      printf( "NULL\n\n" );
   } /* end else */

} /* end function printList */
int isEmpty( StackNodePtr currentPtr )
{
	return currentPtr == NULL;
}// end of function isEmpty
int isOperator( char c )
{
	char *validOperators = "+-%*/^	";

	if( strchr( validOperators, c ) )
	{
		return 1;
	}
	else{
		return 0;
	}
}// end function
int precedence( char operator1, char operator2 )
{
	char opValue1 = 0;
	char opValue2 = 0;
	if( isOperator( operator1) && isOperator( operator2 ) )
	{
		switch( operator1 )
		{
			case '^':
				opValue1 = 3;
				break;
			case '*':
			case '/':
			case '%':
				opValue1 = 2;
				break;
			case '+':
			case '-':
				opValue1 = 1;
				break;
		}
		switch( operator2 )
		{
			case '^':
				opValue2 = 3;
				break;
			case '*':
			case '/':
			case '%':
				opValue2 = 2;
				break;
			case '+':
			case '-':
				opValue2 = 1;
				break;
		}// end case;
		if( opValue1 < opValue2 )
			return -1;
		else if( opValue1 > opValue2 )
			return 1;
		else
			return 0;
	}// end if;
}// end function
StackNodePtr stackTop( StackNodePtr *topPtr )
{
	return *topPtr;
}
void convertToPostFix( char infix[], char postfix[] )
{
	StackNodePtr stackPtr = NULL;
	char temp;
	int infixIndicator = 0;
	int postfixIndicator = 0;
	push( &stackPtr, '(' );
	strcat( infix, ")" );
	while( !isEmpty( stackPtr ) )
	{
		if( isdigit( infix[ infixIndicator ] ) )
		{
			postfix[ postfixIndicator ++ ] = infix[ infixIndicator ];
		}
		else if( infix[ infixIndicator ] == '(' )
		{
			push( &stackPtr, infix[ infixIndicator ] );
		}
		else if( isOperator( infix[ infixIndicator ] ) )
		{
			temp = ( stackTop( &stackPtr ) )->data;
			while( isOperator(temp) && ( precedence( temp, infix[ infixIndicator ] ) >= 0 ) )
			{
				postfix[ postfixIndicator ] = pop(&stackPtr);
				postfixIndicator++;
				temp = ( stackTop(&stackPtr ) )->data;
			}
			push( &stackPtr, infix[ infixIndicator ] );
		}
		else if( infix[ infixIndicator ] == ')' )
		{
			temp = pop( &stackPtr );
			while( temp != '(' ) 
			{
				postfix[ postfixIndicator++ ] = temp;
				temp = pop( &stackPtr );
			}
		}	
		infixIndicator++;
	}
}// end function


