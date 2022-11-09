#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
    int pivot = array[high];
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

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


int main() {

    int N, T; // N = jumlah buku,  T = waktu luang mangarox
    int terbaca = 0;
    scanf("%d %d", &N, &T);

    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]); //A[] = waktu yang dibutuhkan untuk membaca buku tsb
    }
    
    quickSort(A, 0, N-1);

    for (int i = 0; i < N; i++)
    {
        if (T < A[i])
        {
            break;
        }
        T = T - A[i];
        terbaca++;
    }
    printf("%d", terbaca);
    return 0;
}