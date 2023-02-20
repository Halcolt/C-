#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

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

orders *makeNode(int n)
{
    orders *NewOrder = (orders *)malloc(sizeof(orders));
    NewOrder->A = (int *)malloc(sizeof(int) * n);
    NewOrder->next = NULL;
    return NewOrder;
}

void insert(orders *NewOrder, int tmp, int posi)
{
    NewOrder->A[posi] = tmp;
    return;
}

void Print_Bill(orders *NewOrder, int n, Menu data[])
{
    double bill = 0;
    for (int i = 0; i < n; i++)
    {
        data[i].in_stock = data[i].in_stock - NewOrder->A[i];
        bill = bill + (NewOrder->A[i] * data[i].price);
    }
    printf("Tong hoa don thanh toan: %.2f\n\n", bill);
    return;
}

void Find_favorite(int n)
{
    int fav_dish[n];
    memset(fav_dish, 0, sizeof(fav_dish));
    orders *NewOrder = makeNode(n);
    while (NewOrder != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            fav_dish[i] = fav_dish[i] + NewOrder->A[i];
        }
        NewOrder = NewOrder->next;
    }
}

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
    int n, choice, tmp = 0;
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
        printf("Tuy chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                // print the data
                printf("ID: %d, Ten mon: %s, So luong ton: %d, Gia Tien: %.2f\n\n", data[i].id, data[i].dish, data[i].in_stock, data[i].price);
            }
            break;
        case 2:
            if (setjmp(env) == 0)
            {
                printf("Goi mon\n");
                orders *NewOrder = makeNode(n);
                for (int i = 0; i < n; i++)
                {
                    tmp = 0;
                    while (tmp == 0)
                    {
                        printf("So luong ban muon cho mon %s: ", data[i].dish);
                        if (scanf("%d", &tmp) != 1)
                        {
                            free(NewOrder->A);
                            free(NewOrder);
                            longjmp(env, 1);
                        }
                        if (tmp < 0)
                        {
                            printf("So luong khong hop le\n");
                        }
                        insert(NewOrder, tmp, i);
                        if (tmp > data[i].in_stock)
                        {
                            printf("Nha hang khong du so luong suat an cho mon nay, vui long nhap lai order\n\n");
                            free(NewOrder->A);
                            free(NewOrder);
                            break;
                        }
                        if (tmp == 0)
                        {
                            i++;
                        }
                    }
                }

                if (head == NULL && tail == NULL)
                {
                    // if there is no order yet
                    tail = NewOrder;
                    head = NewOrder;
                }
                else
                {
                    // add the new order to the end of the list
                    tail->next = NewOrder;
                    tail = NewOrder;
                }
                Print_Bill(NewOrder, n, data);
                // printf("%s\t%d\t%.2f\n", data->dish, head->A[1], head->A[1] * data[1].price);
                break;
            }
            else
            {
                // Handle the error
                printf("Du lieu khong hop le\n\n");
                break;
            }

        case 3:
            tmp = 1;
            orders *NewOrder = makeNode(n);
            NewOrder = head;

            while (NewOrder != NULL)
            {
                printf("Thuc don thu %d\n", tmp);
                printf("Mon da chon\tSo luong\tThanh tien\n");
                for (int i = 0; i < n; i++)
                {
                    // printf("1");
                    if (NewOrder->A[i] != 0)
                    {
                        printf("%s\t%d\t\t%.2f\n", data->dish, NewOrder->A[i], NewOrder->A[i] * data[i].price);
                    }
                }
                Print_Bill(NewOrder, n, data);
                NewOrder = NewOrder->next;
                tmp++;
            }
            free(NewOrder);
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
