#include <stdio.h>
#include <math.h>
#include <string.h>

int arr[10005];

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
    int N, X, index;
    scanf("%d %d", &N, &X);
    arr[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        abs(arr[i]);
    }
    arr[N] = X;
    
    quickSort(arr, 0, N);

    for (int i = 0; i <= N; i++)
    {
        if(arr[i] == X)
        {
            index = i;
            break;
        }
    }
    
    if(arr[index + 1] >= 10000 && arr[index - 1] >= 10000) //
    {
        if(abs(X - arr[index + 1]) == abs(X - arr[index - 1]))
        {
            printf("%d\n", arr[index - 1]);
            printf("%d\n", arr[index + 1]);
        }

        else if (abs(X - arr[index + 1]) >= abs(X - arr[index - 1]))
        {
            printf("%d\n", arr[index - 1]);
        }

        else if (abs(X - arr[index + 1]) <= abs(X - arr[index - 1]))
        {
            printf("%d\n", arr[index + 1]);
        }
    }

    else if(arr[index + 1] >= 1000 && arr[index - 1] >= 1000)
    {
        if(abs(X - arr[index + 1]) == abs(X - arr[index - 1]))
        {
            printf("0%d\n", arr[index - 1]);
            printf("0%d\n", arr[index + 1]);
        }

        else if (abs(X - arr[index + 1]) >= abs(X - arr[index - 1]))
        {
            printf("0%d\n", arr[index - 1]);
        }

        else if (abs(X - arr[index + 1]) <= abs(X - arr[index - 1]))
        {
            printf("0%d\n", arr[index + 1]);
        }
    }

    else if(arr[index + 1] > 100 && arr[index - 1] > 100)
    {
        if(abs(X - arr[index + 1]) == abs(X - arr[index - 1]))
        {
            printf("00%d\n", arr[index - 1]);
            printf("00%d\n", arr[index + 1]);
        }

        else if (abs(X - arr[index + 1]) >= abs(X - arr[index - 1]))
        {
            printf("00%d\n", arr[index - 1]);
        }

        else if (abs(X - arr[index + 1]) <= abs(X - arr[index - 1]))
        {
            printf("00%d\n", arr[index + 1]);
        }
    }

    else if(arr[index + 1] > 10 && arr[index - 1] > 10)
    {
        if(abs(X - arr[index + 1]) == abs(X - arr[index - 1]))
        {
            printf("000%d\n", arr[index - 1]);
            printf("000%d\n", arr[index + 1]);
        }

        else if (abs(X - arr[index + 1]) >= abs(X - arr[index - 1]))
        {
            printf("000%d\n", arr[index - 1]);
        }

        else if (abs(X - arr[index + 1]) <= abs(X - arr[index - 1]))
        {
            printf("000%d\n", arr[index + 1]);
        }
    }
    
    return 0;
}