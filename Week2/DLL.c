#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Profile{
    int data;
    struct Profile *next;
    struct Profile *prev;
}Profile;

Profile *first,*last,*p;

void initList(){
	first = NULL, last = NULL;
}
int listEmpty(){
	return first == NULL && last == NULL;
}

void push(int new_data)
{
	Profile* Node = (struct Profile*)malloc(sizeof(struct Profile));

	Node->data = new_data;

	Node->next = p;
	Node->prev = NULL;

	if (p != NULL) 
		p->prev = Node;
	p = Node;
}


void insertAfter(int new_data)
{
    Profile* prev_node;
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
	}
    else Find(prev_node->data);

	Profile* Node = (Profile*)malloc(sizeof(struct Profile));

	Node->data = new_data;

	Node->next = prev_node->next;

	prev_node->next = Node;

	Node->prev = prev_node;

}

void insertLast(int new_data)
{
	Profile* Node = (Profile*)malloc(sizeof(struct Profile));

	Profile* last = p; 

	Node->data = new_data;

	Node->next = NULL;

	if (p == NULL) {
		Node->prev = NULL;
		p = Node;
	
	}

	while (last->next != NULL)
		last = last->next;

	last->next = Node;

	Node->prev = last;

	
}
//NOPE//
void load(){
	char filename[256];
	int data;
	printf("Input filename:");
	scanf("%s", &filename);
    FILE* f = fopen(filename,"r");
    if(f == NULL) printf("file not found\n");
    while(!feof(f)){
        
        fscanf(f,"%d",data);
        insertLast(data);
    }
    fclose(f);
}

Profile Find(int data){
    scanf("%d",data);
    Profile profile = NULL;
    for(Profile* p = first; p != NULL; p = p->next){
        if(p->data == data){
            profile = p;
            break;
        }
    }
    if(profile == NULL){
        printf("NOT FOUND profile %d\n",data);
    } else {
        printf("FOUND profile %d\n",profile->data);
    }
    
    return profile;
}

void Write(){// luu du lieu DS vao file van ban
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(Profile* p = first; p != NULL; p = p->next){
        fprintf(f,"%s",p->data);
        if(p->next != NULL) fprintf(f,"\n");
    }
    fclose(f);
}

void printList()
{
    Profile* node;
	Profile* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);

		last = node;

		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		
		last = last->prev;
	}
}

int main()
{
	initList();
    load();
    printList();
	return 0;
}
