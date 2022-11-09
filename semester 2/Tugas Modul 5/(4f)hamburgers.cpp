#include <string.h>
#include <math.h>
#include <stdio.h>

int B = 0, S = 0, C = 0;
int Nb = 0, Ns = 0, Nc = 0;
int Pb = 0, Ps = 0, Pc = 0;
long long int money = 0;
int solve(long long int hamburger);

long long int binSearch(long long int start, long long int end){
    long long int mid = (end + start)/2;

    if (end-start == 1)
    {
        if (solve(end))
        {
            return end;
        } 

        else 
        {
            return start;
        }
    }

    if (solve(mid))
    {
        return binSearch(mid, end);
    } 

    else 
    {
        return binSearch(start, mid);
    }

}

int solve(long long int hamburger){

    long long int needB = 0,needS = 0,needC = 0;
    if(B > 0) needB = B*hamburger - Nb;
    if(S > 0) needS = S*hamburger - Ns;
    if(C > 0) needC = C*hamburger - Nc;

    long long int uangB = 0, uangS = 0, uangC = 0;

    if(needB >= 0) uangB = needB * Pb;
    if(needS >= 0) uangS = needS * Ps;  
    if(needC >= 0) uangC = needC * Pc;

    if ((uangB + uangS + uangC) <= money)
    {
        return 1;
    } else{
        return 0;
    }    
}

int main(){
 
    char arr[100];
    gets(arr);
    int len = strlen(arr);
    for (int i = 0; i < len ; i++)
    {
        switch (arr[i])
        {
        case 'B':
            B++;
            break;
        case 'S':
            S++;
            break;
        case 'C':
            C++;
            break;
        default:
            break;
        }
    }
  
    scanf("%d %d %d", &Nb, &Ns, &Nc);

    scanf("%d %d %d", &Pb, &Ps, &Pc);
    
    scanf("%lli", &money);

    long long int result = binSearch(0, 10000000000000);
    printf("%lli", result);

}