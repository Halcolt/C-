#include<stdio.h>
typedef struct pbook
{
    char name[100];
    int phonenum;
    char email[100];
    char address[100];
} pbook_t;

int main()
{
    pbook_t info[100];
    p = fopen("Phonebook.txt","w+");
    printf("Nhap so luong thong tin nguoi dung: ");
    int a;
    scanf("%s",&a);
    for (int i=0; i<a; i++)
    {
        printf("Nhap ten nguoi thu %d: ",i+1);
        scanf("%c", info->name);
        printf("Nhap SDT nguoi thu %d: ",i+1);
        scanf("%d", info->phonenum);
        printf("Nhap email nguoi thu %d: ",i+1);
        scanf("%c", info->email);
        printf("Nhap dia chi nguoi thu %d: ",i+1);
        scanf("%c", info->address);
        printf("----------------------------------\n");
    }
    fwrite()
    fclose(p)
}