#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Функція, що знаходить середнє арифметичне масиву
float average(float *arr, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Функція, що знаходить індекс найближчого елемента до заданого числа
int closest_index(float *arr, int size, float num) {
    float min_distance = fabs(num - arr[0]);
    int index = 0;
    for (int i = 1; i < size; i++) {
        float distance = fabs(num - arr[i]);
        if (distance < min_distance) {
            min_distance = distance;
            index = i;
        }
    }
    return index;
}

int one() {
    int n;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    // Виділення динамічної пам'яті для масиву
    float *arr = (float*) malloc(n * sizeof(float));

    // Заповнення масиву
    for (int i = 0; i < n; i++) {
        printf("Введіть %d-й елемент масиву: ", i + 1);
        scanf("%f", &arr[i]);
    }

    // Знаходження середнього арифметичного значення масиву
    float avg = average(arr, n);
    printf("Середнє арифметичне: %.2f\n", avg);

    // Знаходження індексу найбл до середнього арифметичного
    int index = closest_index(arr, n, avg);
    printf("Індекс: %d\n", index);

    // Звільнення динамічно виділеної пам'яті
    free(arr);
    return 0;
}