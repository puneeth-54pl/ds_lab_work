#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 20

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
    } else {
        s->arr[++(s->top)] = value;
        printf("Pushed %c to the stack\n", value);
    }
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return 0;
}
void reverse(char *expr){
    int l=strlen(expr);
    for (int i=0,j=l-1;i<j;i++,j--){
        char temp=expr[i];
        expr[i]=expr[j];
        expr[j]=temp;
        }
}
void infixToPrefix(char expr[]) {
    struct Stack s;
    initStack(&s);
    char prefix_expr[MAX];
    int i = 0, j = 0;
    char symb;
    char topsymb;
    reverse(&expr);
    while (expr[i] != '\0') {
        symb = expr[i];

        if (isdigit(symb)) {
            prefix_expr[j++] = symb;
        }

        else if (symb == ')') {
            push(&s, symb);
        }

        else if (symb == '(') {
            while (!isEmpty(&s) && s.arr[s.top] != ')') {
                prefix_expr[j++] = pop(&s);
            }
            pop(&s);
        }
        else {
            while (!isEmpty(&s) && precedence(s.arr[s.top]) >= precedence(symb)) {
                prefix_expr[j++] = pop(&s);
            }
            push(&s, symb);
        }
        i++;
    }


    while (!isEmpty(&s)) {
        prefix_expr[j++] = pop(&s);
    }

    prefix_expr[j] = '\0';
    reverse(&prefix_expr);
    printf("\nConverted prefix Expression: %s\n", prefix_expr);
}

int main() {
    char expr[MAX];
    int pos = 0;
    char ch;

    printf("Enter the infix expression: ");
    while ((ch = getchar()) != '\n' && pos < MAX) {
        if (ch != ' ') {
            expr[pos++] = ch;
        }
    }
    expr[pos] = '\0';

    printf("\nOriginal Infix Expression: %s\n", expr);

    infixToPrefix(expr);

    return 0;
}
