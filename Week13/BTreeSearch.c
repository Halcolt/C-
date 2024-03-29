#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100 // Size of the hash table

// https://www.youtube.com/watch?v=dMyhU07qcgs
typedef struct node
{
    char name[256];
    char email[256];
    struct node *left;
    struct node *right;
} node;

typedef struct HashTable
{
    node *address;
    struct HashTable *next;
} HashTable;

HashTable table[M];

int hash(char *s)
{
    int rs = 0;
    for (int i = 0; i < strlen(s); ++i)
        rs = (rs * 255 + s[i]) % M;
    return rs;
}

void insertMap(int index, node *newNode)
{
    // printf("%d-\n", index);
    HashTable *key = &table[index];
    while (key->next != NULL)
    {
        key = key->next;
    }
    // key = (HashTable *)malloc(sizeof(HashTable));
    key->address = newNode;
    key->next = NULL;
}

node *createNode(char name[], char email[])
{
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->left = NULL;
    newNode->right = NULL;
    int index = hash(name);
    insertMap(index, newNode);
    // printf("%s\n", table[index].address->name);
    //  printf("%d\n", index);
    return newNode;
}

node *insert(node *root, char name[], char email[])
{
    if (root == NULL)
    {
        return createNode(name, email);
    }
    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, email);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, email);
    return root;
}

node *Find(node *root, char name[])
{
    // print_hash_table();
    int index = hash(name);
    HashTable *key = &table[index];
    if (key->address == NULL)
    {
        return NULL;
    }

    while (key != NULL)
    {
        if (strcmp(key->address->name, name) == 0)
        {
            return key->address;
        }
        key = key->next;
    }
    return NULL;
}

node *minValueNode(node *tmp)
{
    node *current = tmp;

    while (current->left != NULL)
        current = current->left;
    return current;
}

node *Remove(node *root, char name[])
{
    if (root == NULL)
    {
        printf("Data not found\n");
        return root;
    }

    if (strcmp(name, root->name) < 0)
        root->left = Remove(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = Remove(root->right, name);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = minValueNode(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->email, temp->email);

        root->right = Remove(root->right, temp->name);
    }
    return root;
}

void print_hash_table()
{
    for (int i = 0; i < M; i++)
    {
        // printf("%d: ", i);
        HashTable *key = &table[i];
        if (key->address == NULL)
        {
            continue;
        }
        while (key != NULL)
        {
            printf("%s, %s\n", key->address->name, key->address->email);
            key = key->next;
        }
        // printf("NULL\n");
    }
}
int main()
{
    node *root = NULL;
    // insert(root, NULL, NULL);
    int value, n, tmp, count = 0;
    char name[256], email[256];

    while (1)
    {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0)
        {
            printf("Bye");
            return 0;
        }
        else if (strcmp(cmd, "Load") == 0)
        {
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%s %s", &name, &email);
                if (root == NULL)
                    root = insert(root, name, email);
                else
                    insert(root, name, email);
            }
        }
        else if (strcmp(cmd, "Remove") == 0)
        {
            scanf("%s", &name);
            Remove(root, name);
        }
        else if (strcmp(cmd, "Find") == 0)
        {
            scanf("%s", &name);
            if (root == NULL)
            {
                printf("Not found\n");
                continue;
            }
            node *tmp = Find(root, name);
            if (tmp == NULL)
            {
                printf("Not found\n");
                continue;
            }

            printf("%d %s\n", hash(name), tmp->email);
        }
        else if (strcmp(cmd, "Insert") == 0)
        {
            scanf("%s %s", &name, &email);
            insert(root, name, email);
        }
        else if (strcmp(cmd, "Print") == 0)
        {
            print_hash_table();
        }
    }
}
