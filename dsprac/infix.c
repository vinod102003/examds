#include <stdio.h>
#include <ctype.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int priority(char x) {
    if (x == '(') {
        return 0;
    } else if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    }
    return -1;
}

int main() {
    char exp[MAX] = "(2*4/3-91)";
    char *e, x;
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                if (x != -1) {
                    printf("%c", x);
                }
            }
        } else {
            while (priority(stack[top]) >= priority(*e)) {
                if (top == -1) {
                    break;
                }
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
