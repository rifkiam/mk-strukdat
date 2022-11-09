#include <stdio.h>
#include <math.h>

int main() {
    long int a, b;
    printf("Insert 2 numbers as dividee and divider (in order)\n");
    scanf("%d %d", &a, &b);
    float c = a;
    float d = b;
    printf("the result is: ");
    printf("%.6f", c / d);
    return 0;
}