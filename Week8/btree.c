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
        
        if (left > -1)
        {
            addLeftChild(parent, left);
        }

        if (right > -1)
        {
            
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
    int choose = 0,value,parent;
option:
     while (choose < 1 || choose > 8)
    {
        printf("-----------------------------------------------------\n");
        printf("1. Doc du lieu tu file\n");
        printf("2. In cay\n");
        printf("3. Them mot con vao ben trai mot not\n");
        printf("4. In danh sach tat ca thanh vien\n");
        printf("5. Thoat\n");
        printf("-----------------------------------------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choose);
    }

    while (choose > 0 && choose < 8)
    {
        switch (choose)
        {
        case 1:
            read("btree.txt");
            choose = 0;
            goto option;
        case 2:
            printTree(root,0);
            choose = 0;
            goto option;
        case 3:
            fflush(stdin);
            printf("Nhap node can them: ");
            scanf("%d",&parent);
            if (FindNode(root, parent) == NULL)
            {
                printf("Khong tim thay ten node trong cay\n");
                choose = 0;
                goto option;
            }
            fflush(stdin);
            printf("Nhap gia tri can them vao: ");
            scanf("%s", value);
            addLeftChild(parent, value);
            choose = 0;
            goto option;
        case 4:
            fflush(stdin);
            printf("Nhap node can them: ");
            scanf("%d",&parent);
            if (FindNode(root, parent) == NULL)
            {
                printf("Khong tim thay ten node trong cay\n");
                choose = 0;
                goto option;
            }
            fflush(stdin);
            printf("Nhap gia tri can them vao: ");
            scanf("%s", value);
            addRightChild(parent, value);
            choose = 0;
            goto option;
            
        case 5:
            free(root);
            return 0;
        }
    }
}