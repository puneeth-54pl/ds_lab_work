#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Overflow! Memory not available.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {

        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow! Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
   int n,v,p;
    int choice=0;
    printf("\n********queue implementation using linked list**********");
    while(choice!=-1){
    printf("\nEnter your choice(only numbers):\n1.enqueue\n2.dequeue\n3.display\n4.peek\n-1 to exit:");
    scanf("%d",&choice);
    if(choice==1){
    printf("\nEnter number of elements to enqueue:");
    scanf("%d",&n);

    int i;
    for(i=0;i<n;i++){
        printf("\nEnter number to enqueue:");
        scanf("%d",&v);
        enqueue(v);
    }
    }
    else if(choice==2){
        dequeue();
    }
    else if(choice==3){
        display();
    }
    else if(choice==4){
        peek();
    }
    }
    return 0;
}

