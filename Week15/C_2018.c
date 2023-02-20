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
            // Set jump point if tmp is invalid
            {
                printf("Goi mon\n");
                orders *NewOrder = (orders *)malloc(sizeof(orders));
                NewOrder->A = (int *)malloc(sizeof(int) * n);
                NewOrder->next = NULL;
                // bug appear here, create node have to put into function or head will move with the node
                for (int i = 0; i < n; i++)
                {
                    tmp = 0;
                    while (tmp == 0)
                    {
                        printf("So luong ban muon cho mon %s: ", data[i].dish);
                        // fflush(stdin);
                        if (scanf("%d", &tmp) != 1)
                        {
                            // If scanf fails, jump back to the setjmp point
                            free(NewOrder);
                            longjmp(env, 1);
                        }
                        if (tmp < 1)
                        {
                            printf("So luong khong hop le");
                        }
                    }
                    NewOrder->A[i] = tmp;
                    if (tmp > data[i].in_stock)
                    {
                        printf("Nha hang ko du so luong suat an cho mon nay, vui long nhap lai order\n\n");
                        break;
                    }
                }
                // printf("%s\t%d\t%.2f\n", data->dish, head->A[1], head->A[1] * data[1].price);
                if (head == NULL)
                {
                    tail = NewOrder;
                    head = NewOrder;
                    printf("+!\n");
                }
                else
                {
                    tail->next = NewOrder;
                    tail = NewOrder;
                }
                double bill = 0;
                for (int i = 0; i < n; i++)
                {
                    data[i].in_stock = data[i].in_stock - NewOrder->A[i];
                    bill = bill + (NewOrder->A[i] * data[i].price);
                }
                printf("Tong hoa don: %.2f\n\n", bill);
                printf("%s\t%d\t%.2f\n", data->dish, head->A[1], head->A[1] * data[1].price);
                free(NewOrder);
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
            orders *NewOrder = (orders *)malloc(sizeof(orders));
            NewOrder->A = (int *)malloc(sizeof(int) * n);
            NewOrder = head;
            printf("%s\t%d\t%.2f\n", data->dish, head->A[1], head->A[1] * data[1].price);
            /*
            while (NewOrder != NULL)
            {
                printf("Thuc don thu %d\n", tmp);
                printf("Mon da chon\tSo luong\tThanh tien\n");
                for (int i = 0; i < n; i++)
                {
                    // printf("1");
                    if (NewOrder->A[i] != 0)
                    {
                        printf("%s\t%d\t%.2f\n", data->dish, NewOrder->A[i], NewOrder->A[i] * data[i].price);
                    }
                }
                NewOrder = NewOrder->next;
                tmp++;
            }*/
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