#include <stdio.h>
#include <math.h>
#include <string.h>

int price[100005];

/*int profit(int arr[], int N) {
    int i, j, selisih1, selisih2, max, totalprofit;
    for (i = 0; i < N; i++)
    {
        for (j = i + 2; j < N; j++)
        {
            selisih1 = arr[i] - arr[j + 2];
            selisih2 = arr[i] - arr[j + 1];
            if (selisih1 > selisih2)
            {
                max = selisih1;
            }

            else if (selisih1 < selisih2)
            {
                max = selisih2;
            }           
        }
        totalprofit += max; 
    }
    return totalprofit;
}*/

int main() {
    int N, selisih, profit = 0, max = 0;
    int i = 0;
    scanf("%d", &N);
    price[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &price[i]);
    }

    for (int i; i < N; i++)
    {
        int j = i + 1;
        for (j; i < N; i++)
        {
            selisih = price[i] - price[j];
            printf("%d", selisih);

            profit = profit + max;
            if (max > selisih)
            {
                break;
            }
            else if (max < selisih)
            {
                max = selisih;
            }
            
        }
        i = j;
    }

    printf("%d", profit);
    return 0;
}