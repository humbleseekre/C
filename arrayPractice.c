#include "stdio.h"
#include "stdlib.h"

//void manipulateArray(int *arr, int sizeofArray)
void manipulateArray(int arr[], int sizeofArray)
{
	int i;
	for(i = 0; i < sizeofArray; i++)
	{
		arr[i] = i;
	}
}

int main(void)
{
	int i;
	int array[5] = {0};
	manipulateArray(array, 5);
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", array[i]);
	}
	//getch();
	return 0;
}
