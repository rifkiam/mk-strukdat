#include <stdio.h>

void reverse(int a, int *m){

    int indexrmvr = 0;
    int temp;
    int i;

    for(i = a-1; i > a/2; i--)
    {
        temp = *(m+1);
        *(m+1) = *(m+(indexrmvr-a-1));
        *(m+(indexrmvr-a-1)) = temp;
        indexrmvr++;
    }

    for(i = 0; i < a; i++)
    {
        printf("%d ", m[i]);
    }
}

int main() {

    int a;
    int i;
    scanf("%d", &a);
    int arr[a];
    
    for(i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }

    reverse(a, arr);

    return 0;
}