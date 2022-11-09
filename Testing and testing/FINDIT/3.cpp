#include <stdio.h>
#include <string.h>

char buah[500][20];

void solve(int M) {
    int i;
    int jalan = 0;
    int newlastknown, lastknown = 9999;

    for (i = 0; i < M; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            if (buah[i][20] == buah[j][20])
            {
                newlastknown = j;
                if (j == M - 1)
                {
                    jalan += 1;
                }
                else if (j < M - 1)
                {
                    if (newlastknown == i + 1)
                    {
                        i = j + 1;
                    }

                    if (newlastknown > lastknown)
                    {
                        
                    }
                    
                    jalan += 1;
                }

                lastknown = newlastknown;
            }
        }
        if (newlastknown < M - 1 && newlastknown > lastknown)
        {
            printf("Rencana#%d=-1\n", i + 1);
            break;
        }
        jalan += 1;
    }
    printf("Rencana#%d=%d\n", i + 1, jalan);
}

int main() {
    int X, N;
    scanf("%d", &X);

    for (int i = 0; i < X; i++)
    {
        scanf("%d", &N);
        int M = 2*N;
        buah[M][20];

        for (int j = 0; j < M; j++)
        {
            scanf("%s", &buah[j][20]);
        }
        solve(M);
    }
    
    return 0;
}