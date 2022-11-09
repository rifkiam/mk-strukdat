#include <stdio.h>

int main() {
    int a[100], n, pos, pindah, c;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
    scanf("%d", &a[i]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        pos = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[pos] > a[j])
            {
                pos = j;
            }
        }
        if(pos != i)
        {
            pindah = a[i];
            a[i] = a[pos];
            a[pos] = pindah;
            c++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n%d", c);
    return 0;
}