#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef __int64 LL;

Double dp[12][12];
int n, K;
String str;

int solve (char ch)
{
    int l = 0, r = 0, ans = 0, cnt = 0;
    while (R < n && L < N)
    {while

        ((str[r] = = CH | | cnt < k) && R < N)//Find the location of the right endpoint 
  {
            if (str[r]! = ch) cnt++;
            r++;
        }
        ans = max (ans, r-l);
        while (l<=r && str[l] == ch) The left end of the l++;//substring is shifted to the right
        l++;
        cnt--;
    }
    return ans;
}

int main ()
{
    while (scanf ("%d%d", &n, &k)! = EOF)
    {
        cin>>str;
        printf ("%d\n", Max (Solve (' a '), Solve (' B ')));
    }
    return 0;
}