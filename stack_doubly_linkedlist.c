// Program to implement Stack using Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* top = NULL; // Pointer to the top of the stack

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = top;
    if (top) top->prev = newNode;
    top = newNode;
    printf("Pushed: %d\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (!top) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    if (top) top->prev = NULL;
    free(temp);
}

// Function to display the top element
void peek() {
    if (!top) printf("Stack is empty.\n");
    else printf("Top element: %d\n", top->data);
}

// Function to display all elements in the stack
void display() {
    if (!top) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack from top: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice = 0, value, n;
    printf("\nStack implementation using doubly linked list\n");
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
