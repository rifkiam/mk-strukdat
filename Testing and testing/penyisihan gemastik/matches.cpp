#include <stdio.h>

int matchesNeededPerDigit[10] = {2, 3, 4, 5, 5, 5, 6, 6, 6, 7};
int matches;
int remaining;
int indexAdder = 0;
int count = 0;

void matchCount() {
    int i = 0;
    int j = 0;
    int iteration = 0;

    while (iteration != 2)
    {
        remaining = matches;
        while (remaining >= 0)
        {
            remaining -= matchesNeededPerDigit[i];
            i++;
        }
        iteration++;
    }
    while (iteration != 3)
    {
        remaining = matches;
        while (remaining >= 0)
        {
            remaining -= matchesNeededPerDigit[i];
            i++;
        }
        iteration++;
    }
    
}

int main() { //
    int matches;
    int indexAdder = 0;
    int count = 0;
    int i = 0;
    int j = 0;

    while (matches = scanf("%d", &matches) != EOF)
    {
        // for (i += indexAdder; i < 10; i++)
        // {
        //     while (matches % matchesNeededPerDigit[j] >= 0)
        //     {   
        //         while (matches % matchesNeededPerDigit[j]*2 >= 0)
        //         {
        //             count++;
        //         }
        //         while (matches % matchesNeededPerDigit[j]*3 >= 0)
        //         {
        //             count++;
        //         }
                
        //         count++;
        //         j++;
        //     }
        //     indexAdder++;
        // }
        
    }
    
    return 0;
}