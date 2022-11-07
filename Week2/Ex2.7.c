#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
    FILE *p;
    p = fopen("out.txt","w");
    char *A = (char *)malloc(sizeof(char));
    char n;
    int new_n = 1;          //newchar
    printf("Mang: ");
    while (1 == 1) 
        {
        scanf("%c", &n);
        if (n == '\n')
        break;
        char *B = (char *)realloc(A, sizeof(char)*(new_n));
        B[new_n] = n;
        new_n++;
        A = B;
    }
    
    printf("Mang sau khi da nhap la:\n");
    for (int i = 1; i < new_n; i++)         //A[0] = ????, A[i>new_n] = no char 
        printf("%c", A[i]);
}