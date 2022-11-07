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
        {break;}
        char *B = (char *)realloc(A, sizeof(char)*(new_n+1));
        B[new_n] = n;
        new_n++;
        A = B;
    }
    printf("Mang sau khi da nhap la:\n");
    for (int i = 1; i < new_n; i++)         //A[0] = ????, A[i>new_n] = no char 
        {printf("%c", A[i]);}
 
    char s[7]; //for first char, no number have more than 6 digit
    int lock;
    int tmp; 
    for(int i = 1; i < new_n; i++)  //read first number
    {
        int x;     //for atoi
        if (A[i] == ' ')
        {
            tmp = i;
            x = atoi(s);
            lock = x;
            break;
        }
        s[i-1] = A[i];
    }
    
    printf("\n%d \n",lock);
//--------------------------------------------------------------

    int *B =(int *)malloc(sizeof(int)*(lock+2));
    int count = 0;
    int sum = 0;
   for(int i = tmp+1, j=0,x; i <= new_n,count < lock; i++)  //read first number
    {
        
        if (A[i] == ' '|| i == new_n)
        {
            x = atoi(s); 
            B[count] = x;printf("%d ",B[count]);
            j = 0;
            sum = sum + B[count];
            count++; 
            for(int k=0; k<7;k++)
            {
                s[k] = '\0';
            }
            continue;
        }
        s[j] = A[i];
        j++;
    }
    printf("%d\n",sum);
    B[count] = sum; //sum is last element of B[]
    for(int i = count,j = 0; i >= 0; )
    {
        if(i == j )
        {break;}
        i--;
        tmp = B[j];
        B[j] = B[i];
        B[i] = tmp;
        j++;
        if(i == (j+1))
        {break;}
    }
    for(int i = 0; i<=count; i++)
    {
        printf("%d ",B[i]);
    }
    int *ptr=B;
   fwrite(B,sizeof(int),count,p);
free(A);
free(B);
fclose(p);
}