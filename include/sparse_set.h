// Copyright (c) 2021 Corsac Team
// License: MIT License
// MIT License web page: https://opensource.org/licenses/MIT
#pragma once

#include <stddef.h>

#include "slice.h"
#include "panic.h"

/***** PUBLIC *****/

typedef unsigned long uint32_t;

typedef struct {
    uint32_t* packed;
    uint32_t* sparse;
} corsac_sparse_set;

#define corsac_sparse_set_has(sparce_set, x) \
    (sparce_set->sparse[x] < corsac_slice_size(sparce_set->packed) && sparce_set->sparse[x] >= 0 && sparce_set->packed[sparce_set->sparse[x]] == x)


int gou(corsac_sparse_set* sparce_set, uint32_t x);

corsac_sparse_set* corsac_sparse_set_new();

void corsac_sparse_set_add(corsac_sparse_set* sparce_set, uint32_t x);

void corsac_sparse_set_remove(corsac_sparse_set* sparce_set, uint32_t x);

void corsac_sparse_set_free(corsac_sparse_set* sparce_set);

/***** PRIVATE *****/
