#include<stdio.h>

typedef struct Node
{
    char name[256];
    struct Node* leftMostChild; // pointer to the left-most child
    struct Node* rightSibling;// pointer to the right sibling
}Node;

Node* makeNode(char* name){
Node* p = (Node*)malloc(sizeof(Node));
strcpy(p->name,name);
p->leftMostChild = NULL; p->rightSibling = NULL;
return p;
}