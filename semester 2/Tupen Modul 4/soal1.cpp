#include <stdio.h>

int tambah (int a, int b, int* c) {
    *c = a + b;
    return *c;
}

int main() {
    int a = 1, b = 2;
    int c;
    printf("%d", tambah(a, b, &c));
    return 0;
}