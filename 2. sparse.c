#include <stdio.h>
#define MAX 50

typedef struct {
    int row;
    int col;
    int value;
} Element;

void convertToSparse(int mat[10][10], int r, int c, Element sparse[]) {
    int k = 1;

    sparse[0].row = r;
    sparse[0].col = c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sparse[k].row   = i;
                sparse[k].col   = j;
                sparse[k].value = mat[i][j];
                k++;
            }
        }
    }
    sparse[0].value = k - 1;      // number of non-zero elements
}

void displaySparse(Element sparse[]) {
    for (int i = 0; i <= sparse[0].value; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

void addSparse(Element A[], Element B[], Element C[]) {
    int i = 1, j = 1, k = 1;

    C[0].row = A[0].row;
    C[0].col = A[0].col;

    while (i <= A[0].value && j <= B[0].value) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            C[k].row   = A[i].row;
            C[k].col   = A[i].col;
            C[k].value = A[i].value + B[j].value;
            i++;
            j++;
            k++;
        } else if (A[i].row < B[j].row ||
                  (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k].row   = A[i].row;
            C[k].col   = A[i].col;
            C[k].value = A[i].value;
            i++;
            k++;
        } else {
            C[k].row   = B[j].row;
            C[k].col   = B[j].col;
            C[k].value = B[j].value;
            j++;
            k++;
        }
    }

    while (i <= A[0].value) {
        C[k++] = A[i++];
    }
    while (j <= B[0].value) {
        C[k++] = B[j++];
    }

    C[0].value = k - 1;
}

void transposeSparse(Element mat[], Element trans[]) {
    int k = 1;

    trans[0].row   = mat[0].col;
    trans[0].col   = mat[0].row;
    trans[0].value = mat[0].value;

    for (int i = 0; i < mat[0].col; i++) {
        for (int j = 1; j <= mat[0].value; j++) {
            if (mat[j].col == i) {
                trans[k].row   = mat[j].col;
                trans[k].col   = mat[j].row;
                trans[k].value = mat[j].value;
                k++;
            }
        }
    }
}

int main() {
    int r, c, matA[10][10], matB[10][10];
    Element A[MAX], B[MAX], C[MAX], T[MAX];

    printf("Enter dimensions of matrix A: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    convertToSparse(matA, r, c, A);
    printf("Sparse matrix A:\n");
    displaySparse(A);

    printf("Enter dimensions of matrix B: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    convertToSparse(matB, r, c, B);
    printf("Sparse matrix B:\n");
    displaySparse(B);

    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        printf("Addition not possible.\n");
        return 0;
    }

    addSparse(A, B, C);
    printf("Sum of the matrices:\n");
    displaySparse(C);

    transposeSparse(C, T);
    printf("Transpose of the sum matrix:\n");
    displaySparse(T);

    return 0;
}
