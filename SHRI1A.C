#include <stdio.h>
#include <stdlib.h>

#define MAX 100 


typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;


void initializeStack(Stack *stack) {
    stack->top = -1;
}


int isEmpty(Stack *stack) {
    return stack->top == -1;
}


int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}


void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1; // Return -1 to indicate failure
    }
    return stack->arr[stack->top--];
}


void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}


int main() {
    Stack stack;
    initializeStack(&stack);

    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
