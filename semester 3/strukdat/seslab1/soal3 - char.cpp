#include <iostream>
#include <string>
using namespace std;

/*DYNAMIC ARRAY*/

struct dynamicarray {
    char *_arr;
    unsigned _size, _capacity;
};

void dArray_init(dynamicarray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (char*) malloc(sizeof(char) * 2);
}

void dArray_pushBack(dynamicarray *darray, char newChar)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        char *newArr = (char*) malloc(sizeof(char) * darray->_capacity);

        for (it = 0; it < darray->_size; ++it)
        {
            newArr[it] = darray->_arr[it];
        }
        
        char *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = newChar;
    cout << darray->_arr[darray->_size+1] << endl;
}

/*LINKED LIST*/

struct charList {
    char word[100];
    struct charList *next;
};
charList *head, *tail, *cur, *before, *newNode, *del;

void createSingleLinkedList(char newChar){
    head = new charList();
    head->word = newChar;
    head->next = NULL;
    tail = head;
}

void addFirst(char newChar){
  newNode = new charList();
  newNode->word = newChar;
  newNode->next = head;
  head = newNode;
}

void addLast(char newChar){
  newNode = new charList();
  newNode->word = newChar;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void printElement(){
    while (cur != NULL)
    {
        cout << cur->word << endl;
    }
}

int main() {
    dynamicarray array;
    dArray_init(&array);
    dArray_pushBack(&array, "Rifqi");
    dArray_pushBack(&array, "Riki");
    dArray_pushBack(&array, "Rafly");
    dArray_pushBack(&array, "Rendy");
    for (int i = 0; i < array._size; i++)
    {
        cout << array._arr[i] << endl;
    }

    cout << endl;

    createSingleLinkedList("Rifqi");
    addLast("Riki");
    addLast("Rafly");
    addLast("Rendy");
    printElement();
}