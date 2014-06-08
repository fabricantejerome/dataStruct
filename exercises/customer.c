/*
 * Structure in C  equal to Classes in  C++
 */
#include <stdio.h>

struct customer{
	char lastName[15];
	char firstName[15];
	int customerNumber;
	
	struct{
		char phoneNumber[11];
		char address[50];
		char city[15];
		char state[3];
	}personal; 
}customerRecord, *customerPtr;


int main(){
	customerPtr = &customerRecord;
	
	printf("Enter your last name: ");
	scanf("%s",customerRecord.lastName);
	
	printf("Enter your first name: ");
	scanf("%s",customerRecord.firstName);
	
	printf("Enter your customer number: ");
	scanf("%d",&customerRecord.customerNumber);
	
	printf("Phone number: ");
	scanf("%s",customerRecord.personal.phoneNumber);
	
	printf("Enter your address: ");
	scanf("%s",customerRecord.personal.address);
	
	printf("Enter your city: ");
	scanf("%s",customerRecord.personal.city);
	
	printf("\nLast Name:%s\nFirst Name:%s\nCustomer Number:%d\nPhone number:%s\nAddress:%s\nCity:%s\n\n",customerPtr->lastName, customerPtr->firstName, customerPtr->customerNumber, customerPtr->personal.phoneNumber, customerPtr->personal.address, customerPtr->personal.city);
	
return 0;
}
