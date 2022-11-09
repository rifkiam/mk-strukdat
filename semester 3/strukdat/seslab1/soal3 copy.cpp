#include <iostream>
#include <string>
using namespace std;

/*DYNAMIC ARRAY*/

struct dynamicarray {
    unsigned _size, _capacity;
    char **_array;
};

void dArray_init(dynamicarray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_array = (char**) malloc(darray->_capacity * sizeof(*darray->_array));
}

bool dArrayOfString_isEmpty(dynamicarray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(dynamicarray *darray, char *newChar)
{
    if (darray->_size + 1 >= darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        char **newArr = (char**) malloc(sizeof(*darray->_array) * darray->_capacity);

        for (it = 0; it < darray->_size; ++it)
        {
            newArr[it] = darray->_array[it];
        }
        
        char **oldArray = darray->_array;
        darray->_array = newArr;
        free(oldArray);
    }
    darray->_array[darray->_size++] = newChar;
}

void dArray_printAll(dynamicarray *darray) {
    for(unsigned i = 0; i < darray->_size; i++) {
        // printf(" [%d] %s\n", i, darray->_array[i]);
        cout << i+1 << ". " << darray->_array[i] << endl;
    }
}


int main() {
    dynamicarray array;
    dArray_init(&array);
    dArray_pushBack(&array, "Rifqi");
    dArray_pushBack(&array, "Riki");
    dArray_pushBack(&array, "Rafly");
    dArray_pushBack(&array, "Rendy");
    dArray_printAll(&array);
}