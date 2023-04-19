#include <stdio.h>
#include <stdlib.h>

int* readArray(int* size) {
    printf("Enter array size: ");
    scanf("%d", size);

    int* arr = (int*)malloc(*size * sizeof(int));

    printf("Enter array elements: ");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}

void pprintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* intersection(int* arr1, int size1, int* arr2, int size2, int* size3) {
    int* arr3 = (int*)malloc(*size3 * sizeof(int));
    *size3 = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[*size3] = arr1[i];
                (*size3)++;
                break;
            }
        }
    }

    return arr3;
}

int sum(int* arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += arr[i];
    }
    return result;
}

int max(int* arr, int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > result) {
            result = arr[i];
        }
    }
    return result;
}

int three() {
    int n, m;
    int* A = readArray(&n);
    int* B = readArray(&m);

    int sizeC = 0;
    int* C = intersection(A, n, B, m, &sizeC);

    printf("Array A: ");
    pprintArray(A, n);

    printf("Array B: ");
    pprintArray(B, m);

    printf("Intersection of A and B: ");
    pprintArray(C, sizeC);

    printf("Sum of intersection: %d\n", sum(C, sizeC));
    printf("Max element of intersection: %d\n", max(C, sizeC));

    free(A);
    free(B);
    free(C);

    return 0;
}