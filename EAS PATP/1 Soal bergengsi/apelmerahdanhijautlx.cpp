#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, A, B, tampung1 = 0, tampung2 = 0;
    int i = 0, j = 0;
    scanf("%d", &N, &A, &B);

    int C = A;
    int D = B;
    for (int h = 0; h < 2*N; h++)
    {
        if (C == D)
        {
            break;
        }
        else if (C < D)
        {
            C = C + C;
            i++;
            printf("A %d %d\n", C, i);
        }
        else if (C > D)
        {
            D = D + D;
            j++;
            printf("B %d %d\n", D, j);
        }
    }
    
    printf("%d %d", C, D);
    return 0;
}