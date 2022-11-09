#include <iostream>
#include <string>
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

void addMiddle(int number, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    newNode = new numList();
    newNode->num = number;

    // tranversing
    cur = head;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
  }
}

int printElement(){
    cout << cur->num << endl;
    return cur->num;
}

int multiply2() {
    cur->num = (cur->num)*2;
    return cur->num;
}

int reverseEach() {
  int remainder, reverse = 0;
  while (cur->num != 0) {
    remainder = cur->num % 10;
    reverse = reverse * 10 + remainder;
    cur->num/= 10;
  }
  cur->num = reverse;
  return cur->num;
}

int sumDigit() {
  int remainder, digit = 0;

  while (cur->num != 0)
  {
    remainder = cur->num % 10;
    cur->num = cur->num - remainder;
    cur->num = cur->num / 10;
    digit += remainder;
  }
  cur->num = digit;
  return cur->num;
}

void forEachElement(int (*func)()) {
    cur = head;
    while (cur != NULL)
    {
        func();
        cur = cur->next;
    }
}

int main() {
    // createSingleLinkedList(35);
    // addLast(36);
    // forEachElement(printElement);
    createSingleLinkedList(35);
    addLast(36);
    addLast(37);
    addLast(38);
    addLast(39);
    addLast(40);
    forEachElement(printElement);
    cout << "==========Multiply==========" << endl;
    forEachElement(multiply2);
    forEachElement(printElement);
    cout << "==========Reverse==========" << endl;
    forEachElement(reverseEach);
    forEachElement(printElement);
    cout << "==========Sum==========" <<endl;
    forEachElement(sumDigit);
    forEachElement(printElement);
}