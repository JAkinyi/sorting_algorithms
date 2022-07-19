#include sort.h

void swap(int a, int b)
{
  int tmp;

  tmp = a;
  a = b;
  b = tmp;
}

void quick_sort(int *array, size_t size)
{
  if (size < 2)
    return;
  quickSort(array, 0, size - 1, size);
}

int partition (int array[], int hi, int low)
{
  int pivot = array[hi];
  int i = low - 1;
  int j;

  for (j = low; j < hi; j++)
    {
      if (array[j] <= pivot)
      {
        i++;
        swap(array[i], array[j]);
      }
    }
  swap(array[i + 1], array[hi]);
  return (i + 1); 
}

void quickSort(int *array, int low, int hi, size_t size)
{
  if (low < hi)
    {
        int pi = partition(array, low, hi);
        quickSort(array, low, pi - 1, size);
        quickSort(array, pi + 1, hi, size);
    }
}
