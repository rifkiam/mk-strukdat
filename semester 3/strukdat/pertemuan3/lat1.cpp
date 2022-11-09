#include <iostream>
#include <string>
using namespace std;

struct Nama {
    string dataNama;
    string id;
    struct Nama *next;
};
Nama *head, *tail, *cur, *before, *newNode, *del;

// struct singleLinkedList {
//     unsigned _size;
//     Nama *_head;
// };

// void singleLinkedList_init(singleLinkedList *list) 
// {
//     list->_head = NULL;
//     list->_size = 0;
// }

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

void createSingleLinkedList(string nama, string id){
    head = new Nama();
    head->dataNama = nama;
    head->id = id;
    head->next = NULL;
    tail = head;
}

void addFirst(string nama, string id){
  newNode = new Nama();
  newNode->dataNama = nama;
  newNode->id = id;
  newNode->next = head;
  head = newNode;
}

void addLast(string nama, string id){
  newNode = new Nama();
  newNode->dataNama = nama;
  newNode->id = id;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void addMiddle(string nama, string id, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    newNode = new Nama();
    newNode->dataNama = nama;
    newNode->id = id;

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

void updateFirst(string nama, string id){
    head->dataNama = nama;
    head->id = id;
}

void updateLast(string nama, string id){
    tail->dataNama = nama;
    tail->id = id;
}

void updateMiddle(string nama, string id, int posisi){
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
    cur->dataNama = nama;
    cur->id = id;
  }
}

void printSingleLinkedList(){
    cur = head;
    while (cur != NULL)
    {
        cout << cur->dataNama << endl;
        cout << cur->id << endl;

        cur = cur->next;
    }
    cout << endl;
}


int main() {
    
    
    return 0;    
}