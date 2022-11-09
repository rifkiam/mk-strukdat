#include <iostream>
#include <string>
using namespace std;

struct dynamicarray {
    int *_arr;
    unsigned _size, _capacity;
};

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

int main() {
    dynamicarray array;
    dArray_init(&array);
    int input[1000];

    for (int i = 0; i < 1000; i++)
    {
        cin >> input[i];
        int temp = input[i];
        array->_arr[i] = temp;
    }

    int smallest = array->_arr[0];

    for (int i = 0; i < 1000; i++) {
        if (array->_arr[i] == 0)
        {
            break;
        }
        
        if (array->_arr[i] < smallest) 
        {
            smallest = array->_arr[i];
        }
   }
   cout << smallest;
}

#include <iostream>
#include <string>
using namespace std;

struct dynamicarray {
    int *_arr;
    unsigned _size, _capacity;
};

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

int main()
{

    dynamicarray myArray;
    dArray_init(&myArray);

    int count = 100000;
    int temp = 0;

    while(true){

        cin >> temp;
        if(temp == 0) break;
        if (temp<count) count = temp;
        dArray_pushBack(&myArray, temp);
    }
    cout << count ;
    return 0;

//     dynamicarray array;
//     dArray_init(&array);
//     int input[10000];

//     for (int i = 0; i < 1000; i++)
//     {
//         cin >> input[i];
//         array->_arr[i] = input[i];
//     }

//     int smallest = array->_arr[0];

//     for (int i = 0; i < 1000; i++) {
//         if (array->_arr[i] == 0)
//         {
//             break;
//         }
        
//         if (array->_arr[i] < smallest) 
//         {
//             smallest = array->_arr[i];
//         }
//    }
//    cout << smallest;
}