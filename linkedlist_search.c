// Program to implement Stack with Search and Delete using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node* NODEPTR;

NODEPTR top = NULL; // Pointer to the top of the stack

// Function to push an element onto the stack
void push(int value) {
    NODEPTR newNode = (NODEPTR)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    NODEPTR temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
}

// Function to display the top element
void peek() {
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Top element: %d\n", top->data);
}

// Function to display all elements in the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    NODEPTR temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with a given value from the stack
void deleteNode(int x) {
    if (top == NULL) {
        printf("Stack is empty. Cannot delete %d.\n", x);
        return;
    }
    NODEPTR temp = top;
    NODEPTR prev = NULL;
    // Search for the node to delete
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the stack.\n", x);
        return;
    }
    // If node to delete is the top node
    if (prev == NULL) {
        top = top->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Deleted node with value %d\n", x);
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    display(); 
    deleteNode(30); 
    display();   
    deleteNode(50); 
    pop();           
    display();
    peek();  
    return 0;
}
