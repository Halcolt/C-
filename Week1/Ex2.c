#include<stdio.h>
#include<string.h>

int IfEqual(int a[], int b[],int x, int y)
{

    if (x != y)
    {return 0;}
    for (int i = 0; i < x; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
        
    }
    return 1;
    
}

int main()
{
    int a[100],b[100];
    printf("Nhap so phan tu mang a");
    int x,y;
    scanf("%d",&x);
    for (int i = 0; i < x; i++)
    {
        printf("Nhap phan tu thu %d cua mang a: ", i+1);
        scanf("%d",&a[i]);
    }
    
    printf("Nhap so phan tu mang b");
    scanf("%d",&y);
    for (int i = 0; i < y; i++)
    {
        printf("Nhap phan tu thu %d cua mang b: ", i+1);
        scanf("%d",&b[i]);
    }
    if (IfEqual(a,b,x,y) == 1)
    {printf("2 mang giong nhau\n");}
}