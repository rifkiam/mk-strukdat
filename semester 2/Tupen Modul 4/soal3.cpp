#include <stdio.h>

void reverse(int a, int arr[]){

    int indexrmvr = 0;
    int temp;
    int i;

    for(i = a-1; i > a/2; i--)
    {
        temp = arr[i];
        arr[i] = arr[indexrmvr];
        arr[indexrmvr] = temp;
        indexrmvr++;

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

    for(i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}