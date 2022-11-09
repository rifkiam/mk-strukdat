#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 5;
    int temp;
    int a[n] = {6, 12, 73, 8, 1};

    //Bubble Sort
    for (int step = 0; step < n; step++) 
    {
    
        // check if swapping occurs  
        int swapped = 0;
        
        // loop to compare array elements
        for (int i = 0; i < n - step; i++) 
        {
        
            // compare two array elements
            // change > to < to sort in descending order
            if (a[i] > a[i + 1]) 
            {
                
                // swapping occurs if elements
                // are not in the intended order
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                
                swapped = 1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }

        // no swapping means the array is already sorted
        // so no need for further comparison
        if (swapped == 0) 
        {
        break;
        }
    
    }
    
    //Bubble Sort
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}