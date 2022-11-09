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
numList *head, *tail, *cur, *before, *newNode, *del;

int countSingleLinkedList(){
    cur = head;
    int jumlah = 0;
    while( cur != NULL )
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void createSingleLinkedList(int number){
    head = new numList();
    head->num = number;
    head->next = NULL;
    tail = head;
}

void addFirst(int number){
  newNode = new numList();
  newNode->num = number;
  newNode->next = head;
  head = newNode;
}

void addLast(int number){
  newNode = new numList();
  newNode->num = number;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

int main() {
    int input[1000];
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        cin >> input[i];
        if (input[i] == 0)
        {
            break;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (input[i] != 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    cout << count;
    return 0;
}