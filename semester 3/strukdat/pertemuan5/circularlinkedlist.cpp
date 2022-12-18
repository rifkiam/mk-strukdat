#include <iostream>
using namespace std;

typedef struct snode_t {
    int data;
    snode_t *next;
} SListNode;

/* Struktur ADT CircularSinglyList */

typedef struct circularSList_t {
    unsigned _size;
    SListNode *_head;
    SListNode *_tail;
} CircularSinglyList;


void slist_init(CircularSinglyList *list) 
{
    list->_head = NULL;
    list->_tail = NULL;
    list->_size = 0;
}

bool slist_isEmpty(CircularSinglyList *list) {
    return (list->_head == NULL && list->_tail == NULL);
}

void slist_pushFront(CircularSinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) 
        {
            list->_head = newNode;
            list->_tail = newNode;
        }
        else
        {
            newNode->next = list->_head;
            list->_head = newNode;
            list->_tail->next = list->_head;
        }
    }
}

void slist_popFront(CircularSinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(CircularSinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        return (list->_head->data);
    }
    return 0;
}

void slist_pushBack(CircularSinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
        {
            list->_head = newNode;
            list->_tail = newNode;
            // newNode->next = list->_head;
        }
        else 
        {
            SListNode *temp = list->_tail;
            temp->next = newNode;
            list->_tail = newNode;
            newNode->next = list->_head;
        }
    }
}

void slist_popBack(CircularSinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

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

void slist_insertAt(CircularSinglyList *list, unsigned index, int value) {
    if (index == 0)
    {
        slist_pushFront(list, value);
        return;
    }
    else if (index >= list->_size)
    {
        slist_pushBack(list, value);
        return;
    }
    // SListNode *newNode = createNode(value);
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    newNode->data = value;

    if (newNode)
    {
        if (slist_isEmpty(list) == true)
        {
            slist_pushBack(list, value);
            return;
        }
        else
        {
            SListNode *temp = list->_head;

            unsigned i = 0;
            while (i < index - 1 && temp->next != NULL)
            {
                temp = temp->next;
                i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    list->_size++;
}

void printls(CircularSinglyList* list){
    SListNode* temp = list->_head;
    int i = 0;
    while (i < list->_size)
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

int main()
{
    CircularSinglyList list;
    slist_init(&list);

    slist_pushFront(&list, 3); // add di depan
    slist_pushFront(&list, 4);
    slist_pushFront(&list, 5);
    slist_pushFront(&list, 7);
    slist_insertAt(&list, 1, 6); // add di tengah
    slist_pushBack(&list, 2); // add di belakang
    printls(&list);
    return 0;
}
