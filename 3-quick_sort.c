#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @hi: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int partition (int array[], int low, int hi, size_t size)
{
  int *pivot, i, j;

	pivot = &array[hi];
	for (i = j = low; j < hi; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(&array[i], pivot);
		print_array(array, size);
	}
  return (i);
}

/**
 * quickSort_L - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @hi: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void quickSort_Lomuto(int *array, int low, int hi, size_t size)
{
  int piv;
  
  if (low < hi)
    {
        piv = partition(array, low, hi, size);
        quickSort_Lomuto(array, low, piv - 1, size);
        quickSort_Lomuto(array, piv + 1, hi, size);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
  if (array == NULL || size < 2)
    return;
  quickSort_Lomuto(array, 0, size - 1, size);
}
