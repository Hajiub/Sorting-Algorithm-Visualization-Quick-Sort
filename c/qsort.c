#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int low, int high)
{
    int piv, i, j;
    piv = array[high];
    j = low - 1;
    for (i = low; i < high; i++)
    {
        if (piv >= array[i])
        {
            j++;
            // swap
            swap(&array[i], &array[j]);
        }
    }
    j++;
    swap(&array[j], &array[high]);
    return j;
}

void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int piv = partition(array, low, high);

        quicksort(array, low, piv - 1);
        quicksort(array, piv + 1, high);
    }
}

int main()
{
    int array[] = {45, 87, 131, 879, 456, 123, 100, 21, 5, 41, 12, 69, 75, 40};
    int size;
    size = sizeof(array)/sizeof(array[0]) - 1;
    quicksort(array, 0, size - 1);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);        
    }
    putchar('\n');

}