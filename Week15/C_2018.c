#include <stdio.h>
#include <stdlib.h>

typedef struct Menu
{
    int id;
    char dish[255];
    int in_stock;
    double price;
} Menu;

typedef struct orders
{
    int *A;
    struct orders *next;
} orders;
orders *head = NULL, *tail = NULL;

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
        printf("Error opening file.\n");
        return 1;
    }
    int n, choice;
    // read the number of data lines
    fscanf(fp, "%d", &n);

    Menu data[n];
    for (int i = 0; i < n; i++)
    {
        // read one line of data
        fscanf(fp, "%d %s %d %lf", &data[i].id, &data[i].dish, &data[i].in_stock, &data[i].price);
    }

    fclose(fp);
    do
    {
        Option();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                // print the data
                printf("ID: %d, Ten mon: %s, So luong ton: %d, Gia Tien: %.2f\n", data[i].id, data[i].dish, data[i].in_stock, data[i].price);
            }
            break;
        case 2:
        goimon:
            printf("Goi mon\n");
            orders *NewOrder = (orders *)malloc(sizeof(orders));
            NewOrder->A = (int *)malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++)
            {
                int tmp = 0;
                printf("So luong ban muon cho mon %s: ", data[i].dish);
                scanf("%d", &tmp);
                NewOrder->A[i] = tmp;
                if (tmp > data[i].in_stock)
                {
                    printf("Nha hang ko du so luong suat an cho mon nay, vui long nhap lai order\n\n");
                    goto goimon;
                }
            }
            if (tail == NULL)
            {
                tail = NewOrder;
            }
            NewOrder->next = head;
            head = NewOrder;
            //&NewOrder = NULL;
            for (int i = 0; i < n; i++)
            {
                data[i].in_stock = data[i].in_stock - NewOrder->A[i];
            }
            free(NewOrder);
            break;

        case 3:
            printf("You chose option 3.\n");
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
