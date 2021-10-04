#include <stdio.h>
#include "array.h"

void arrIter(int* e) {
    printf("%d \n", *e);
}

int main(void)
{
    //int[10] arr;
    corsac_array* arr = corsac_new_array(sizeof(int));
    if (arr == NULL) {
        printf("ERROR \n");
    }

    //arr.push(1);
    corsac_array_push(arr, (void*)1);
    corsac_array_push(arr, (void*)2);
    corsac_array_push(arr, (void*)4);

    //arr[0] = 3;
    corsac_array_set(arr, 0, (void*)3);

    //arr[0];
    int *el = corsac_array_get(arr, 0);
    printf("%d \n", *el);

    int* el2 = corsac_array_pop(arr);
    printf("%d \n", *el2);

    corsac_array_remove(arr, 0);

    int *el3 = corsac_array_get(arr, 0);
    printf("%d \n", *el3);

    //clear arr;
    corsac_array_clear(arr);

    //delete arr;
    corsac_array_delete(arr);

    printf("Hello world!");

    return 0;
}