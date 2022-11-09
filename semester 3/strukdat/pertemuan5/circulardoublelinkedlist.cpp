#include <iostream>

using namespace std;

typedef struct snode_t {
    int data;
    snode_t *next, *prev;
} DListNode;

/* Struktur ADT CircularSinglyList */

typedef struct circularDList_t {
    unsigned _size;
    DListNode *_head;
    DListNode *_tail;
} CircularDoubleList;


void dlist_init(CircularDoubleList *list) 
{
    list->_head = NULL;
    list->_tail = NULL;
    list->_size = 0;
}

bool dlist_isEmpty(CircularDoubleList *list) {
    return (list->_head == NULL && list->_tail == NULL);
}

void dlist_pushFront(CircularDoubleList *list, int value) 
{
    DListNode *newNode = (DListNode*) malloc(sizeof(DListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (dlist_isEmpty(list)) 
        {
            list->_head = newNode;
            list->_tail = newNode;
        }
        else
        {
            newNode->next = list->_head;
            newNode->next->prev = newNode;
            list->_head = newNode;
            list->_tail->next = list->_tail;
        }
    }
}

void dlist_popFront(CircularDoubleList *list)
{
    if (!dlist_isEmpty(list)) 
    {
        DListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_head->prev = list->_tail;
        list->_size--;
    }
}

void dlist_pushBack(CircularDoubleList *list, int value)
{
    DListNode *newNode = (DListNode*) malloc(sizeof(DListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if (dlist_isEmpty(list)) 
        {
            list->_head = newNode;
            list->_tail = newNode;
        }
        // BATAS
        else 
        {
            DListNode *temp = list->_tail;
            temp->next = newNode;
            newNode->prev = temp;
            list->_tail = newNode;
            newNode->next = list->_head;
        }
    }
}

void dlist_popBack(CircularDoubleList *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *nextNode = list->_head->next;
        DListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = list->_head;
        free(nextNode);
        list->_size--;
    }
}

void dlist_insertAt(CircularDoubleList *list, unsigned index, int value) {
    if (index == 0)
    {
        dlist_pushFront(list, value);
        return;
    }
    else if (index >= list->_size)
    {
        dlist_pushBack(list, value);
        return;
    }
    // SListNode *newNode = createNode(value);
    DListNode *newNode = (DListNode*) malloc(sizeof(DListNode));
    newNode->data = value;

    if (newNode)
    {
        if (dlist_isEmpty(list) == true)
        {
            dlist_pushBack(list, value);
            return;
        }
        else
        {
            DListNode *temp = list->_head;

            unsigned i = 0;
            while (i < index - 1 && temp->next != NULL)
            {
                temp = temp->next;
                i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next->prev = newNode; // pointer prev dari temp-> next diarahkan ke newNode
            temp->next = newNode;  // pointer next dari temp diarahkan ke newNode
            newNode->prev = temp;
        }
    }
    list->_size++;
}

void printls(CircularDoubleList* list){
    DListNode* temp = list->_head;
    int i = 0;
    while (i<list->_size)
    {
        i++;
        cout << temp->data << " ";
        if(temp->next == NULL){
            break; 
        }
        temp = temp->next;
    }
    cout << endl;
}

void printls_reverse(CircularDoubleList* list){
    DListNode* temp = list->_tail;
    int i = 0;
    while (i<list->_size)
    {
        i++;
        cout << temp->data << " ";
        if(temp->prev == NULL){
            break; 
        }
        temp = temp->prev;
    }
    cout << endl;
}



int main() {
    CircularDoubleList list;
    dlist_init(&list);

    dlist_pushBack(&list, 2);
    dlist_pushBack(&list, 3);
    dlist_pushBack(&list, 5);
    dlist_pushFront(&list, 1);
    dlist_insertAt(&list, 3, 4);
    printls(&list);
    printls_reverse(&list);
}