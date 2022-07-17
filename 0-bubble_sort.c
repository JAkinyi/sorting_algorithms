#include "sort.h"

void swap(int* xp, int* yp) 
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	i = 0;

	if (size < 2)
		return;

	while (i < size - 1)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
		i++;
	}
}
