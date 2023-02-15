#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// https://www.youtube.com/watch?v=dMyhU07qcgs
typedef struct node
{
    char name[256];
    char email[256];
    struct node *left;
    struct node *right;
} node;

node *createNode(char name[], char email[])
{
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, char name[], char email[])
{
    if (root == NULL)
        return createNode(name, email);

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, email);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, email);

    return root;
}

node *Find(node *root, char name[])
{
    if (root == NULL || strcmp(root->name, name) == 0)
    {
        return root;
    }

    if (strcmp(name, root->name) < 0)
        return Find(root->left, name);
    else
        return Find(root->right, name);
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

void print_tree(node *root)
{
    if (root != NULL)
    {
        print_tree(root->left);
        printf("Name: %s, Email: %s\n", root->name, root->email);
        print_tree(root->right);
    }
}

int main()
{
    node *root = NULL;
    int value, n, tmp, count = 0;
    char name[256], email[256];

    while (1)
    {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0)
        {
            printf("Bye\n");
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
            // print_tree(root);
        }
        else if (strcmp(cmd, "Remove") == 0)
        {
            scanf("%s", &name);
            Remove(root, name);
        }
        else if (strcmp(cmd, "Find") == 0)
        {
            scanf("%s", &name);
            node *tmp = Find(root, name);
            if (tmp == NULL)
            {
                // printf("Not Found");
                continue;
            }
            printf("%s \n", tmp->email);
        }
        else if (strcmp(cmd, "Print") == 0)
        {
            print_tree(root);
        }
        }
    return 0;
}
