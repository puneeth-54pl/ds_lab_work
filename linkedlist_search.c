#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
}

void peek() {
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Top element: %d\n", top->data);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(int x) {
    if (top == NULL) {
        printf("Stack is empty. Cannot delete %d.\n", x);
        return;
    }

    struct Node* temp = top;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the stack.\n", x);
        return;
    }

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
