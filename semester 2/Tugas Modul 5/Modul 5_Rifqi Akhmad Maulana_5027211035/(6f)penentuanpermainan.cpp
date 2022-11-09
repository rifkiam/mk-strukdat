#include <stdio.h>

void quicksort(int number[], int first, int last){
    int i, j;
    int pivot, temp;
    
    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while(i < j)
        {
            while(number[i] <= number[pivot] && i < last)
            i++;
            while(number[j] > number[pivot])
            j--;
            if(i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j-1);
        quicksort(number, j+1, last);
    }
}

int main(){
    int n;
    
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    
    quicksort(a, 0, n-1);
    printf("%d", a[n-1]);
    return 0;
}