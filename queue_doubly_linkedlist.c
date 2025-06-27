#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Overflow! Memory not available.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;
    if (!front) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (!front) {
        printf("Underflow! Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    if (front) front->prev = NULL;
    else rear = NULL;
    free(temp);
}



void display() {
    if (!front) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice = 0, value, n;
    printf("\nQueue implementation using doubly linked list\n");
    while (choice != -1) {
        printf("\nEnter your choice (only numbers):\n1.enqueue\n2.dequeue\n3.display\n-1 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nEnter number of elements to enqueue: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter number to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
            }
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        }
    }
    return 0;
}
