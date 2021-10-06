# Slice - Срез

Динамический массив. Индексируеться и имеет длину. В отличии от массива автоматически изменяет свою длину при добавлении нового элемента. По умолчанию выделяеться память для 4 элементов. Последующие расширения в 2 раза. 

## Инициализация среза
```c
    // C
    corsac_slice* slice = corsac_new_slice(sizeof(int));
```
```c
    // Corsac
    int slice = [];
```
## Инициализация среза из массива
```c
    // C
   
```
```go
    // Corsac
    int[10] arr = {5, 3, 10, 11, 5, 3, 1, 9, 44, 178};

    int[] slice = arr[0:5];
```
## Получить длину среза
```c
    // C
    int lenght = corsac_slice_lenght(slice);
```
```go
    // Corsac
    int lenght = len(slice);
```
## Добавить новый элемент в конец среза
```c
    // C
    corsac_slice_push(slice, 1);
```
```js
    // Corsac
    slice.push(1);
```
## Установить значение элемента среза по индексу
```c
    // C
    corsac_slice_set(slice, 0, 3);
```
```c
    // Corsac
    slice[0] = 3;
```
## Получить значение элемента среза по индексу
```c
    // C
    int* el = corsac_slice_get(slice, 0);
```
```go
    // Corsac
    int el = slice[0];
```
## Удалить и получить последнего элемента среза
```c
    // C
    int* el = corsac_slice_pop(slice);
```
```c
    // Corsac
    int el = slice.pop();
```
## Удалить улемент среза с сохранением порядка
```c
    // C
    corsac_slice_remove(slice, 0);
```
```c
    // Corsac
    slice.remove(0)
```
## Удалить улемент среза без сохранения порядка
```c
    // C
    corsac_slice_remove(slice, 0);
```
```c
    // Corsac
    slice.fastRemove()
```
## Очистка данных среза с сохранением выделенной памяти
```c
    // C
    corsac_slice_clear(slice);
```
```js
    // Corsac
    clear slice;
```
## Удаление среза с освобождение выделенной памяти
```c
    // C
    corsac_slice_delete(slice);
```
```js
    // Corsac
    delete(slice)
```