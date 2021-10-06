// Copyright (c) 2021 Corsac Team
// License: MIT License
// MIT License web page: https://opensource.org/licenses/MIT
#pragma once

// malloc, realloc, free
#include <malloc.h>

#include "panic.h"

/***** PUBLIC *****/

#define corsac_slice(type)                                                      \
	({                                                                          \
        type * slice = NULL;                                                    \
		const size_t slc_size = 4 * sizeof(*slice) + (sizeof(size_t) * 2);      \
        size_t* meta = malloc(slc_size);                                        \
        if (meta == NULL) corsac_panic("Falled memory allocate!");              \
        slice = (void*)&meta[2];                                                \
        _corsac_slice_set_capacity(slice, 4);                                   \
        _corsac_slice_set_size(slice, 0);                                       \
        slice;                                                                  \
    })

#define corsac_slice_capacity(slice) ((size_t *)(slice))[-1]

#define corsac_slice_size(slice) ((size_t *)(slice))[-2]

#define corsac_slice_pop(slice) \
	({                                                          \
        _corsac_slice_set_size(slice, corsac_slice_size(slice) - 1);   \
        slice[corsac_slice_size(slice)];                        \
    })

#define corsac_slice_push(slice, value) \
	{                                                       \
        size_t cap = corsac_slice_capacity(slice);          \
        size_t size = corsac_slice_size(slice);             \
        if (cap <= size) _corsac_slice_grow(slice, cap * 2);\
        slice[size] = value;                                \
        _corsac_slice_set_size(slice, size + 1);            \
    }

#define corsac_slice_free(slice) \
	{                                               \
        size_t *data = &((size_t *)(slice))[-2];    \
        free(data);                                 \
	}

/***** PRIVATE *****/

#define _corsac_slice_set_capacity(slice, size) \
		if (slice) ((size_t *)(slice))[-1] = (size);

#define _corsac_slice_set_size(slice, size) \
		if (slice) ((size_t *)(slice))[-2] = (size);


#define _corsac_slice_grow(slice, size) \
	{                                                                           \
        const size_t slc_size = size * sizeof(*slice) + (sizeof(size_t) * 2);   \
        size_t* meta = &((size_t *)slice)[-2];                                  \
        size_t* data = realloc(meta, slc_size);                                 \
        if (data == NULL) corsac_panic("Falled memory reallocate!");            \
        slice = (void*)&data[2];                                                \
        _corsac_slice_set_capacity(slice, size);                                \
    }
