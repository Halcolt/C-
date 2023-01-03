#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void SelectionSort(int a[], int n){
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for (int j = i+1; j<n; j++){
            if (a[j]<a[min]){ 
                min = j;
            }
        }
        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
        
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
 
    SelectionSort(arr,n);
    printf("\nresult:\n");
    for (int i=0;i<n;i++) 
        printf("%d ",arr[i]);

    fclose(p);
}