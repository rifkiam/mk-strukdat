#include <iostream>
#include <string>
using namespace std;

struct dynamicarray {
    int *_arr;
    unsigned _size, _capacity;
};
// dynamicarray array;

void dArray_init(dynamicarray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(dynamicarray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(dynamicarray *darray, int value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it = 0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

void dArray_insertAt(dynamicarray *darray, unsigned index, int value){
    int *newArr;
    unsigned indexIt;
    if (darray->_arr[index] == NULL)
    {
        darray->_arr[index] = value;
    }
    else
    {
        if (darray->_size + 1 > darray->_capacity) 
        {
            darray->_capacity *= 2;
            newArr = (int*) malloc(sizeof(int) * darray->_capacity);

            for (indexIt = (darray->_size-1); index <= indexIt; --indexIt)
            {
                newArr[indexIt+1] = darray->_arr[indexIt];
            }
            newArr[index] = value;
            for (indexIt = 0; indexIt < index; indexIt++)
            {
                newArr[indexIt] = darray->_arr[indexIt];
            }

            int *oldArray = darray->_arr;
            darray->_arr = newArr;
            free(oldArray);
            
            // while (it != (pos-1))
            // {
            //     it++;
            // }
            // newArr[it] = darray->_arr[it];
        }
    else
    {
        for (indexIt = (darray->_size-1); index <= indexIt; --indexIt)
        {
            newArr[indexIt+1] = darray->_arr[indexIt];
            // cout << darray->_arr[indexIt+1] << endl;
        }
        newArr[index] = value;
        for (indexIt = 0; indexIt < index; indexIt++)
        {
            newArr[indexIt] = darray->_arr[indexIt];
            // cout << darray->_arr[indexIt] << endl;
        }
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    }
    
    
    
}
void dArray_removeAt(dynamicarray *darray, unsigned index){
    // if (darray->_arr[index] == NULL)
    // {
    //     darray->_arr[index]
    // }
    for (int i = index; i < (darray->_size-1); i++)
    {
        darray->_arr[i] = darray->_arr[i+1];
    }
    darray->_size--;
}

int main() {
    dynamicarray array;
    dArray_init(&array);
    dArray_pushBack(&array, 10);
    dArray_pushBack(&array, 11);
    dArray_pushBack(&array, 12);
    dArray_pushBack(&array, NULL); // index 3 bernilai NULL
    dArray_pushBack(&array, 14);
    dArray_pushBack(&array, 15);
    dArray_pushBack(&array, 16);
    dArray_pushBack(&array, 17);
    dArray_insertAt(&array, 3, 5); //(arr, index, value to insert), karena index 3 bernilai NULL maka tinggal memasukkan
    dArray_insertAt(&array, 4, 8);
    dArray_removeAt(&array, 6); // menghapus array index 6 setelah 2 operasi insertAt sebelumnya
    for (int i = 0; i < array._size; i++)
    {
        cout << array._arr[i] << endl;
    }

    return 0;
}