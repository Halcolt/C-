#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    float a,b;
    a = atof(argv[1]); 
    b = atof(argv[2]);
    printf("Chu vi la: %f\n", 2*a+2*b);
    printf("Dien tich la: %f\n", a*b);
}