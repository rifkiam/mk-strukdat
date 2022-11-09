#include <iostream>
#include <cstring>
using namespace std;

struct String {
    char data[100];
    struct String *next;
};

void str_push(struct String** head, char *s) {
	String *newNode = (struct String*) malloc(sizeof(struct String));

	strcpy(newNode->data, s);
	newNode->next = (*head);
	(*head) = newNode;
}

void str_append(struct String** head, char *s) {
    struct String* newNode = (struct String *) malloc(sizeof(struct String));
    struct String* last = *head;

    strcpy(newNode->data, s);
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    while(last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    return;
}

void printElement(struct String** str) {
    printf("%s\n", (*str)->data);
    return;
}

void forEachElement(struct String **str, void (*func)(struct String **)) {
    struct String *tmp = NULL;

    while(*str != NULL) {
        (*func)( (str) );
        str_append(&tmp, (*str)->data);
        *str = (*str)->next;
    }

    *str = tmp;
    return;
}

int main() {
    struct String* str = NULL;
    
    str_append(&str, "Apple");
    str_append(&str, "Orange");
    str_push(&str, "Watermelon");


    forEachElement(&str, printElement);

    return 0;
}