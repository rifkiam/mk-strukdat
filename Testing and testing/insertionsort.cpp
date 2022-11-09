#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) 
    {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than 'key' is found.
        while (key < array[j] && j >= 0) 
        {
            array[j + 1] = array[j];
            --j;
        }
        // Kalau udah nemu tempat yang cocok dalam urutan (menyisipkan)
        array[j + 1] = key;
    }
}

int main() {

    int n = 5;
    int i;
    int j = i + 1;
    int temp;
    int a[n] = {6, 12, 73, 8, 1};
    int size = sizeof(a)/sizeof(a[0]);

    insertionSort(a, size);
    /*Insertion Sort
    for (int j = 1; j < n; j++)
    {
        for (int i = j - 1; j <= 0; i--)
        {
            if (a[i] > a[j])
            {
                temp = a[i + 1];
                a[i + 1] = a[i];
            }

            else if (a[i] < a[j])
            {
                a[i] = a[j];
            }
        }
    }
    
    Insertion Sort*/

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}