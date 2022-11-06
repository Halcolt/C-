#include<stdio.h>

int detail(double a)
{
    int b;
    float c;
    b = a/1;
    c = a-b;
    printf("Phan nguyen la: %d \n Phan thap phan la: %f\n",b,c);
    return 0;
}

int main()
{
    printf("Nhap 1 so thap phan: ");
    double a;
    scanf("%lf",&a);
    detail(a);
}