#include <stdio.h>

void displayBits( unsigned number );

int main(){
	unsigned number;//initialize
	
	printf("Enter a number: ");
	scanf("%u",&number);
	
	displayBits( number ); 
	printf(" 4 bits positions using the ");
	printf("right shift operator >> is\n");
	displayBits( number >> 4);
	
	putchar('\n');
	
	displayBits( number ); 
	printf(" 4 bits positions using the ");
	printf("left shift operator << is\n");
	displayBits( number << 4);

	
	return 0;//indicate the program ended successfully
}//end of main function

void displayBits( unsigned number ){
	unsigned c;
	
	unsigned displayMask = 1 << 15;
	printf("%7u = ",number);
	
	for( c = 1; c <= 16; c++){
		putchar(number & displayMask ? '1' : '0');
		number <<= 1;//shift value left by 1
		
		if( c % 8 == 0){
			putchar(' ');
		}//end if
	}//end for
	putchar('\n');
}//end of function displayBits
