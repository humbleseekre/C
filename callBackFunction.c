#include "stdio.h"

void A(void)
{
	printf("I am function A\n");
}

void B(void (*ptr)())
{
	(*ptr)();
}

int main(void)
{
	void (*ptr)() = &A;

	//calling function B and pasing address of
	// the function as an argument
	B(ptr);

	return 0;
}
