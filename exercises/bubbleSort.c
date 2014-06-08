#include <stdio.h>

void swap(int *element1, int *element2);
void bubbleSort(int *const array, const int size);

int main(){
	int array[] = { 50, 16, 34, 48, 12, 8, 13 ,17, 47, 11, 9};
	int y;
	
	bubbleSort(array,11);
	for(y = 0; y < 11; y++){
		printf("%d ",array[ y ]);
	}
	printf("\n");
	return 0;
}
void bubbleSort(int *const array, const int size)
{
	int x = 0;
	int pass = 0;
	
	for(pass = 0; pass < size-1; pass++ ){
		for(x = 0; x < size-1; x++ )
		{
			if( array[ x ] > array[ x + 1 ] )
				swap( &array[ x ], &array[ x + 1 ]);
		}
	}
}
void swap(int *element1, int *element2){
	
	int hold = *element1;
	*element1 = *element2;
	*element2 = hold;
}
