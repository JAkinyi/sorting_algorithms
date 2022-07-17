#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */

void selection_sort(int *array, size_t size)
{
  size_t i, j;
  int min,temp;
  
  for (i = 0; i < size; i++)
    {
      min = i;
      
      for (j = i + 1; j < size; j++)
        {
          if (array[j] < array[min])
          {
            min = j;
          }
        }
    
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    
        if (min != 0)
        { 
          print_array(array, size);
        }   
    }
}
