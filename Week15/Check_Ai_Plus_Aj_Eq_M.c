#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int count_pairs(int A[], int n, int M)
{
    int count = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (A[i] + A[j] == M)
        {
            count++;
            i++;
            j--;
        }
        else if (A[i] + A[j] < M)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return count;
}

int main()
{
    int n, M;
    scanf("%d %d", &n, &M);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, n, sizeof(int), compare_ints);
    int count = count_pairs(A, n, M);
    printf("%d\n", count);
    return 0;
}
