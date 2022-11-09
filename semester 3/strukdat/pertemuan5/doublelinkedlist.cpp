#include <iostream>
#include <string>

using namespace std;

typedef struct dnode_t
{
    int data;
    struct dnode_t *next, *prev;
} DListNode;

typedef struct dlist
{
    DListNode *_head, *_tail;
    unsigned _size;
} DLinkedList;

DListNode *createNode(int value)
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

void dlist_init(DLinkedList *doubleLinked)
{
    doubleLinked->_head = doubleLinked->_tail = NULL;
    doubleLinked->_size = 0;
}

bool dlist_isEmpty(DLinkedList *doubleLinked)
{
    return (doubleLinked->_head == NULL && doubleLinked->_tail == NULL);
}

void pushFront(DLinkedList *doublelinked, int value)
{
    DListNode *newNode = createNode(value);
    if (newNode)
    {
        if (dlist_isEmpty(doublelinked))
        {
            doublelinked->_head = newNode;
            doublelinked->_tail = newNode;
        }
        else
        {
            newNode->next = doublelinked->_head;
            doublelinked->_head->prev = newNode;
            doublelinked->_head = newNode;
        }
    }
    doublelinked->_size++;
}

void popFront(DLinkedList *doublelinked)
{

    if (!dlist_isEmpty(doublelinked))
    {
        DListNode *temp = doublelinked->_head;
        if (doublelinked->_head == doublelinked->_tail)
        {
            doublelinked->_head = NULL;
            doublelinked->_tail = NULL;
            free(temp);
        }
        else
        {
            doublelinked->_head = doublelinked->_head->next;
            doublelinked->_head->prev = NULL;
            free(temp);
        }
    }
    doublelinked->_size--;
}

void pushBack(DLinkedList *doublelinked, int value)
{
    DListNode *newNode = createNode(value);
    if (newNode)
    {
        if (dlist_isEmpty(doublelinked))
        {
            doublelinked->_head = newNode;
            doublelinked->_tail = newNode;
            return;
        }

        else
        {
            doublelinked->_tail->next = newNode;
            newNode->prev = doublelinked->_tail;
            doublelinked->_tail = newNode;
        }
    }
    doublelinked->_size++;
}

void popBack(DLinkedList *doublelinked)
{
    DListNode *temp = doublelinked->_tail;
    if (doublelinked->_head == doublelinked->_tail)
    {
        doublelinked->_head = NULL;
        doublelinked->_tail = NULL;
        free(temp);
    }
    else
    {
        doublelinked->_tail = doublelinked->_tail->prev;
        doublelinked->_tail->next = NULL;
        free(temp);
    }
    doublelinked->_size--;
}

int dlist_front(DLinkedList *doublelinked)
{
    if (!dlist_isEmpty(doublelinked))
    {
        return (doublelinked->_head->data);
    }
    return 0;
}

void insertAt(DLinkedList *doublelinked, unsigned index, int value)
{
    if (index == 0)
    {
        pushFront(doublelinked, value);
        return;
    }
    else if (index >= doublelinked->_size)
    {
        pushBack(doublelinked, value);
        return;
    }
    DListNode *newNode = createNode(value);

    if (newNode)
    {
        if (dlist_isEmpty(doublelinked) == true)
        {
            pushBack(doublelinked, value);
            return;
        }
        else
        {
            DListNode *temp = doublelinked->_head;

            unsigned i = 0;
            while (i < index - 1 && temp->next != NULL)
            {
                temp = temp->next;
                i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next->prev = newNode; // pointer prev dari temp-> next diarahkan ke newNode
            temp->next = newNode;       // pointer next dari temp diarahkan ke newNode
            newNode->prev = temp;
        }
    }
    doublelinked->_size++;
}

int main()
{
    DLinkedList list;
    dlist_init(&list);

    pushFront(&list, 3); // add di depan
    pushFront(&list, 4); 
    pushFront(&list, 5); 
    pushFront(&list, 7);
    insertAt(&list, 1, 6); // add di tengah
    pushBack(&list, 2); // add di belakang

    DListNode *currNode = list._head;
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