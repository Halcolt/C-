#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

int addfirst(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
    if (tail == NULL)
    {
        tail = newnode;
    }
    return 0;
}

int addlast(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    if (tail != NULL)
    {
        tail->next = newnode;
    }
    tail = newnode;
    if (head == NULL)
    {
        head = newnode;
    }
    return 0;
}

struct Node *search(int value)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int RemoveValue(int value)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        return 0;
    }
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return 0;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp == head)
    {
        head = temp->next;
    }
    free(temp);
    return 0;
}

int reverse()
{
    struct Node *temp = NULL;
    struct Node *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
    return 0;
}

void printList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int addafter(int c, int v)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != c)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return 1;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = v;
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    if (newnode->next != NULL)
    {
        newnode->next->prev = newnode;
    }
    return 0;
}

int addbefore(int c, int v)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != c)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return 1;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = v;
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev = newnode;
    if (newnode->prev != NULL)
    {
        newnode->prev->next = newnode;
    }
    else
    {
        head = newnode;
    }
    return 0;
}

int main()
{
    int value, n, tmp, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        addlast(value);
    }

    while (1)
    {
        printList();
        printf("option: ");
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
        {
            break;
        }
        else if (strcmp(cmd, "addlast") == 0)
        {
            scanf("%d", &value);
            if (search(value) != NULL)
            {
                continue;
            }
            addlast(value);
        }
        else if (strcmp(cmd, "addfirst") == 0)
        {
            scanf("%d", &value);
            if (search(value) != NULL)
            {
                continue;
            }
            addfirst(value);
        }
        else if (strcmp(cmd, "addafter") == 0)
        {
            scanf("%d %d", &value, &tmp);
            if (search(value) != NULL)
            {
                continue;
            }
            addafter(tmp, value);
        }
        else if (strcmp(cmd, "addbefore") == 0)
        {
            scanf("%d %d", &value, &tmp);
            if (search(value) != NULL)
            {
                continue;
            }
            addbefore(tmp, value);
        }
        else if (strcmp(cmd, "remove") == 0)
        {
            scanf("%d", &value);
            RemoveValue(value);
        }
    }

    return 0;
}