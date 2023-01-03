#include <stdio.h>
#include<time.h> 

void swap(int* a, int* b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
} 

void bubbleSort(int arr[], int n) {
	int swapped;
	do{ 
		swapped = 0;
		for(int i = 0; i < n-1; i++){
			if(arr[i] > arr[i+1]){
				swap(&arr[i],&arr[i+1]);
				swapped = 1;
			}
		}
	}while(swapped == 1); 
}

int main(void)
{
	clock_t start, end;
	start = clock();
    FILE * f;
    int arr[100],n;
    
    f= fopen("arr-n.txt", "r");  
    printf("Input:\n");
    fscanf(f,"%d",&n);
    printf("%d\n",n);
   
    for(int i=0;i<n;i++) {
    	fscanf(f,"%d",&arr[i]); 
    	printf("%d ",arr[i]);
	} 
	
	bubbleSort(arr,n);
        printf("\nOutput:\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    fclose(f);
	end = clock();
   	printf("\nTime: %f\n", (double)(end-start)/CLOCKS_PER_SEC  );
   	return 0; 

}
