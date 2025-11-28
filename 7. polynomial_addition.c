#include <stdio.h>
#include <stdlib.h>
struct Node {
int coeff;
int exp;
struct Node* next;
};
void insertTerm(struct Node** head, int coeff, int exp) {
if (coeff == 0) return;
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->coeff = coeff;
newNode->exp = exp;
newNode->next = NULL;
if (*head == NULL || (*head)->exp < exp) {
newNode->next = *head;
*head = newNode;
return;
}
struct Node* current = *head;
if (current->exp == exp) {
current->coeff += coeff;
free(newNode);
return;
}
while (current->next != NULL && current->next->exp > exp) {
current = current->next;
}
if (current->next != NULL && current->next->exp == exp) {
current->next->coeff += coeff;
free(newNode);
} else {
newNode->next = current->next;
current->next = newNode;
}
}
void display(struct Node* head) {
struct Node* temp = head;
while (temp != NULL) {
printf("%dx^%d", temp->coeff, temp->exp);
if (temp->next != NULL) printf(" + ");
temp = temp->next;
}
printf("\n");
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
struct Node* result = NULL;
while (poly1 != NULL || poly2 != NULL) {
if (poly1 == NULL) {
insertTerm(&result, poly2->coeff, poly2->exp);
poly2 = poly2->next;
} else if (poly2 == NULL) {
insertTerm(&result, poly1->coeff, poly1->exp);
poly1 = poly1->next;
} else if (poly1->exp > poly2->exp) {
insertTerm(&result, poly1->coeff, poly1->exp);
poly1 = poly1->next;
} else if (poly1->exp < poly2->exp) {
insertTerm(&result, poly2->coeff, poly2->exp);
poly2 = poly2->next;
} else {
insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
poly1 = poly1->next;
poly2 = poly2->next;
}
}
return result;
}
int main() {
struct Node* poly1 = NULL;
struct Node* poly2 = NULL;
int n1, n2;
printf("Enter the number of terms in polynomial 1: ");
scanf("%d", &n1);
printf("Enter the terms (coefficient and exponent) for polynomial 1:\n");
for (int i = 0; i < n1; i++) {
int coeff, exp;
scanf("%d %d", &coeff, &exp);
insertTerm(&poly1, coeff, exp);
}
printf("Enter the number of terms in polynomial 2: ");
scanf("%d", &n2);
printf("Enter the terms (coefficient and exponent) for polynomial 2:\n");
for (int i = 0; i < n2; i++) {
int coeff, exp;
scanf("%d %d", &coeff, &exp);
insertTerm(&poly2, coeff, exp);
}
printf("\nPolynomial 1: ");
display(poly1);
printf("Polynomial 2: ");
display(poly2);
struct Node* result = addPolynomials(poly1, poly2);
printf("Sum of Polynomials: ");
display(result);
return 0;
}
