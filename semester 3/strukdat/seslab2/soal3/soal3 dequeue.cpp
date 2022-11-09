#include <iostream>
#include <string>

using namespace std;

typedef struct dnode_t
{
    string data;
    struct dnode_t *next, *prev;
} DListNode;

typedef struct dlist
{
    DListNode *_head, *_tail;
    unsigned _size;
} Dequeue;

DListNode *createNode(string value)
{
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
    if (!newNode)
    {
        return NULL;
    }
    else
    {
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
    }

    return (DListNode *)newNode;
}

void dlist_init(Dequeue *dequeue)
{
    dequeue->_head = NULL;
    dequeue->_tail = NULL;
    dequeue->_size = 0;
}

bool dlist_isEmpty(Dequeue *dequeue)
{
    return (dequeue->_head == NULL && dequeue->_tail == NULL);
}

void pushFront(Dequeue *dequeue, string value)
{
    DListNode *newNode = createNode(value);
    if (newNode)
    {
        if (dlist_isEmpty(dequeue))
        {
            dequeue->_head = newNode;
            dequeue->_tail = newNode;
        }
        else
        {
            newNode->next = dequeue->_head;
            dequeue->_head->prev = newNode;
            dequeue->_head = newNode;
        }
    }
    dequeue->_size++;
}

void popFront(Dequeue *dequeue)
{

    if (!dlist_isEmpty(dequeue))
    {
        DListNode *temp = dequeue->_head;
        if (dequeue->_head == dequeue->_tail)
        {
            dequeue->_head = NULL;
            dequeue->_tail = NULL;
            free(temp);
        }
        else
        {
            dequeue->_head = dequeue->_head->next;
            dequeue->_head->prev = NULL;
            free(temp);
        }
    }
    dequeue->_size--;
}

void pushBack(Dequeue *dequeue, string value)
{
    DListNode *newNode = createNode(value);
    if (newNode)
    {
        if (dlist_isEmpty(dequeue))
        {
            dequeue->_head = newNode;
            dequeue->_tail = newNode;
            return;
        }

        else
        {
            dequeue->_tail->next = newNode;
            newNode->prev = dequeue->_tail;
            dequeue->_tail = newNode;
        }
    }
    dequeue->_size++;
}

void popBack(Dequeue *dequeue)
{
    DListNode *temp = dequeue->_tail;
    if (dequeue->_head == dequeue->_tail)
    {
        dequeue->_head = NULL;
        dequeue->_tail = NULL;
        free(temp);
    }
    else
    {
        dequeue->_tail = dequeue->_tail->prev;
        dequeue->_tail->next = NULL;
        free(temp);
    }
    dequeue->_size--;
}


int main()
{
    Dequeue list;
    dlist_init(&list);

    pushFront(&list, "Rifqi Akhmad"); // add antrian di depan
    pushFront(&list, "Rendy Anfi"); 
    pushFront(&list, "Dzakirozaan"); 
    pushFront(&list, "Ilham Yumna");
    pushBack(&list, "Athaya Reyhan"); // add antrian di belakang

    DListNode *currNode = list._head;
    // cout << list._head->data;
    while (currNode != NULL)
    {
        cout << currNode->data << endl;
        currNode = currNode->next;
    }
    // pushFront(&list, 8);
    // pushFront(&list, 9);
    // pushFront(&list, 10);

    // while (!dlist_isEmpty(&list))
    // {
    //     cout << dlist_front(&list) << endl;
    //     popFront(&list);
    // }
    return 0;
}