#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char string[50];

struct  palin
{
    char numpalin[50];
};

struct palin arr[100000];

long long int check(int i, long long int num) {
    int a, b, c;
    //float c = a, d = b, e;
    //printf("%d\n", num);
    sprintf(arr[i].numpalin, "%d", num);
    for (a = 0, b = strlen(arr[i].numpalin) - 1; a <= b; a++, b--)
    {
        /*e = ceil((c + d)/2);
        int f = e;
        if (arr[i].numpalin[f] == '0')
        {
            arr[i].numpalin[f] = '1';
        }*/
        
        if (arr[i].numpalin[a] == '0')
        {
            arr[i].numpalin[a] = '1';
        }
        
        if (arr[i].numpalin[a] == arr[i].numpalin[b])
        {
            continue;
        }

        else 
        {
            long long int temp = atoi(arr[i].numpalin);
            //printf("%d %d\n", a, b);
            return check(i, temp + 1);
        }
    }

    sprintf(string, "%d", num);
    if (string[strlen(string)/2] == '0')
    {
        string[strlen(string)/2] = '1';
    }
    num = atoi(string);
    return num;
}

int main() {
    
    long long int palin[100000];
    long long int printpalin[100000];
    long int t;
    scanf("%ld", &t);
    palin[t];

    for (int i = 0; i < t; i++)
    {
        scanf("%lld", &palin[i]);
        palin[i] += 1;
        //printf("%lld\n", check(i, palin[i]));
        printpalin[i] = check(i, palin[i]);
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d\n", printpalin[i]);
    }
    
    return 0;
}