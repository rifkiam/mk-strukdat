#include <stdio.h>

int array[1][100001];
int arrayCopy[1][100001];
int i;
int j;
int q;
int n;

/*void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}*/

void arrswap(int (*a)[i], int (*b)[]) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high) {

    int pivot = array[0][high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++)
    {
        if (array[0][j] <= pivot)
        {
            i++;
            arrswap(&array[0][i], &array[0][j]);
        }
    }
    arrswap(&array[i+1], &array[high]);
    return (i+1);
}

void quickSort(int low, int high) {
    if (low < high)
    {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

/*int binserarray(int l, int r, int v) {
    i = 0;
    int mid;
    int w = 0;
    while (l <= r)
    {
        mid = (l+r)/2;

        if(arrayCopy[0][mid] >= v)
        {
            i = mid;
            r = mid - 1;
        }
        else if(arrayCopy[0][mid] < v)
        {
            l = mid + 1;
        }
    }

    if(arrayCopy[0][i] == v)
    {
        return arrayCopy[1][i];
    }

    return -1;
}*/

int binser(int l, int r, int v) {
    int mid;
    int w = 0;
    while (l <= r)
    {
        mid = (l+r)/2;

        if(array[0][mid] >= v)
        {
            w = mid;
            r = mid - 1;
        }
        else if(array[0][mid] < v)
        {
            l = mid + 1;
        }
    }

    if(array[0][w] == v)
    {
        return w;
    }

    return -1;
}

int main(void) {

    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[0][i]);
    }

    for (j = 0; j < n; j++)
    {
        array[1][j];
    }

    quickSort(0, n-1);

    int q;
    scanf("%d", &q);
    int v;
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &v);
        printf("%d ", binser(0, n-1, v));
    }

    return 0;
}
