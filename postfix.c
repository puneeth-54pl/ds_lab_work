#include <stdio.h>
#include <ctype.h>

#define Maxcols 10

typedef struct {
    int top;
    int arr[Maxcols];
} stack;

void init(stack *s) {
    s->top = -1;
}

int isempty(stack *s) {
    return s->top == -1;
}

int isfull(stack *s) {
    return s->top == Maxcols - 1;
}
void push(stack *s, int n) {
    if (isfull(s)) {
        printf("\nCannot push. Stack overflow.");
    } else {
        s->arr[++s->top] = n;
    }
}

int pop(stack *s) {
    if (isempty(s)) {
        printf("\nStack underflow. Cannot pop.");
        return -1;
    } else {
        return s->arr[s->top--];
    }
}


int evaluatePostfix(char expr[]) {
    stack s;
    init(&s);
    int i = 0, val1, val2;

    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            push(&s, expr[i] - '0');
        } else {
            val1 = pop(&s);
            val2 = pop(&s);
            switch (expr[i]) {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': push(&s, val2 / val1); break;
                default: printf("\nInvalid operator: %c", expr[i]);
            }
        }
        i++;
    }

    return pop(&s);
}


void main() {
    char expr[Maxcols];
    int pos = 0;
    char ch;

    printf("Enter the postfix expression (no spaces, single-digit operands): ");
    while ((ch = getchar()) != '\n' && pos < Maxcols - 1) {
        if (ch != ' ') {
            expr[pos++] = ch;
        }
    }
    expr[pos] = '\0';

    printf("\nOriginal Postfix Expression: %s", expr);

    int result = evaluatePostfix(expr);

    printf("\nResult of Postfix Evaluation: %d\n", result);
}
