#include <stdio.h>

int a; //index for array arr
int b; //
int c;
int arr[100001];
int L, R;

/*int binser(int z) {
    int jawab;
    while (L <= R)
    {
        int mid = (L+R)/2;
        if (arr[mid] >= z)
        {
            jawab = mid;
            R = mid - 1;
            //printf("%d\n", R);
        }
        else if(arr[mid] < z)
        {
            L = mid + 1;
            //printf("%d\n", L);
        }
        //printf("%d %d", L, R);
    }

    if(arr[jawab] == c)
    {
        return jawab;
    }

    else
    {
        return -1;
    }

    /*if(arr[jawab] != c)
    {
        printf("-1\n");
    }
    else if(arr[jawab] == c)
    {
        printf("%d\n", jawab);
    }*/
    
}*/

/*int main() {
    
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &b);
    for(int i = 0; i < b; i++)
    {
        scanf("%d", &c);
        L = 0;
        R = a-1;
        printf("%d\n", binser(c));
    }
}*/