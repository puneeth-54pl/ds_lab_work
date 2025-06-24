#include <stdio.h>
#define MAX 5
struct cir_queue{
int arr[MAX];
int front;
int rear;
};
int isfull(struct cir_queue *q){

    return ((q->rear+1)%MAX ==q->front);
}
int isempty(struct cir_queue *q){
    return q->front==q->rear;
}
void enqueue(struct cir_queue *q,int val){
    if(!isfull(q)){
        q->rear=(q->rear+1)%MAX;
        q->arr[q->rear]=val;
        printf("\nvalue inserted successfully:%d\n",val);

    }
    else{
        printf("\nqueue overflow!!!\n");
    }
}
void dequeue(struct cir_queue *q){
    if(!isempty(q)){
        q->front=(q->front+1)%MAX;
        printf("\nremoved element from queue:%d\n",q->arr[q->front]);
    }
    else {
        printf("\nQueue underflow!!!\n");
    }
}
void display(struct cir_queue *q){
    int f=q->front+1;
    printf("\nelements in the queue are:");
    while(f!=q->rear+1){
        printf("\n%d",q->arr[f]);
        f++;
    }
    }
int main(){
    struct cir_queue q;
    q.front=0;
    q.rear=0;
    int n,v;
    int choice=0;
    printf("\n********Circular queue**********");
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
        enqueue(&q,v);
    }
    }
    else if(choice==2){
        dequeue(&q);
    }
    else if(choice==3){
        display(&q);
    }
    }
    return 0;
}
