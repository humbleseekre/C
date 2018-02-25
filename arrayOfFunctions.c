#include "stdio.h"

typedef void (*ptr)(void);

void functionA(void)
{
	printf("Print A\n");
}

void functionB(void)
{
	printf("Print B\n");
}

void functionC(void)
{
	printf("Print C\n");
}

void functionD(void)
{
	printf("Print D\n");
}

void functionE(void)
{
	printf("Print E\n");
}

ptr arr[] = {&functionA, &functionB, &functionC, &functionD, &functionE};

int main(void)
{
	int i;
	printf("Hello World\n");
	for(i=0; i < 5; i++)
	{
		arr[i]();
	}
	return 0;
}

