#include <stdio.h>
#include <ctype.h>

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

void infixToPostfix(char expr[]) {
    struct Stack s;
    initStack(&s);
    char post_expr[MAX];
    int i = 0, j = 0;
    char symb;
    char topsymb;

    while (expr[i] != '\0') {
        symb = expr[i];

        if (isdigit(symb)) {
            post_expr[j++] = symb;
        }

        else if (symb == '(') {
            push(&s, symb);
        }

        else if (symb == ')') {
            while (!isEmpty(&s) && s.arr[s.top] != '(') {
                post_expr[j++] = pop(&s);
            }
            pop(&s);  // Pop the '(' from the stack.
        }
        else {
            while (!isEmpty(&s) && precedence(s.arr[s.top]) >= precedence(symb)) {
                post_expr[j++] = pop(&s);
            }
            push(&s, symb);
        }
        i++;
    }


    while (!isEmpty(&s)) {
        post_expr[j++] = pop(&s);
    }

    post_expr[j] = '\0';
    printf("\nConverted Postfix Expression: %s\n", post_expr);
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

    infixToPostfix(expr);

    return 0;
}
