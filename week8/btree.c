#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree{
    int id;
    struct Tree* left;
    struct Tree* right; 
} Tree;
Tree* root;

Tree* newNode(int id){
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert on the left of the node
Tree* addLeftChild(Tree* root, int value) {
  root->left = newNode(value);
  return root->left;
}

// Insert on the right of the node
Tree* addRightChild(Tree* root, int value) {
  root->right = newNode(value);
  return root->right;
}

//Read File
void read(char* filename){
    FILE* p = fopen(filename,"r");
    Tree* cur_node = (Tree*)malloc(sizeof(Tree));
    int left,right;
    
    while(fscanf(p, "%d %d %d", &cur_node->id, &left, &right) !=EOF){
    if (root == NULL)
        root = newNode(cur_node->id);;
    if(cur_node->id == -2) 
        break;
    if(left > -1) 
        addLeftChild(cur_node,left);
    if(right > -1) 
        addRightChild(cur_node,right);
    }
    fclose(p);
}
    

void printTree(Tree* r, int level) {
    if (r == NULL) return;
    for (int i = 0; i < level; i++)
    printf(i == level - 1 ? "|_" : "| ");
    printf("%d\n", r->id);
    printTree(r->left, level + 1);
    printTree(r->right, level + 1);
}
 
int main()
{
    Tree* p;
    read("btree.txt");
    printTree(p,3);

}