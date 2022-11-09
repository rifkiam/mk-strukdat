#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct numList {
    int num;
    struct numList *next;
};

typedef struct slist_t {
    unsigned _size;
    numList *_head;
} SinglyList;


bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
};

numList *head, *tail, *cur, *before, *newNode, *del;

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

void slist_pushBack(SinglyList *list, int value)
{
    numList *newNode = (numList*) malloc(sizeof(numList));
    if (newNode) {
        list->_size++;
        newNode->num = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            numList *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}


void remove(int index, SinglyList *list){
    if(slist_isEmpty(list)){
        return;
    }

    numList *new_node = (numList*) malloc(sizeof (numList));
    if(new_node){
        numList* temp = list->_head;
        int i = 0;

        while (i < index-1) {
            temp = temp->next;
            i++;
        }

        numList* temp2 = temp->next;
        temp->next = temp2->next;

        free(temp2);
    }
}

void printElements(SinglyList *list){
    numList* temp = list->_head;
    while (true)
    {
        cout << temp->num << " ";
        if(temp->next == NULL){
            break; 
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    SinglyList myList;
    slist_init(&myList);
    int s,M,N ;
    cin >> s;
    cin >> M >> N;

    while(s--){
        int temp;
        cin >> temp;
        slist_pushBack(&myList, temp);
    }


    while(N--){
        remove(M, &myList);
    }

    printElements(&myList);
    
    return 0;
}

