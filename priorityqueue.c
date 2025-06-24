#include <stdio.h>
#define MAX 5

struct item {
    int data;
    int priority;
};

struct priority_queue {
    struct item arr[MAX];
    int size;
};

void enqueue(struct priority_queue *pq, int value, int priority) {
    if (pq->size == MAX) {
        printf("Queue Overflow!\n");
        return;
    }

    pq->arr[pq->size].data = value;
    pq->arr[pq->size].priority = priority;
    pq->size++;

    printf("Inserted: %d (priority: %d)\n", value, priority);
}

void dequeue(struct priority_queue *pq) {
    if (pq->size == 0) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int highest = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i].priority < pq->arr[highest].priority) {
            highest = i;
        }
    }

    int removed_value = pq->arr[highest].data;

    for (int i = highest; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;

    printf("Removed: %d\n", removed_value);;
}

void display(struct priority_queue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d | Priority: %d\n", pq->arr[i].data, pq->arr[i].priority);
    }
}

int main() {
    struct priority_queue pq;
    pq.size = 0;
    int n,v,p;
    int choice=0;
    printf("\n********Priority queue**********");
    while(choice!=-1){
    printf("\nEnter your choice(only numbers):\n1.enqueue\n2.dequeue\n3.display\n-1 to exit:");
    scanf("%d",&choice);
    if(choice==1){
    printf("\nEnter number of elements to enqueue:");
    scanf("%d",&n);

    int i;
    for(i=0;i<n;i++){
        printf("\nEnter number to enqueue:");
        scanf("%d",&v);
        printf("\nEnter priority:");
        scanf("%d",&p);
        enqueue(&pq, v, p);
    }
    }
    else if(choice==2){
        dequeue(&pq);
    }
    else if(choice==3){
        display(&pq);
    }
    }
    return 0;
}

