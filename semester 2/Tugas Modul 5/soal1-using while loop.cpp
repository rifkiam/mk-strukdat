#include <stdio.h>

int main() {

    int i = 0;
    int j = 0;
    int match, value;

    int n;
    scanf("%d", &n);

    int arrN[n];

    while (i < n)
    {
        scanf("%d", &arrN[i]);
        i++;
    }

    int m;
    scanf("%d", &m);
    int arrQ[m];
    int ans[m];

    while(j < m)
    {
        scanf("%d", &arrQ[j]);
        j++;
    }

    for(j = 0; j < m; j++)
    {
        match = 0;
        for(i = 0; i < n; i++)
        {
            /*if(value == arrN[i])
            {
                ans[j] = i;
            }*/

            if(arrQ[j] == arrN[i])
            {
                match = 1;
                ans[j] = i;
                break;
            }

            /*while(i < n)
            {
                if (arrN[i] == value)
                {
                    continue;
                }
            }*/
        }
        if(match == 0)
        {
            ans[j] = -1;
        }
        printf("%d\n", ans[j]);
    }

    return 0;
}