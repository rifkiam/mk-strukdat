#include <iostream>
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

void removeFirst(){
  del = head;
  head = head->next;
  delete del;
}

// Remove Last
void removeLast(){
  del = tail;
  cur = head;
  while( cur->next != tail )
  {
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;
}

// remove middle
void removeMiddle(int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() )
  {
    cout << "Posisi diluar jangkauan" << endl;
  }
  else if( posisi == 1)
  {
    cout << "Posisi bukan posisi tengah" << endl;
  }
  else
  {
    int index = 1;
    cur = head;
    while( index <= posisi )
    {
      if( index == posisi-1 )
      {
        before = cur;
      }
      if( index == posisi )
      {
        del = cur;
      }
      cur = cur->next;
      index++;
    }
    before->next = cur;
    delete del;
  }
}

void updateFirst(int number){
    head->num = number;
}

void updateLast(int number){
    tail->num = number;
}

void updateMiddle(int number, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() )
  {
    cout << "Posisi diluar jangkauan" << endl;
  }
  else if( posisi == 1)
  {
    cout << "Posisi bukan posisi tengah" << endl;
  }
  else
  {
    cur = head;
    int index = 1;
    while (index < posisi)
    {
        cur = cur->next;
        index++;
    }
    cur->num = number;
  }
}