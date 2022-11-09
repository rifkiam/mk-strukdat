#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[100];
    scanf("%s", &string);
    int temp = atoi(string);
    printf("%d", temp + 1);
    //string += 1;
    return 0;
}