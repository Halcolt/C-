#include<stdio.h>
#include<string.h>

int Replace(char str[100], char c1, char c2)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c1)
        {
            str[i] = c2;
        }
    }
    printf("\nChuoi moi la: %s\n",str);
}

int main()
{
    char str[100];
    char c1;
    char c2;

    printf("Nhap chuoi: ");
    fgets(str, 100, stdin);

    printf("\nNhap ki tu can thay doi: ");
    c1 = getchar();
    getchar();
    printf("\nThay bang ki tu: ");
    c2 = getchar();

    Replace(str,c1,c2);
}