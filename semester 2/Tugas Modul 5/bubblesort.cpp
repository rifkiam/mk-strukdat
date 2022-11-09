    #include <stdio.h>
    #include <stdlib.h>

    //TEMPLATE BUBBLE SORT TEMPLATE BUBBLE SORT TEMPLATE BUBBLE SORT TEMPLATE BUBBLE SORT
    void swap(int *xp, int *yp) {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    void bubbleSort(int arr[], int n) {
    int i, j, swapped;        // dioptimasi dengan bool `swapped`:
    for (i = 0; i < n-1; i++) 
    {
            swapped = 0;
            for (j = 0; j < n-i-1; j++) 
            {
                if (arr[j] > arr[j+1]) 
                {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
                }
            }
        if (swapped == 0)
            break;
        }
    }
    //TEMPLATE BUBBLE SORT TEMPLATE BUBBLE SORT TEMPLATE BUBBLE SORT TEMPLATE BUBBLE SORT

    int main() {

        int n;
        scanf("%d", &n);

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        bubbleSort(arr, n);

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        return 0;
    }