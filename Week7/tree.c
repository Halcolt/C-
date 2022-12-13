#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char name[30];
    struct Node *leftMostChild; // pointer to the left-most child
    struct Node *rightSibling;  // pointer to the right sibling
} Node;

Node *root;
int max;
int countt = 0;
void Empty_List()
{
    root = NULL;
}

Node *makeNode(char name[]) // check here
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node *FindChildren(Node *root, char name[])
{
    if (root == NULL)
        return NULL;
    if (strcmp(root->name, name) == 0)
        return root;
    Node *tmp = root->leftMostChild;
    while (tmp != NULL)
    {
        Node *p;
        p = FindChildren(tmp, name);
        if (p != NULL)
            return p;
        tmp = tmp->rightSibling;
    }
    return NULL;
}

Node *AddSibling(Node *sibling, char name[])
{
    if (sibling == NULL)
        return makeNode(name);

    sibling->rightSibling = AddSibling(sibling->rightSibling, name);
    return sibling;
}

void Add(char parent[], char child[])
{
    Node *tmp = FindChildren(root, parent);
    tmp->leftMostChild = AddSibling(tmp->leftMostChild, child);
}
void processLoad(Node **root, FILE *fptr)
{
    char str[30];
    char parent[30];
    char child[30];

    rewind(fptr); // set pointer to begin of file
    fscanf(fptr, "%s", parent);

    *root = makeNode(parent);

    while (fscanf(fptr, "%s", str) != EOF)
    {
        if (strcmp(str, "$") != 0)
            Add(parent, str);
        // printf("\t%s\n", parent);
        if (strcmp(str, "$") == 0)
            fscanf(fptr, "%s", parent);

        if (strcmp(str, "$$") == 0)
            break;
    }

    fclose(fptr);
}
int PrintChild(Node *root)
{
    while (root != NULL)
    {
        printf("%s ", root->name);
        root = root->rightSibling;
    }
    printf("\n");
}

int processPrint(Node *root)
{
    if (root != NULL)
    {
        if (root->leftMostChild != NULL)
        {
            printf("%s ", root->name);
            root->leftMostChild;
            PrintChild(root->leftMostChild);
            processPrint(root->leftMostChild);
        }
    }
    if (root->rightSibling != NULL)
    {
        processPrint(root->rightSibling);
    }
}

int height(Node *root, int tmp)
{
    if (root->leftMostChild == NULL && max <= tmp)
    {
        max = tmp;
    }
    if (root != NULL)
    {
        if (root->leftMostChild != NULL)
        {
            tmp++;
            height(root->leftMostChild, tmp);
        }
    }
    if (root->rightSibling != NULL)
    {
        height(root->rightSibling, tmp);
    }
    return max;
}
int count(Node *root)
{
    countt++;
    if (root != NULL)
    {
        if (root->leftMostChild != NULL)
        {
            count(root->leftMostChild);
        }
    }
    if (root->rightSibling != NULL)
    {
        count(root->rightSibling);
    }
    return countt;
}
int main()
{
    FILE *p;
    p = fopen("tree.txt", "r");
    int choose = 0, max = 0;
    char parent[30];
    char child[30];

option:
    while (choose < 1 || choose > 8)
    {
        printf("-----------------------------------------------------\n");
        printf("1. Doc du lieu tu file\n");
        printf("2. In danh sach con cua mot node\n");
        printf("3. Them mot con vao cuoi danh sach mot node\n");
        printf("4. In danh sach tat ca thanh vien\n");
        printf("5. Tinh chieu cao cua cay\n");
        printf("6. Dem so thanh vien gia dinh\n");
        printf("7. Luu tru vao file\n");
        printf("8. Thoat\n");
        printf("-----------------------------------------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choose);
    }

    while (choose > 0 && choose < 8)
    {
        switch (choose)
        {
        case 1:
            processLoad(&root, p);
            choose = 0;
            goto option;
        case 2:
            processPrint(root);
            choose = 0;
            goto option;
        case 3:
            fflush(stdin);
            printf("Nhap node can them: ");
            scanf("%s", parent);
            if (FindChildren(root, parent) == NULL)
            {
                printf("Khong tim thay ten node trong cay\n");
                choose = 0;
                goto option;
            }
            fflush(stdin);
            printf("Nhap ten con can them vao: ");
            scanf("%s", child);
            Add(parent, child);
            choose = 0;
            goto option;
        case 4:
            printf("Nhap node can tim: ");
            scanf("%s", parent);
            if (FindChildren(root, parent) == NULL)
            {
                printf("Khong tim thay ten node trong cay\n");
                choose = 0;
                goto option;
            }
            PrintChild(FindChildren(root, parent)->leftMostChild);
            choose = 0;
            goto option;
        case 5:
            max = 0;
            printf("Do cao cua cay la %d\n", height(root, 0));
            choose = 0;
            goto option;
        case 6:
            printf("So node cua cay: %d\n", count(root));
            choose = 0;
            goto option;
        case 7:
            choose = 0;
            goto option;
        case 8:
            fclose(p);
            free(root);
            return 0;
        }
        fclose(p);
        free(root);
    }
}