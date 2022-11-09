#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 5;
    int temp;
    int a[n] = {6, 12, 73, 8, 1};

    //Selection Sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] >= a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }
    //Selection Sort
    
    return 0;
}