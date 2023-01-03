#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int A[], int N) {
// index tu 1 -> N
    for(int k = 1 ; k < N; k++){
        int last = A[k];
        int j = k;
        while(j > 0 && A[j-1] > last){
            A[j] = A[j-1];
            j--; 
        }
    A[j] = last;
    } 
}

int main(){
    int n,arr[50];
    FILE *p = fopen("input.txt","r");

    printf("So phan tu:");
    fscanf(p,"%d",&n);
    printf("%d",n);

    printf("\nDay nhap vao:\n");
    for (int i=0; i<n; i++) {
        fscanf(p,"%d ",&arr[i]);
        printf("%d ",arr[i]);
    }
 
    insertionSort(arr,n);
    printf("\nresult:\n");
    for (int i=0;i<n;i++) 
        printf("%d ",arr[i]);

    fclose(p);
}