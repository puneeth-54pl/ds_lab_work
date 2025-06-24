#include <stdio.h>
#include <conio.h>
#define MAX 3

struct queue {
    int arr[MAX];
    int front;
    int rear;
};

int isfull(struct queue *q) {
    return q->rear == MAX - 1;
}

int isempty(struct queue *q) {
    return q->front == q->rear;
}

void enqueue(struct queue *q, int val) {
    if (!isfull(q)) {
        q->arr[++q->rear] = val;
        printf("\nValue inserted successfully: %d\n", val);
    } else {
        printf("\nQueue overflow!!!\n");
    }
}

int dequeue(struct queue *q) {
    if (!isempty(q)) {
        return q->arr[++q->front];
    } else {
        printf("\nQueue underflow!!!\n");
        return -1;
    }
}

void displayQueue(struct queue *q) {
    if (isempty(q)) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nCurrent queue elements:\n");
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d\n", q->arr[i]);
    }
}

void showMenu() {
    printf("\nQueue Operations Menu:\n");
    printf("1. Enqueue element\n");
    printf("2. Dequeue element\n");
    printf("3. Display queue\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

int main() {
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;
    int dequeuedValue;

    do {
        clrscr();
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeuedValue = dequeue(&q);
                if (dequeuedValue != -1) {
                    printf("\nDequeued value: %d\n", dequeuedValue);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

        printf("\nPress any key to continue...");
        getch();
    } while (choice != 4);

    return 0;
}