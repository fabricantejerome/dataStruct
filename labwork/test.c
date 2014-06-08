#include "postfix.c"

int main()
{
	char infix[] = "+*^";
	StackNodePtr stackPtr = NULL;
	
	push( &stackPtr, '(');
	
	printf("%c",( stackTop( &stackPtr ) )->data);
	printf("%c", pop( &stackPtr ));
	
}
