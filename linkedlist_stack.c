// Program to implement Stack using Linked List
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
    printf("Pushed %d\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    NODEPTR temp = top;
    top = top->next;
    printf("Popped %d\n", temp->data);
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
    printf("Stack from top: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n,v;
    int choice=0;
    printf("\nStack implementation using linked list");
    while(choice!=-1){
        printf("\nEnter your choice(only numbers):\n1.push\n2.pop\n3.peek\n4.display\n-1 to exit:");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter number of elements to push:");
            scanf("%d",&n);
            int i;
            for(i=0;i<n;i++){
                printf("\nEnter number to push:");
                scanf("%d",&v);
                push(v);
            }
        }
        else if(choice==2){
            pop();
        }
        else if(choice==3){
            peek();
        }
        else if(choice==4){
            display();
        }
    }
    return 0;
}
