#include <stdio.h>
#include <stdlib.h>

//TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE 
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) 
    {
        key = arr[i]; //menyimpan sementara nilai arrar index i ke variable 'key'
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE TEMPLATE 

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}