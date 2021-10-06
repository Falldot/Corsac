
#include <stdio.h>
#include <stdlib.h>

#include "slice.h"
#include "sparse_set.h"

int main(void)
{
    corsac_sparse_set* set = corsac_sparse_set_new();

    corsac_sparse_set_add(set, 6);
    corsac_sparse_set_add(set, 2);
    corsac_sparse_set_add(set, 3);
    corsac_sparse_set_add(set, 22);
    corsac_sparse_set_add(set, 80);


    corsac_sparse_set_remove(set, 2);
    corsac_sparse_set_remove(set, 80);

    printf("has %d   : %lu\n", corsac_sparse_set_has(set, 6), 6);
    printf("has %d   : %lu\n", corsac_sparse_set_has(set, 2), 2);
    printf("has %d   : %lu\n", corsac_sparse_set_has(set, 3), 3);
    printf("has %d   : %lu\n", corsac_sparse_set_has(set, 22), 22);
    printf("has %d   : %lu\n", corsac_sparse_set_has(set, 80), 80);

    // corsac_sparse_set* set = corsac_sparse_set_new();

    // printf("size    : %lu\n", set->size);

    // corsac_slice* slice = corsac_slice_new(sizeof(int));
    // if (slice == NULL) {
    //     printf("ERROR \n");
    // }

    // corsac_slice_push(slice, (void*)1);
    // corsac_slice_push(slice, (void*)2);
    // corsac_slice_push(slice, (void*)4);

    // corsac_slice_set(slice, 0, (void*)3);

    // corsac_slice* slice2 = corsac_slice_splice(slice, 1);

    // for (size_t i = 0; i < corsac_slice_lenght(slice2); i++)
    // {
    //     int *el = corsac_slice_get(slice2, i);
    //     printf("%d \n", *el);
    // }

    corsac_sparse_set_free(set);

    //delete arr;
    //corsac_slice_delete(slice);
    //corsac_slice_delete(slice2);

    printf("Hello world!");

    return 0;
}