#include <stdio.h>
#include <math.h>

int main() {
    long int a, b;
    printf("Insert 2 Numbers as 'base' and 'power'\n");
    scanf("%ld %ld", &a, &b);
    int c = pow(a, b);
    printf("the result is: ");
    printf("%ld", c);
    return 0;
}