#include <stdio.h>

int double_add1(int a, int b){
	
return (a+b)*2;
} 
int double_add2(int *a, int *b){
	*a = *a*2;
	*b = *b*2;
return *a+*b;
}

int main()
{
	int a, b, x;
	a = 5;
	b = 10;
	x = double_add1(a,b);
	printf("%d + %d = %d\n",a, b ,x);
	x = double_add2(&a,&b);
	printf("%d + %d = %d\n",a, b, x);
	
return 0;
}
