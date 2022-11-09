#include <stdio.h>

/*void check(int Q, int arr[], int q1[], int q2[]) {
    int result = 0;
    for(int i = 0; i < Q; i++)
    {
        for(int j = 0; j < Q; j++)
        {
            if(q1[i] <= arr[j] && arr[j] <= q2[i])
            {
                result += 1;
            }
        }
        printf("%d\n", result);
        result = 0;
    }
}*/



int main() {
    int N, Q;

    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &Q);
    int q1[Q], q2[Q];
    for(int i = 0; i < Q; i++)
    {
    scanf("%d %d", &q1[i], &q2[i]);
    }
    
    
    return 0;
}