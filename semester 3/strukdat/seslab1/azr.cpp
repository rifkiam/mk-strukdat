#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct dynamicArray {
    unsigned _size, _capacity;
    char **_array;
};

void dynamicArray_init(dynamicArray *darray) {
    darray->_size = 0u;
    darray->_capacity = 2u;
    darray->_array = (char**) malloc(darray->_capacity * sizeof(*darray->_array));
}

bool dynamicArray_isEmpty(dynamicArray *darray) {
    return (darray->_size == 0);
}

void dynamicArray_memExpand(dynamicArray *darray) {
    darray->_capacity *= 2;
    char **newArray = (char **)malloc(darray->_capacity * sizeof(*darray->_array));

    unsigned it;
    for (it = 0; it < darray->_size; it++) {
        newArray[it] = darray->_array[it];
    }

    char **oldArray = darray->_array;
    darray->_array = newArray;
    free(oldArray);
}

void dynamicArray_push(dynamicArray *darray, char *string) {
    if (darray->_size + 1 >= darray->_capacity) {
        dynamicArray_memExpand(darray);
    }

    darray->_array[darray->_size++] = string;
}

void dynamicArray_insertAt(dynamicArray *darray, unsigned int index, char *string) {
    if (index > darray->_size) {
        printf("Gagal insert \"%s\" di index ke-%d\n", string, index);
        return;
    }

    if (darray->_size + 1 >= darray->_capacity) {
        dynamicArray_memExpand(darray);
    }

    if (darray->_array[index] != NULL) {
        memmove(&darray->_array[index+1], &darray->_array[index], (&darray->_array[darray->_size] - &darray->_array[index]) * sizeof(*darray));
        darray->_array[index] = string;
        darray->_size++;
    } else {
        darray->_array[index] = string;
        darray->_size++;
    }
}

void dynamicArray_removeAt(dynamicArray *darray, unsigned index) {
    if(index > darray->_size) {
        printf("Gagal remove data di index ke-%d\n", index);
        return;
    }

    memmove(&darray->_array[index], &darray->_array[index+1], (&darray->_array[darray->_size] - &darray->_array[index]) * sizeof(*darray));
    darray->_array[darray->_size] = "";
    darray->_size--;
}

void dynamicArray_printAll(dynamicArray *darray) {
    for(unsigned i = 0; i < darray->_size; i++) {
        printf(" [%d] %s\n", i, darray->_array[i]);
    }
}
int main() {
    dynamicArray darray;
    dynamicArray_init(&darray);
    dynamicArray_push(&darray, "Apple");
    dynamicArray_push(&darray, "Orange");
    dynamicArray_push(&darray, "Melon");
    dynamicArray_insertAt(&darray, 0, "Kacang");
    dynamicArray_insertAt(&darray, 1, "Kacang");
    dynamicArray_removeAt(&darray, 0);
    dynamicArray_insertAt(&darray, 5, "Permen");

    printf("Array Information :\n");
    printf("  Capacity : %d\n", darray._capacity);
    printf("  Size : %d\n", darray._size);
    printf("\nArray Contents :\n");
    dynamicArray_printAll(&darray);

    
    return 0;
}