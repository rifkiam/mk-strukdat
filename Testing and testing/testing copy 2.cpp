#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char nama[21];
    scanf("%s", &nama);

    int a = strlen(nama);
    
    int indexrmvr = 0;
    int temp;
    int i;

    for(i = a-1; i > a/2; i--)
    {
        temp = nama[i];
        nama[i] = nama[indexrmvr];
        nama[indexrmvr] = temp;
        indexrmvr++;
    }
    
    printf("%s", nama);

    /*reverse(a, nama, nama2);*/
    
    return 0;
}