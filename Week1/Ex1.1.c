#include<stdio.h>

int main()
{
    printf("Nhap chuoi: ");
    char str[100];
    fgets(str, 100, stdin);

    printf("Nhap ki tu can dem: ");
    char c;
    scanf("%c",&c);

    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (str[i] == c)
        {
            count++;
        }
    }
    printf("So lan ki tu d xuat hien la %d \n", count);
}