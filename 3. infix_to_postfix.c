// INFIX TO POSTFIX

#include <stdio.h>

char stack[100];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

char peek() {
    return (top == -1) ? '\0' : stack[top];
}

int isEmpty() {
    return top == -1;
}

int isOperand(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

int isp(char c) {          // in-stack precedence
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        default:  return -1;
    }
}

int icp(char c) {          // incoming precedence
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 4;
        case '(': return 5;
        default:  return -1;
    }
}

void convert() {
    char exp[100], item;
    int i = -1, j = 0;

    printf("Enter the expression: ");
    scanf("%s", exp);

    push('(');                 // add '(' to stack

    // add ')' at the end of expression
    while (exp[j] != '\0') j++;
    exp[j] = ')';
    exp[j + 1] = '\0';

    printf("Postfix expression: ");

    while (!isEmpty()) {
        item = exp[++i];

        if (isOperand(item)) {
            printf("%c", item);
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while (peek() != '(')
                printf("%c", pop());
            pop();             // remove '('
        } else {               // operator
            while (isp(peek()) >= icp(item))
                printf("%c", pop());
            push(item);
        }
    }
    printf("\n");
}

int main() {
    convert();
    return 0;
}
