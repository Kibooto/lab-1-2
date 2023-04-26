#include <stdio.h>
#include <stdlib.h>

// Функція для створення динамічної матриці
int **createMatrix(int rows, int cols) {
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }
    return matrix;
}

// Функція для звільнення памяті для динамічної матриці
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функція для додавання двох матриць
void addMatrices(int **A, int **B, int **C, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void pprintArray(int **arr, int rows, int cols) {
        // Виведення елементів матриці на екран
    printf("Елементи матриці C (сума елементів матриць A та B):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int rows, cols;
    printf("Введіть розмір матриць: ");
    scanf("%d %d", &rows, &cols);

    // Створення матриць A та B
    int **A = createMatrix(rows, cols);
    int **B = createMatrix(rows, cols);

    // Ввід елементів матриць 
    printf("Введіть елементи матриці A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Введіть елементи матриці B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Створення матриці та додавання матриць
    int **C = createMatrix(rows, cols);
    
    addMatrices(A, B, C, rows, cols);

    pprintArray(C, rows, cols);

    freeMatrix(A, rows);
    freeMatrix(B, rows);
    freeMatrix(C, rows);
}