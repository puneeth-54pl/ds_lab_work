#include <stdio.h>
#define MAX 10


struct Stack {
    int arr[MAX];
    int top;
};
void initialize(struct Stack *ps){
 ps->top=-1;

}
void push(struct Stack *ps,int n){
 if(ps->top==MAX-1){
 printf("Stack is full.Overflow. Cannot push\n");
 }
 else{
 printf("push successful:%d\n",n);
 ps->arr[++ps->top]=n;
 }
}
void display(struct Stack *ps){
 int i;
 printf("stack elements:\n");
 for(i=0;i<=ps->top;i++){
   printf("%d\n",ps->arr[i]);
  }
}
void pop(struct Stack *ps){
 if(ps->top==-1){
 printf("Stack is empty. Underflow. cannot pop\n");
 }
 else{
  printf("pop successful: %d\n",ps->arr[ps->top--]);
 }
}
void main(){
 struct Stack s1;
 initialize(&s1);
 clrscr();
  push(&s1,1);
  push(&s1,2);
  display(&s1);
  pop(&s1);
  push(&s1,3);
  push(&s1,4);
  display(&s1);
  pop(&s1);
  pop(&s1);
  display(&s1);
  pop(&s1);pop(&s1);

  getch();
}
