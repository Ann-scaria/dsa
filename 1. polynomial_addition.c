#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

int main() {
    int n1, n2, i, j, k;

    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n1);

    struct poly poly1[n1];
    printf("Enter the terms (coefficient and exponent) for polynomial 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp);
    }

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n2);

    struct poly poly2[n2];
    printf("Enter the terms (coefficient and exponent) for polynomial 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d", &poly2[i].coeff, &poly2[i].exp);
    }

    struct poly poly3[n1 + n2];
    i = 0;
    j = 0;
    k = 0;

    /* add the two polynomials (terms are assumed in descending order of exp) */
    while (i < n1 && j < n2) {
        if (poly1[i].exp == poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            poly3[k].exp   = poly1[i].exp;
            i++;
            j++;
            k++;
        } else if (poly1[i].exp > poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff;
            poly3[k].exp   = poly1[i].exp;
            i++;
            k++;
        } else {
            poly3[k].coeff = poly2[j].coeff;
            poly3[k].exp   = poly2[j].exp;
            j++;
            k++;
        }
    }

    /* copy remaining terms of poly1, if any */
    while (i < n1) {
        poly3[k].coeff = poly1[i].coeff;
        poly3[k].exp   = poly1[i].exp;
        i++;
        k++;
    }

    /* copy remaining terms of poly2, if any */
    while (j < n2) {
        poly3[k].coeff = poly2[j].coeff;
        poly3[k].exp   = poly2[j].exp;
        j++;
        k++;
    }

    printf("\nPolynomial 1: ");
    for (i = 0; i < n1; i++) {
        printf("%dx^%d", poly1[i].coeff, poly1[i].exp);
        if (i != n1 - 1) printf(" + ");
    }

    printf("\nPolynomial 2: ");
    for (i = 0; i < n2; i++) {
        printf("%dx^%d", poly2[i].coeff, poly2[i].exp);
        if (i != n2 - 1) printf(" + ");
    }

    printf("\nSum of Polynomials: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", poly3[i].coeff, poly3[i].exp);
        if (i != k - 1) printf(" + ");
    }
    printf("\n");

    return 0;
}
