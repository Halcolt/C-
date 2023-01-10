#include "stdio.h"
#include "stdlib.h"

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int A[], int i, int N)
{
    int L = 2*i;
	int R = 2*i+1;
	int max = i;
	if(L <= N && A[L] > A[i]) max = L;
	if(R <= N && A[R] > A[max]) max = R;
	if(max != i){ 
	    int temp = A[i];
		A[i] = A[max];
		A[max] = temp;
		heapify(A,max,N);
	}
}
void buildHeap(int A[], int N) {
    for(int i = N/2; i >= 0; i--)
	heapify(A,i,N);
}

void heapSort(int A[], int N) {
    buildHeap(A,N);
	for(int i = N; i > 0; i--) {
	    int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapify(A, 0, i-1); 
	}
}
int main() {
    int n,A[100000];
    //nhap so luong
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&A[i]);
    }
    heapSort(A,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}