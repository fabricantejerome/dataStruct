#include <stdio.h>

union integer
{
	char c;
	short int s;
	int i;
	long int b;

};

typedef union integer Number;

int main()
{
	Number Letter;

	scanf("%c",&Letter.c);
	//printf("Char: %c\n",Letter.c);
		printf("\nChar: %c\nShort: %hd\nInt: %d\nLong: %ld\n",Letter.c,Letter.s,Letter.i,Letter.b);
	scanf("%hd",&Letter.s);
	//printf("Short: %hd\n",Letter.s);
		printf("\nChar: %c\nShort: %hd\nInt: %d\nLong: %ld\n",Letter.c,Letter.s,Letter.i,Letter.b);
	scanf("%d",&Letter.i);
	//printf("Int: %d\n",Letter.i);
		printf("\nChar: %c\nShort: %hd\nInt: %d\nLong: %ld\n",Letter.c,Letter.s,Letter.i,Letter.b);
	scanf("%ld",&Letter.b);
	//printf("Long: %ld\n",Letter.b);
		printf("\nChar: %c\nShort: %hd\nInt: %d\nLong: %ld\n",Letter.c,Letter.s,Letter.i,Letter.b);
	
	printf("\nChar: %c\nShort: %hd\nInt: %d\nLong: %ld\n",Letter.c,Letter.s,Letter.i,Letter.b);
return 0;
}
