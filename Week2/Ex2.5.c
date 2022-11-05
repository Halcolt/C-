#include<stdio.h>
#include<stdlib.h>
typedef struct pbook
{
    char name[30];
    char phonenum[15];
    char email[30];
    char address[30];
} pbook_t;

int main()
{
    FILE *p;
    pbook_t info[100];
    p = fopen("Phonebook.txt","w+");
    printf("Nhap so luong thong tin nguoi dung: ");
    int a;
    scanf("%d",&a);
    printf("----------------------------------\n");
    for (int i=0; i<a; i++)
    {
        printf("\nNhap ten nguoi thu %d: ",i+1);
        scanf("%s", &info[i].name);
        printf("Nhap SDT nguoi thu %d: ",i+1);
        scanf("%s", &info[i].phonenum);
        printf("Nhap email nguoi thu %d: ",i+1);
        scanf("%s", &info[i].email);
        printf("Nhap dia chi nguoi thu %d: ",i+1);
        scanf("%s \n", &info[i].address);
        printf("----------------------------------\n");
    }

    fwrite(info, a, sizeof(pbook_t), p);
    fclose(p);
}