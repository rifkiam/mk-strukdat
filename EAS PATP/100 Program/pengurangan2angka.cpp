#include <stdio.h>
#include <math.h>

int main() {
    long int a, b;
    printf("Insert 2 Numbers to subtract together\n");
    scanf("%ld %ld", &a, &b);
    printf("the result is: ");
    printf("%ld", a - b);
    return 0;
}