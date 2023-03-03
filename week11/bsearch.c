#include "stdio.h"
#include "stdlib.h"
int A[1000000], n, q, cnt;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int A[], int L, int R, int indexPivot)
{
    int pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    for (int i = L; i <= R - 1; i++)
    {
        if (A[i] < pivot)
        {
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(int A[], int L, int R)
{
    if (L < R)
    {
        int index = (L + R) / 2;
        index = partition(A, L, R, index);
        if (L < index)
            quickSort(A, L, index - 1);
        if (index < R)
            quickSort(A, index + 1, R);
    }
}

int binarySearch(int u, int v, int k)
{
    int l = u, r = v;
    int mid = (l + r) / 2;
    while (l != mid && r != mid)
    {
        if (A[mid] >= k)
            r = mid;
        else
            l = mid;
        mid = (l + r) / 2;
    }
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (A[i] == k)
            cnt++;
    }
    return cnt;
}
void binarySearchSolve()
{
    quickSort(A, 0, n - 1);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int ok = binarySearch(i + 1, n, q - A[i]);
        cnt += ok;
    }
    printf("%d\n", cnt);
}

int main()
{

    // nhap so luong
    scanf("%d", &n);
    // nhap tong
    scanf("%d", &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    quickSort(A, 0, n - 1);
    binarySearchSolve();

    return 0;
}