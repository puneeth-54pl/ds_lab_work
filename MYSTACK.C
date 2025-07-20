// Program to implement Stack using Array with overflow and underflow checks
#include <stdio.h>
#define MAX 100

int stack[MAX]; // Array to store stack elements
int top = -1;   // Index of the top element

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("Pushed: %d\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

// Function to display the top element
void peek() {
    if (top == -1)
        printf("Stack is empty.\n");
    else
        printf("Top element: %d\n", stack[top]);
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack from top: ");
    for (int i = top; i >= 0; i--) {
        printf("%d -> ", stack[i]);
    }
    printf("NULL\n");
}

int main() {
    int choice = 0, value, n;
    printf("\nStack implementation using array\n");
    while (choice != -1) {
        printf("\nEnter your choice (only numbers):\n1.push\n2.pop\n3.display\n-1 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nEnter number of elements to push: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter number to push: ");
                scanf("%d", &value);
                push(value);
            }
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        }
    }
    return 0;
}
