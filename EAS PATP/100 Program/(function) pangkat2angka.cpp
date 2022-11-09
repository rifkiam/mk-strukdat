#include <stdio.h>
#include <stdlib.h>

int pow(long int a, long int b) {
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

int main() {
    long int a, b;
    printf("Insert 2 Numbers as 'base' and 'power'\n");
    scanf("%ld %ld", &a, &b);
    printf("the result is: ");
    printf("%ld", pow(a, b));
    return 0;
}