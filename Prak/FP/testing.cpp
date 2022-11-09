#include <stdio.h>
#include <stdlib.h>

struct siswa
{
    int x;
    int y;
    int z;
    char nama[20];
};

struct siswa urut;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(struct siswa urut[], int low, int high) {
  
    int pivot = urut[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) 
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(struct siswa urut[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", n);
    siswa urut[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &urut[i].x);
    }

    
    return 0;
}