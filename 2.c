#include <stdio.h>
#include <stdlib.h>

int find_min_positive(int *arr, int n) {
    int i, *ptr, min_pos;
    ptr = NULL;
    min_pos = -1;

    for (i = 0; i < n; i++) {
        if (arr[i] > 0 && (i == 0 || i % 5 != 0)) {
            if (ptr == NULL || arr[i] < *ptr) {
                ptr = &arr[i];
                min_pos = i;
            }
        }
    }

    return min_pos;
}

void input_array(int *arr, int n) {
    int i;
    printf("Введіть елементи масиву: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]+1);
    }
}

void output_result(int min_pos) {
    if (min_pos == -1) {
        printf("У масиві немає додатніх елементів, що передують першому елементу, кратному п'яти.\n");
    } else {
        printf("Номер першого мінімального додатнього елемента: %d\n", min_pos);
    }
}

int two() {
    int n, *arr, min_pos;

    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    input_array(arr, n);

    min_pos = find_min_positive(arr, n);
    output_result(min_pos);

    free(arr);
    
    return 0;
}
