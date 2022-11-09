#include <iostream>
using namespace std;

typedef struct Node
{
    string nama;
    int harga;
    struct Node *next;
} Node;

typedef struct queue
{
    Node *_top;
    unsigned _size;
} antrian_prioritas;

Node *smallest;

void pqueue_init(antrian_prioritas *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(antrian_prioritas *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(antrian_prioritas *pqueue, string nama, int hrg)
{
    Node *temp = pqueue->_top;
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->nama = nama;
    newNode->harga = hrg;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (hrg > pqueue->_top->harga) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && temp->next->harga > hrg)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Node *newNode = (Node *)malloc(sizeof(Node));
    // if (newNode)
    // {
    //     pqueue->_size++;
    //     newNode->nama = nama;
    //     newNode->harga = hrg;

    //     if (pqueue_isEmpty(pqueue))
    //     {
    //         newNode->next = NULL;
    //         pqueue->_top = newNode;
    //         smallest = newNode;
    //     }
    //     else
    //     {
    //         newNode->next = pqueue->_top;
    //         pqueue->_top = newNode;
    //         if (newNode->harga < smallest->harga)
    //         {
    //             smallest = newNode;
    //         }
    //     }
    //     pqueue->_top = newNode;
    // }
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
        return pqueue->_top->harga;
    else return 0;
}

void melayani(antrian_prioritas *pqueue, string method, int hrg) {
    if (method == "PULANG!")
    {
        cout << pqueue_top(pqueue) << endl;
        // while (curr != NULL)
        // {
        //     pqueue_pop(pqueue);
        // }
    }

    else if (method != "PULANG!")
    {
        int hrg;
        cin >> hrg;
        pqueue_push(pqueue, method, hrg);
    }
}

int main() {
    antrian_prioritas pqueue;
    pqueue_init(&pqueue);
    pqueue_push(&pqueue, "Testi", 11000);
    int q;
    cin >> q;

    // for (int i = 0; i < q; i++)
    while(q > 0)
    {
        string method;
        int harga;
        cin >> method;
        cin >> harga;
        melayani(&pqueue, method, harga);
        q--;
    }
    return 0;
}