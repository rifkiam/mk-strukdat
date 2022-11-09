#include <iostream>
using namespace std;

typedef struct Node
{
    int id;
    int urgency;
    struct Node *next;
} pasien;

typedef struct queue
{
    pasien *_top;
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

void pqueue_push(antrian_prioritas *pqueue, int id, int urg)
{
    pasien *temp = pqueue->_top;
    pasien *newNode = (pasien*) malloc (sizeof(pasien));
    newNode->urgency = urg;
    newNode->id = id;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (urg > pqueue->_top->urgency) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && temp->next->urgency > urg)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(antrian_prioritas *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        pasien *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(antrian_prioritas *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->urgency;
    else return 0;
}

void melayani(antrian_prioritas *pqueue, string method) {
    if (method == "MASUK")
    {
        int id, urg;
        cin >> id;
        cin >> urg;
        pqueue_push(pqueue, id, urg);
    }

    else if (method == "LAYANI")
    {
        if (pqueue_isEmpty(pqueue))
        {
            cout << "HORE" << endl;
        }
        else
        {
            cout << pqueue->_top->id << endl;
            pqueue_pop(pqueue);
        }
    }
}

int main() {
    antrian_prioritas pqueue;
    pqueue_init(&pqueue);

    int q;
    cin >> q;

    Node *current = pqueue._top;
    for (q; q > 0; q--)
    {
        string method;
        cin >> method;
        melayani(&pqueue, method);
        // cout << method << " " << id << " " << urg << endl;
    }
    return 0;
}