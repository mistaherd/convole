#include <stdio.h>
#include <stdlib.h>
#define ATMEGA8U2_CLKSEL_1 *((volatile unsigned char *)0xD1))

int main(){
	//int kernal[3][3]={{1,1,1},{0,2,1},{0,0,1}};
	int var =4;
	int *ptr=&var;
	ATMEGA8U2_CLKSEL_1 |=0x80;
	ATMEGA8U2_CLKSEL_1 &= ~(0x80);
	printf("address = %d",ptr);

	return 0;
}

