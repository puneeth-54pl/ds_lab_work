// Program to implement Queue using Array with overflow and underflow checks
#include <stdio.h>
#define MAX 100

int queue[MAX]; // Array to store queue elements
int front = -1, rear = -1; // Indices for front and rear

// Function to enqueue (add) an element to the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
    if (front > rear) front = rear = -1;
}

// Function to display the front element
void peek() {
    if (front == -1 || front > rear)
        printf("Queue is empty.\n");
    else
        printf("Front element: %d\n", queue[front]);
}

// Function to display all elements in the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d -> ", queue[i]);
    }
    printf("NULL\n");
}

int main() {
    int choice = 0, value, n;
    printf("\nQueue implementation using array\n");
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