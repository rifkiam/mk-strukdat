#include <stdio.h>
#include <math.h>

int main() {
    long int a, b;
    printf("Insert 2 in the order of: The number that will be operated ; the modulo\n");
    scanf("%ld %ld", &a, &b);
    printf("the remainder is: ");
    printf("%ld", a % b);
    return 0;
}