#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void Option()
{
    printf("Menu:\n");
    printf("1. Danh sach mon an hom nay \n");
    printf("2. Nhan Order (yeu cau dat mon) \n");
    printf("3. Thong tin tat ca order \n");
    printf("4. Mon an ua chuong nhat \n");
    printf("5. Thoat\n");
}

int main()
{
    FILE *fp = fopen("thucdontheongay.txt", "r+");
    if (fp == NULL)
    {
        printf("Loi mo file.\n");
        return 1;
    }

    do
    {
        Option();
        printf("Tuy chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Goodbye!\n");
            break;
        case 2:
            printf("Goodbye!\n");
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        case 5:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);
    return 0;
}
