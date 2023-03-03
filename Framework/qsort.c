#include <stdio.h>
#include <stdlib.h>

// comparator function for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[] = {4, 2, 7, 1, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // sorting the array using qsort
    qsort(arr, n, sizeof(int), compare);
    // printing the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
