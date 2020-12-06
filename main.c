#include <stdio.h>
#include "common.h"


int main(void)
{
	int a = 10;
	int b = 5;
	//call funktion from lib
	
	int c = add(a, b);

	printf("number is: %d\n", c);
}


