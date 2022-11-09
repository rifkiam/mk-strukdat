#include <iostream>

using namespace std;

struct Dat{
    int num;

   Dat *next;
};

Dat *head, *tail, *cur, *baru;

void Linklist(int num){
    head = new Dat();
    head->num = num;
    head->next = NULL;
    tail = head;
}

void pushFront(int num){
    baru = new Dat();
    baru->num = num;
    baru->next = head;
    head = baru;
}

void pushBack(int num){
    baru = new Dat();
    baru->num = num;
    baru->next = NULL;
    tail->next = baru;
    tail = baru;
}

int printElement(){
    cout << cur->num << endl;
    return cur->num;
  }

int multiply2() {
    cur->num = (cur->num)*2;
    return cur->num;
}

void forEach(int (*p)()) {
  cur = head;
  while (cur != NULL)
  {
    p();
    cur = cur->next;
  }
}

int main() {
  Linklist(62);
  pushBack(72);
  pushBack(12);
  forEach(printElement);
    return 0;
}