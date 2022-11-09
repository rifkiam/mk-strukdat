#include <stdio.h>
#include <stdlib.h>

long long int factorial(long long int a) {
    if (a <= 1)
    {
        return a;
    }
    else
    {
        return a * factorial(a-1);
    }
}

int main() {
    long long int a, b;
    printf("Insert a number to get its factorial value\n");
    scanf("%lld", &a);
    printf("the result is: ");
    printf("%lld", factorial(a));
    return 0;
}