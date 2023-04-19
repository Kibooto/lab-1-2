#include <stdio.h>
#include <stdlib.h>
#include "1.c"
#include "2.c"
#include "3.c"
#include "4.c"

int main(){
    int z = 0, flag = 1;
    while(flag){
        printf("Оберіть завдання: ");
        scanf("%d", &z);
        switch (z)
        {
        case 1 :
            one();
            break;
        
        case 2 :
            two();
            break;

        case 3 :
            three();
            break;

        case 4 :
            four();
            break;

        case 0 :
            flag = 0;
            break;

        default:
            printf("Введіть число від 0 до 4");
            break;
        }
    }
}