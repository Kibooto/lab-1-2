#include <stdio.h>
#include <stdlib.h>

// функція для введення послідовності чисел
void enterSequence(float *a, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Введіть %d-й елемент послідовності: ", i+1);
        scanf("%f", &a[i]);
    }
}

// функція для виведення елементів масиву
void printArray(float *a, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

// функція для знаходження унікальних елементів масиву
void uniqueElements(float *a, int n) {
    int i, j, flag;
    printf("Унікальні елементи послідовності: ");
    for(i = 0; i < n; i++) {
        flag = 1;
        for(j = i+1; j < n; j++) {
            if(a[i] == a[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("%.2f ", a[i]);
        }
    }
    printf("\n");
}

// функція для знаходження груп однакових елементів та їх кількості
void identicalElements(float *a, int n) {
    int i, count = 1;
    printf("Групи однакових елементів:\n");
    for(i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            count++;
        }
        else {
            printf("%.2f - %d шт.\n", a[i-1], count);
            count = 1;
        }
    }
    printf("%.2f - %d шт.\n", a[n-1], count);
}

// функція для знаходження кількості унікальних елементів
void countUniqueElements(float *a, int n) {
    int i, j, count = 1;
    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(a[i] == a[j]) {
                break;
            }
        }
        if(i == j) {
            count++;
        }
    }
    printf("Кількість унікальних елементів: %d\n", count);
}

// функція для знаходження кількості елементів, що повторюються
void countRepeatedElements(float *a, int n) {
    int i, j, count = 0;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++){
		    if(a[i] == a[j]) {
			    count++;
			    break;
		    }
	    }
    }
    printf("Кількість елментів що повторюються %d\n", count);
}

int four(){
    int n;
    float *a;
    printf("Введіть кількість елементів послідовності: ");
    scanf("%d", &n);

    a = (float*) malloc(n * sizeof(float));

    enterSequence(a, n);

    printArray(a, n);
    
    uniqueElements(a, n);

    identicalElements(a, n);

    countUniqueElements(a, n);

    countRepeatedElements(a, n);

    free(a);

return 0;

}
