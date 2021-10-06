// Copyright (c) 2021 Corsac Team
// License: MIT License
// MIT License web page: https://opensource.org/licenses/MIT
#include "sparse_set.h"

corsac_sparse_set* corsac_sparse_set_new()
{
    corsac_sparse_set* set = malloc(sizeof(corsac_sparse_set));
    if (set == NULL) corsac_panic("Falled memory allocate!");

    set->packed = corsac_slice(uint32_t);
    set->sparse = corsac_slice(uint32_t);

    return set;
}

void corsac_sparse_set_add(corsac_sparse_set* sparce_set, uint32_t x)
{
    if (x >= corsac_slice_capacity(sparce_set->sparse)) _corsac_slice_grow(sparce_set->sparse, x * 2);

    if (corsac_sparse_set_has(sparce_set, x))
        corsac_panic("This number already exist!")

    sparce_set->sparse[x] = corsac_slice_size(sparce_set->packed);
    corsac_slice_push(sparce_set->packed, x);
}

void corsac_sparse_set_remove(corsac_sparse_set* sparce_set, uint32_t x)
{
    if (!corsac_sparse_set_has(sparce_set, x))
        corsac_panic("This number does not exist!")

    uint32_t index = sparce_set->sparse[x];
    uint32_t swap = corsac_slice_pop(sparce_set->packed);
    if (swap != x)
    {
        sparce_set->packed[index] = swap;
        sparce_set->sparse[swap] = index;
    }
}

void corsac_sparse_set_free(corsac_sparse_set* sparce_set)
{
    corsac_slice_free(sparce_set->packed);
    corsac_slice_free(sparce_set->sparse);
    free(sparce_set);
}