#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree
{
    int id;
    struct Tree *left;
    struct Tree *right;
} Tree;
Tree *root;

Tree *newNode(int id)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree *FindNode(Tree *node, int value)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->id == value)
    {
        return node;
    }
    Tree *tmp = node->left;
    Tree *p;
    while (tmp != NULL)
    {
        Tree *p;
        p = FindNode(tmp, value);
        if (p != NULL)
            return p;
        tmp = node->right;
    }
}

// Insert on the left of the node
Tree *addLeftChild(int parent, int value)
{
    Tree *tmp = FindNode(root, parent);
    tmp->left = newNode(value);
}

// Insert on the right of the node
Tree *addRightChild(int parent, int value)
{
    Tree *tmp = FindNode(root, parent);
    tmp->right = newNode(value);
}

// Read File
void read(char *filename)
{
    FILE *p = fopen(filename, "r+");
    // Tree *cur_node = (Tree *)malloc(sizeof(Tree));
    int left, right, parent;

    while (fscanf(p, "%d %d %d", &parent, &left, &right) != EOF)
    {
        if (parent == -2)
            break;
        if (root == NULL)
        {
            root = newNode(parent);
        }
        printf("%d\n/////////\n", parent);
        if (left > -1)
        {
            printf("%d\n++++++++\n", left);
            addLeftChild(parent, left);
        }
        printf("ok %d,%d,%d \n", parent, left, right);

        if (right > -1)
        {
            printf("%d\n********\n", right);
            addRightChild(parent, right);
        }
        // printf("%d,%x\n", root->id, root);
    }
    fclose(p);
}

void printTree(Tree *r, int level)
{
    if (r == NULL)
        return;
    for (int i = 0; i < level; i++)
        printf(i == level - 1 ? "|_" : "| ");
    printf("%d\n", r->id);
    printTree(r->left, level + 1);
    printTree(r->right, level + 1);
}

int main()
{
    root = NULL;

    read("Btree.txt");

    printTree(root, 0);
}