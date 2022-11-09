#include <stdio.h>

int array[100001];

int binser(int l, int r, int array[], int v) {
    int mid;
    int w = 0;
    while (l <= r)
    {
        mid = (l+r)/2;

        if(array[mid] >= v)
        {
            w = mid;
            r = mid - 1;
        }
        else if(array[mid] < v)
        {
            l = mid + 1;
        }
    }

    if(array[w] == v)
    {
        return w;
    }

    return -1;
}

int main(void) {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int q;
    scanf("%d", &q);
    int v;
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &v);
        printf("%d\n", binser(0, n-1, array, v));
    }

    return 0;
}