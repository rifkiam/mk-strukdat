#include <stdio.h>

int main() {

    int i = 0;
    int j = 0;
    int match, value;

    int n;
    scanf("%d", &n);

    int arrN[n];

    for(i; i < n; i++)
    {
        scanf("%d", &arrN[i]);
    }

    int m;
    scanf("%d", &m);
    int arrQ[m];
    int ans[m];

    for(j; j < m; j++)
    {
        scanf("%d", &arrQ[j]);
    }

    for(j = 0; j < m; j++)
    {
        match = 0;
        for(i = 0; i < n; i++)
        {
            if(arrQ[j] == arrN[i])
            {
                match = 1;
                ans[j] = i;
                break;
            }
        }
        if(match == 0)
        {
            ans[j] = -1;
        }
        printf("%d\n", ans[j]);
    }

    return 0;
}