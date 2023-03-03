#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char name[50];
    char email[50];
} Contact;

typedef struct {
    Contact items[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, Contact contact) {
    if (stack->top < MAX_STACK_SIZE) {
        stack->items[stack->top] = contact;
        stack->top++;
    } else {
        printf("Stack overflow\n");
    }
}

Contact pop(Stack *stack) {
    Contact contact = {"", ""};
    if (stack->top > 0) {
        stack->top--;
        contact = stack->items[stack->top];
    } else {
        printf("Stack underflow\n");
    }
    return contact;
}

void printStack(struct StackNode* top) {
    printf("Stack:\n");
    while (top != NULL) {
        printf("Name: %s, Email: %s\n", top->name, top->email);
        top = top->next;
    }
}


int main() {
    Stack stack = { .top = 0 };
    Contact contact1 = { .name = "John Smith", .email = "john.smith@example.com" };
    Contact contact2 = { .name = "Jane Doe", .email = "jane.doe@example.com" };

    push(&stack, contact1);
    push(&stack, contact2);

    Contact popped_contact = pop(&stack);
    printf("Popped contact: %s (%s)\n", popped_contact.name, popped_contact.email);

    return 0;
}
