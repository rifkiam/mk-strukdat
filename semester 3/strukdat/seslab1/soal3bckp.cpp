#include <iostream>
#include <string>
using namespace std;

/*LINKED LIST*/

struct charList {
    char *word;
    struct charList *next;
};
charList *head, *tail, *cur, *before, *newNode, *del;

void createSingleLinkedList(char *newChar){
    head = new charList();
    head->word = newChar;
    head->next = NULL;
    tail = head;
}

void addFirst(char *newChar){
  newNode = new charList();
  newNode->word = newChar;
  newNode->next = head;
  head = newNode;
}

void addLast(char *newChar){
  newNode = new charList();
  newNode->word = newChar;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void printElement(){
    while (cur != NULL)
    {
        cout << cur->word << endl;
    }
}

int main() {

    createSingleLinkedList("Rifqi");
    addLast("Riki");
    addLast("Rafly");
    addLast("Rendy");
    printElement();
}