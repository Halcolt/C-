#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

int addfirst(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return 0;
}

int addlast(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return 1;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
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
    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

int reverse()
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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
    struct Node *curr = head;
    while (curr != NULL && curr->data != c)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return 1;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = v;
    newnode->next = curr->next;
    curr->next = newnode;
    return 0;
}

int addbefore(int c, int v)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr != NULL && curr->data != c)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return 1;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = v;
    newnode->next = curr;
    if (prev == NULL)
    {
        head = newnode;
    }
    else
    {
        prev->next = newnode;
    }
    return 0;
}

void find(int value)
{
    if (search(value) != NULL)
    {
        printf("Found\n");
    }
    else
    {
        printf("NotFound\n");
    }
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
        else if (strcmp(cmd, "search") == 0)
        {
            scanf("%d", &value);
            find(value);
        }
    }
    return 0;
}