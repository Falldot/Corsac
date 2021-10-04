#include "array.h"

corsac_array* corsac_new_array(size_t type_size)
{
	corsac_array* arr = (corsac_array*)malloc(sizeof(corsac_array));
	if (arr == NULL) {
		return NULL;
	}

	arr->_data = (void**)malloc(INIT_CORSAC_ARRAY_SIZE * sizeof(void*));
	if (arr->_data == NULL) {
		free(arr);
		return NULL;
	}

	arr->_current_size = 0;
	arr->_max_size = INIT_CORSAC_ARRAY_SIZE;
	arr->_type_size = type_size;

	return arr;
}

void corsac_array_delete(corsac_array* arr)
{
	if (arr != NULL)
	{
		for (size_t i = 0; i < arr->_current_size; i++)
			free(arr->_data[i]);
		free(arr->_data);
		arr->_current_size = 0;
		free(arr);
	}
}

size_t corsac_array_lenght(corsac_array* arr)
{
	return arr->_current_size;
}

void corsac_array_push(corsac_array* arr, void* data)
{
	if (arr->_current_size >= arr->_max_size)
	{
		corsac_array_resize(arr, arr->_max_size*2);
	}

	arr->_data[arr->_current_size] = (void*)malloc(arr->_type_size);
	memcpy(arr->_data[arr->_current_size], &data, arr->_type_size);

	arr->_current_size++;
}

void* corsac_array_get(corsac_array* arr, size_t index)
{
	if (index < 0 || index > arr->_current_size-1 || arr->_current_size <= 0)
		return NULL;
	return (void*)arr->_data[index];
}

int corsac_array_set(corsac_array* arr, size_t index, void* data)
{
	if (index >= 0 && index < arr->_current_size)
	{
		memcpy(arr->_data[index], &data, arr->_type_size);
		return 1;
	}
	return 0;
}

int corsac_array_cut(corsac_array* arr, size_t index)
{
	if (index < 0 || index > arr->_current_size - 1 || arr->_current_size <= 0)
		return 0;
	
	free(arr->_data[index]);

	for (size_t i = index; i < arr->_current_size; i++)
		arr->_data[i] = arr->_data[i + 1];
	
	arr->_current_size--;
	return 1;
}

int corsac_array_remove(corsac_array* arr, size_t index)
{
	if (index < 0 || index > arr->_current_size - 1 || arr->_current_size <= 0)
		return 0;

	memcpy(arr->_data[index], arr->_data[arr->_current_size - 1], arr->_type_size);
	free(arr->_data[arr->_current_size - 1]);

	arr->_current_size--;
	return 1;
}

void* corsac_array_pop(corsac_array* arr)
{ 
	if (arr->_current_size <= 0)
		return NULL;
	arr->_current_size--;
	return (void*)arr->_data[arr->_current_size];
}

void corsac_array_clear(corsac_array* arr)
{
	arr->_current_size = 0;
}

void corsac_array_resize(corsac_array* arr, size_t max_size)
{
	arr->_max_size = max_size;
	arr->_data = realloc(arr->_data, max_size * sizeof(void*));
}