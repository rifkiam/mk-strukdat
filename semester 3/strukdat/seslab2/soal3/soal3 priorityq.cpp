#include <iostream>
using namespace std;

typedef struct Node
{
    string data;
    int urgency;
    struct Node *next;
};

typedef struct queue
{
    Node *_top;
    unsigned _size;
} antrian_prioritas;

void pqueue_init(antrian_prioritas *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(antrian_prioritas *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(antrian_prioritas *pqueue, string value) {
    Node *temp = pqueue->_top;
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value.compare(pqueue->_top->data) < 0) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    } else {
        while ( temp->next != NULL && (temp->next->data).compare(value) < 0) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(antrian_prioritas *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        Node *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(antrian_prioritas *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->urgency;
    else return 0;
}

int main() {
    antrian_prioritas pqueue;
    pqueue_init(&pqueue);

    pqueue_push(&pqueue, "Rifqi");
    pqueue_push(&pqueue, "Reynold");
    pqueue_push(&pqueue, "Ahnaf");
    pqueue_push(&pqueue, "Wahyu");
    pqueue_push(&pqueue, "Nas");
    
    Node *curr = pqueue._top;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
    
    return 0;
}