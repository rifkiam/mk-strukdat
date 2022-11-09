#include <stdio.h>

int arr[100001];

int main() {
    int n, bil, q, b;

    for(int i = 0; i < 100001; i++)
    {
        arr[i] = -1;
    }

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &bil);
        if(arr[bil] == -1)
        {
            arr[bil] = i;
        }
    }

    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &b);
        printf("%d\n", arr[b]);
    }

}