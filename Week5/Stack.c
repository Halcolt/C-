#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char c;
    struct Node* next;
} Node;

Node* top;

Node* makeNode(char x)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = x; p->next = NULL;
    return p;
}

void initStack()
{
    top = NULL;
}
    
int stackEmpty() 
{
    return top == NULL;
}

void push(char x)
{
    Node* p = makeNode(x);
    p->next = top; top = p;
}

char pop()
{
    if(stackEmpty()) return ' ';
    char x = top->c;
    Node* tmp = top; top = top->next; free(tmp);
    return x;
}

int match(char a, char b)
{
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

int main()
{
    printf("Nhap input : ");
    //dynamic string
    char *input = (char *)malloc(sizeof(char));
    char n;
    int new_n = 1;          //newchar
    while (1 == 1) 
    {
        scanf("%c", &n);
        if (n == '\n')
        {break;}
        char *B = (char *)realloc(input,sizeof(char)*(new_n+1));
        B[new_n] = n;
        new_n++;
        input = B;
    }
    //printf("%c",input[1]);

    int check = 0;
    initStack();
    for(int i = 1; i < strlen(input); i++)      //bug somewhere about the address-> make i need to run from 1
    {
        
        if( input[i] == '(' || input[i] == '[' || input[i] == '{')
        {
            push(input[i]);
        }
        else 
        {
            if(stackEmpty()) goto Output;               
            //improve, instead of return 0 make the program exxit if not match char which
            //make equation like (4+4) is not valid, goto can! 
            if( input[i] == ')' || input[i] == ']' || input[i] == '}')
                {
                char test = pop();
                check = match(test, input[i]);   
                }
                //printf("%d\n",check);
        }
    }
    Output:
    if(check == 1) 
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    return 0;
}