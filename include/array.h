#ifndef CORSAC_ARRAY_H
#define CORSAC_ARRAY_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#define INIT_CORSAC_ARRAY_SIZE 4

typedef struct {
    void** _data;
    size_t _max_size;
    size_t _current_size;
    size_t _type_size;
} corsac_array;

corsac_array* corsac_new_array(size_t type_size);

void corsac_array_delete(corsac_array* arr);

size_t corsac_array_lenght(corsac_array* arr);

void corsac_array_push(corsac_array* arr, void* data);

int corsac_array_set(corsac_array* arr, size_t index, void* data);

void* corsac_array_get(corsac_array* arr, size_t index);

int corsac_array_cut(corsac_array* arr, size_t index);

int corsac_array_remove(corsac_array* arr, size_t index);

void* corsac_array_pop(corsac_array* arr);

void corsac_array_clear(corsac_array* arr);

void corsac_array_resize(corsac_array* arr, size_t max_size);

#endif