#include<stdio.h>
#include<stdlib.h>
int A[100000],B[100000];
void merge(int A[], int L, int M, int R){
    int i = L, j = M + 1;
    for(int k = L; k <= R; k++){
        if(i > M){
            B[k] = A[j];
            ++j;
        }
        else if(j > R){
            B[k] = A[i];
            ++i;
        }
        else{
            if(A[i] < A[j]){
                B[k] = A[i];
                ++i;
            }
            else{
                B[k] = A[j];
                ++j;
            }
        }
    }
    for(int k = L; k <= R; k++){
        A[k] = B[k];
    }
}

void mergeSort(int A[], int L, int R){
    if(L < R){
        int M = (L + R)/2;
        mergeSort(A,L,M);
        mergeSort(A,M + 1,R);
        merge(A,L,M,R);
    }
}

int main() {
    int n;
    //nhap so luong
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}