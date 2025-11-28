#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node {
char data;
struct Node *left, *right;
};
struct Node* createNode(char c) {
struct Node* n = (struct Node*)malloc(sizeof(struct Node));
n->data = c;
n->left = n->right = NULL;
return n;
}
char stack[100];
int top = -1;
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int empty() { return top == -1; }
int precedence(char c) {
if (c == '^') return 3;
if (c == '*' || c == '/') return 2;
if (c == '+' || c == '-') return 1;
return 0;
}
int isOperator(char c) {
return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}
void infixToPostfix(char infix[], char postfix[]) {
int j = 0;
for (int i = 0; i < strlen(infix); i++) {
char c = infix[i];
if (c == ' ') continue;
if (isalnum(c)) postfix[j++] = c;
else if (c == '(') push(c);
else if (c == ')') {
while (!empty() && peek() != '(') postfix[j++] = pop();
pop();
} else if (isOperator(c)) {
while (!empty() && precedence(peek()) >= precedence(c)) postfix[j++] = pop();
push(c);
}
}
while (!empty()) postfix[j++] = pop();
postfix[j] = '\0';
}
// Tree from postfix
struct Node* nstack[100];
int ntop = -1;
void npush(struct Node* n) { nstack[++ntop] = n; }
struct Node* npop() { return nstack[ntop--]; }
struct Node* buildTree(char postfix[]) {
for (int i = 0; postfix[i]; i++) {
char c = postfix[i];
if (isalnum(c)) npush(createNode(c));
else if (isOperator(c)) {
struct Node* t = createNode(c);
t->right = npop();
t->left = npop();
npush(t);
}
}
return npop();
}
void preorder(struct Node* root) {
if (!root) return;
printf("%c", root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct Node* root) {
if (!root) return;
postorder(root->left);
postorder(root->right);
printf("%c", root->data);
}
int main() {
char infix[100], postfix[100];
printf("Enter an arithmetic expression: ");
scanf("%s", infix);
infixToPostfix(infix, postfix);
struct Node* root = buildTree(postfix);
printf("Prefix: ");
preorder(root);
printf("\nPostfix: ");
postorder(root);
printf("\n");
return 0;
}
